package pl.polsl.calculationpiweb.servlet;

import pl.polsl.calculationpiweb.data.CalculationResults;
import pl.polsl.calculationpiweb.data.Result;
import pl.polsl.calculationpiweb.data.Counter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import javax.servlet.ServletConfig;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import pl.polsl.calculationpiweb.database.DatabaseConnectionException;
import pl.polsl.calculationpiweb.database.DatabaseController;
import pl.polsl.calculationpiweb.database.DatabaseSQLException;

/**
 * Servlet class that displays the results of calculations
 *
 * @author BW
 * @version 2.0
 */
public class CalculationHistory extends HttpServlet {

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

        ServletConfig config = getServletConfig();

        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet CalculationHistory</title>");
            out.println("<link rel=\"shortcut icon\" href=\"images/pi.ico\"/>");
            out.println("<link rel=\"stylesheet\" type=\"text/css\" href=\"styles/ServletStyle.css\">");
            out.println("</head>");
            out.println("<body>");

            // Main block //
            out.println("<div class=\"MainBlock\">");
            CalculationResults results;
            
                    // Database service //
            try {
                DatabaseController dbController = new DatabaseController(config);
                if (!dbController.isTablesCreated()) {
                    dbController.createTables();
                }
                results = dbController.selectData();
                dbController.closeDataConnection();
            } catch (DatabaseConnectionException e) {
                response.sendError(HttpServletResponse.SC_BAD_REQUEST, "Can not connect to database");
                return;
            } catch (DatabaseSQLException e) {
                response.sendError(HttpServletResponse.SC_BAD_REQUEST, "Internal query error for the database");
                return;
            }

            ArrayList<Result> res = null;
            try {
                res = results.getResult();
            } catch (NullPointerException e) {
            }
            if (res != null) {
                for (Result i : res) {
                    out.println("<p> Number of points: " + i.getNumberOfPoints() + ", result: " + i.getResultValue());
                }
            } else {
                out.println("No results were found for this session.");
            }

            out.println("<form action=\"" + request.getContextPath() + "\">");
            out.println("<input type=\"submit\" value=\"Back\"/>");
            out.println("</form>");
            out.println("</div>");

            // Footer //
            out.println("<footer>");

            Cookie[] cookies = request.getCookies();
            for (Cookie cookie : cookies) {
                if (cookie.getName().equals("bestResult")) {
                    out.println("<p>Calculated the nearest to reality value Pi: " + cookie.getValue() + "</p>");
                }
            }

            out.println("<p>Number of calculations performed on the server (generally): " + contextCounterService(request, response) + "</p>");

            out.println("</footer>");

            out.println("</body>");
            out.println("</html>");
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
     * Method obtaining the counter's status from the context
     *
     * @param request servlet request
     * @param response servlet response
     * @return a String containing number of counted events
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    private String contextCounterService(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        ServletContext context = this.getServletContext();
        Counter counter = null;
        try {
            counter = (Counter) context.getAttribute("Counter");
        } catch (ClassCastException e) {
        }
        if (counter == null) {
            return "0";
        } else {
            return Integer.toString(counter.getNumberOfCounted());
        }

    }
}
