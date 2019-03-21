package pl.polsl.calculationpiserver;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import pl.polsl.calculationpiserver.model.InvalidArgumentException;
import pl.polsl.calculationpiserver.model.Model;

/**
 * Class that represents a single client connection to the server
 * 
 * @author BW
 * @version 1.0
 */
public class SingleService {

    /**
     * Represent the connection between a client program and a server program.
     */
    private Socket socket;
    /**
     * Input stream from client application
     */
    private BufferedReader input;
    /**
     * Output stream to client application
     */
    private PrintWriter output;

    /**
     * Default constructor that sets the input and output streams 
     * to communicate with the client application
     * 
     * @param socket socket representation through which the client establishes a connection with the server.
     * @throws IOException when when the stream was interrupted
     */
    public SingleService(Socket socket) throws IOException {
        this.socket = socket;
        output = new PrintWriter(
                new BufferedWriter(
                        new OutputStreamWriter(
                                socket.getOutputStream())), true);
        input = new BufferedReader(
                new InputStreamReader(
                        socket.getInputStream()));
    }

    /**
     * Method implementing the service depending on its type.
     * 
     * @param model currently used model to calculate value of Pi
     */
    public void realize(Model model) {

        String initMessage = "";
        try {
            initMessage = input.readLine();
        } catch (IOException e) {
            System.err.println(e.getMessage());
        }
        if (initMessage.toUpperCase().equals("MANUAL")) {
            manualRealize(model);
        } else {
            cmdRealize(model);
        }

        System.out.println("closing...");
    }

    /**
     * Protocol support using arguments from the command line.
     * 
     * @param model currently used model to calculate value of Pi
     */
    private void cmdRealize(Model model) {
        Boolean done = false;
        try {
            while (!done) {
                String userRequest;
                userRequest = input.readLine();
                if (userRequest.toUpperCase().equals("-HELP")) {
                    helpService();
                } else {
                    if (userRequest.toUpperCase().equals("QUIT")) {
                        quitService();
                        done = true;
                    } else {
                        String[] splitedRequest = userRequest.split("\\s+");
                        if (splitedRequest[0].toUpperCase().equals("-CALC") && splitedRequest.length == 2) {
                            output.println("Calc command");
                            try {
                                double calculationResult = model.calculatePi(Integer.parseInt(splitedRequest[1]));
                                output.println("PARSE 0");
                                output.println("Server: Result = " + calculationResult);
                            } catch (NumberFormatException e) {
                                output.println("PARSE 1");
                                System.err.println("Parse exception");
                            } catch (InvalidArgumentException e) {
                                System.err.println(e.getMessage());
                            }
                        } else {
                            output.println("Unknown command");
                        }
                    }
                }
            }
        } catch (IOException e) {
            System.err.println(e.getMessage());
        } finally {
            try {
                socket.close();
            } catch (IOException e) {
                System.err.println(e.getMessage());
            }

        }
    }

    /**
     * Protocol supporting using data entry by the client application
     * 
     * @param model currently used model to calculate value of Pi
     */
    private void manualRealize(Model model) {
        Boolean done = false;
        try {
            while (!done) {
                output.println("Server: Hello, what do you want to do?");
                String userRequest;
                userRequest = input.readLine();
                if (userRequest.toUpperCase().equals("-HELP")) {
                    helpService();
                } else {
                    if (userRequest.toUpperCase().equals("QUIT")) {
                        quitService();
                        done = true;
                    } else {
                        String[] splitedRequest = userRequest.split("\\s+");
                        if (splitedRequest[0].toUpperCase().equals("-CALC") && splitedRequest.length == 2) {
                            try {
                                calculateService(Integer.parseInt(splitedRequest[1]), model);
                            } catch (NumberFormatException e) {
                                output.println("PARSE 1");
                                System.err.println("Parse exception");
                            } catch (InvalidArgumentException e) {
                                System.err.println(e.getMessage());
                            }
                        } else {
                            output.println("Unknown command");
                        }
                    }
                }
            }
        } catch (IOException e) {
            System.err.println(e.getMessage());
        } finally {
            try {
                socket.close();
            } catch (IOException e) {
                System.err.println(e.getMessage());
            }

        }

    }

    /**
     * Support for the "-calc" command
     * 
     * @param pointsCountToCalculate number of points used to calculate the Pi value
     * @param model currently used model to calculate value of Pi
     * @throws InvalidArgumentException when the number of points transferred 
     * to the calculation is less than "1"
     */
    private void calculateService(int pointsCountToCalculate, Model model) throws InvalidArgumentException {
        output.println("Calc command");
        if (pointsCountToCalculate <= 0) {
            output.println("PARSE 1"); // Unsuccessful parse code
            throw new InvalidArgumentException("The number of points should be greater than '0'!");
        } else {
            output.println("PARSE 0"); // Successful parse code
        }
        output.println("Server: Calculate the pi value for " + pointsCountToCalculate + " points? Y/N");
        try {
            String clientRequest = input.readLine();

            if (clientRequest.toUpperCase().equals("Y")) {
                try {
                    output.println("Server: Result = " + model.calculatePi(pointsCountToCalculate));
                } catch (InvalidArgumentException e) {
                    System.err.println(e.getMessage());
                }
            } else {
                output.println("Server: Calculations canceled");
            }
        } catch (IOException e) {
        }
    }

    /**
     * Support for the "-help" command
     */
    private void helpService() {
        output.println("Help command");
        output.println("-calc <number> \t Calculates the value of pi based on <number> points; quit \t Exit from program ");
    }

    /**
     * Support for the "quit" command
     */
    private void quitService() {
        output.println("Quit command");
        output.println("End session");
    }
}