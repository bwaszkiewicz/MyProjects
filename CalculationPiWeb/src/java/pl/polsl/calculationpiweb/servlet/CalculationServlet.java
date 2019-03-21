package pl.polsl.calculationpiweb.servlet;

import pl.polsl.calculationpiweb.data.Counter;
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletConfig;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import pl.polsl.calculationpiweb.database.DatabaseConnectionException;
import pl.polsl.calculationpiweb.database.DatabaseController;
import pl.polsl.calculationpiweb.database.DatabaseSQLException;
import pl.polsl.calculationpiweb.model.*;

/**
 * Servlet class responsible for picking arguments and performing calculations
 *
 * @author BW
 * @version 2.0
 */
public class CalculationServlet extends HttpServlet {

    /**
     * Currently used model to calculate value of Pi
     */
    Model model;

    /**
     * The initiating method that creates the model object
     */
    @Override
    public void init() {
        model = new MonteCarloMethods();
    }

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");

        int numberOfPoints = 0;
        double calculatedResultDouble = 0;
        String calculatedResult = "";
        if (request.getParameter("numberOfPoints") == null) {
            response.sendError(HttpServletResponse.SC_BAD_REQUEST, "Argument was not detected");
        } else if (request.getParameter("numberOfPoints").length() > 6) {
            response.sendError(HttpServletResponse.SC_BAD_REQUEST, "Too many points to generate");
        } else {
            try {
                numberOfPoints = Integer.parseInt(request.getParameter("numberOfPoints"));
            } catch (NumberFormatException e) {
                response.sendError(HttpServletResponse.SC_BAD_REQUEST, "You should give number of points greater than 0!");
                return;
            }

            ServletConfig config = getServletConfig();

            try (PrintWriter out = response.getWriter()) {
                /* TODO output your page here. You may use following sample code. */
                out.println("<!DOCTYPE html>");
                out.println("<html>");
                out.println("<head>");
                out.println("<title>Servlet calculation</title>");
                out.println("<link rel=\"shortcut icon\" href=\"images/pi.ico\"/>");
                out.println("<link rel=\"stylesheet\" type=\"text/css\" href=\"styles/ServletStyle.css\">");
                out.println("</head>");
                out.println("<body>");
                out.println("<div class=\"MainBlock\">");
                out.println("Calculated value of Pi number: ");

                try {
                    calculatedResultDouble = model.calculatePi(numberOfPoints);
                    calculatedResult = Double.toString(calculatedResultDouble);
                    out.println(calculatedResult);
                } catch (InvalidArgumentException e) {
                    response.sendError(HttpServletResponse.SC_BAD_REQUEST, "Can not calculate the result");
                } catch (NumberFormatException e) {
                    response.sendError(HttpServletResponse.SC_BAD_REQUEST, "Can not calculate the result");
                }

                cookieBestResultService(request, response, calculatedResult);
                contextCounterService(request, response);

                out.println("<form action=\"" + request.getContextPath() + "\">");
                out.println("<input type=\"submit\" value=\"Back\"/>");
                out.println("</form>");
                out.println("</div>");
                out.println("</body>");
                out.println("</html>");
                
                        // Database service //
                try {
                    DatabaseController dbController = new DatabaseController(config);
                    if (!dbController.isTablesCreated()) {
                        dbController.createTables();
                    }
                    dbController.insertData(numberOfPoints, calculatedResultDouble);
                    dbController.closeDataConnection();
                } catch (DatabaseConnectionException e) {
                    response.sendError(HttpServletResponse.SC_BAD_REQUEST, "Can not connect to database");
                    return;
                } catch (DatabaseSQLException e) {
                    response.sendError(HttpServletResponse.SC_BAD_REQUEST, "Internal query error for the database");
                    return;
                }
            }
        }
    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        HttpSession session = request.getSession(true);
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        HttpSession session = request.getSession(true);
        processRequest(request, response);
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

    /**
     * Method that records the result closest to the actual Pi number in cookies
     *
     * @param request servlet request
     * @param response servlet response
     * @param calculatedResult value of the result (calculated value of the
     * number Pi)
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    private void cookieBestResultService(HttpServletRequest request, HttpServletResponse response, String calculatedResult)
            throws ServletException, IOException {
        Cookie[] cookies = request.getCookies();
        if (cookies != null) {
            for (Cookie cookie : cookies) {
                if (cookie.getName().equals("bestResult")) {
                    try {
                        if (Math.abs(Math.PI - Double.parseDouble(calculatedResult)) < Math.abs(Math.PI - Double.parseDouble(cookie.getValue()))) {
                            Cookie newCookie = new Cookie("bestResult", calculatedResult);
                            response.addCookie(newCookie);
                        }
                    } catch (NumberFormatException e) {
                        response.sendError(response.SC_BAD_REQUEST, "Unknown parsing problem");
                    }
                }
            }
        } else {
            Cookie cookie = new Cookie("bestResult", calculatedResult);
            response.addCookie(cookie);
        }
    }

    /**
     * Method that supports the event counter when a new calculation is
     * performed
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    private void contextCounterService(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        ServletContext context = this.getServletContext();
        Counter counter = null;
        try {
            counter = (Counter) context.getAttribute("Counter");
        } catch (ClassCastException e) {
        }
        if (counter == null) {
            counter = new Counter();
        }
        counter.hitCounter();
        context.setAttribute("Counter", counter);
    }
}
