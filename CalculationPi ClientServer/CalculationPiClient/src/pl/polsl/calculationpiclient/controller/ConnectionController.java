package pl.polsl.calculationpiclient.controller;

import pl.polsl.calculationpiclient.view.ClientView;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.util.Arrays;
import java.util.Properties;
import java.util.Scanner;

/**
 * Class responsible for controlling the connection
 * 
 * @author BW
 * @version 1.0
 */
public class ConnectionController {

    /**
     * Reading data from the keyboard
     */
    private Scanner scanner = new Scanner(System.in);
    /**
     * Represent the connection between a client program and a server program.
     */
    private Socket socket;

    /**
     * Default constructor that loads the server port settings from the .properties file
     * 
     * @throws IOException when error occurred while reading from a file
     * @throws pl.polsl.calculationpiclient.controller.InvalidPortFormatException when
     * wrong port format
     */
    public ConnectionController() throws IOException, InvalidPortFormatException {
        Properties defaultProperties = new Properties();
        try (FileInputStream in = new FileInputStream(".properties")) {
            defaultProperties.load(in);
        } catch (IOException e) {
        }
        try{
        this.socket = new Socket("localhost", Integer.parseInt(defaultProperties.getProperty("port")));
        } catch(NumberFormatException e) {
            throw new InvalidPortFormatException("Incorrect port value in the .properties file");
        }
    }

    /**
     * Method implementing the client communication protocol with the server
     * 
     * @throws IOException when the stream was interrupted
     */
    public void manualService() throws IOException {
        Scanner serverAnswer = new Scanner(socket.getInputStream());  // create scanner for message from server
        PrintStream requestToServer = new PrintStream(socket.getOutputStream());
        String dataToServer;
        ClientView view = new ClientView();
        Boolean done = false;
        requestToServer.println("MANUAL");
        while (!done) {
            view.showServerMessage(serverAnswer.nextLine());

            dataToServer = scanner.nextLine(); // read data from keyboard

            requestToServer.println(dataToServer); // send request to server
            switch (serverAnswer.nextLine().toUpperCase()) {
                case "UNKNOWN COMMAND":
                    view.showErrorFromServer("Unknown command");
                    break;
                case "CALC COMMAND":
                    if (serverAnswer.nextLine().toUpperCase().equals("PARSE 0")) {
                        view.showServerMessage(serverAnswer.nextLine());
                        dataToServer = scanner.nextLine();
                        requestToServer.println(dataToServer);
                        view.showServerMessage(serverAnswer.nextLine());
                    } else {
                        view.showErrorFromServer("Enter number greater than 0!");
                    }
                    break;
                case "HELP COMMAND":
                    view.showServerMessage(serverAnswer.nextLine());
                    break;
                case "QUIT COMMAND":
                    view.showServerMessage(serverAnswer.nextLine());
                    done = true;
                    break;
            }
        }
    }

    /**
     * Method that implements the communication protocol of a program 
     * running with an argument from the command line to the server.
     *
     * @param args array of arguments from the command line
     * @throws IOException when there is a problem with the streams
     */
    public void commandLineService(String[] args) throws IOException {
        ClientView view = new ClientView();
        Scanner serverAnswer = new Scanner(socket.getInputStream());  // create scanner for message from server
        PrintStream requestToServer = new PrintStream(socket.getOutputStream());

        requestToServer.println("CMD");
        requestToServer.println(Arrays.toString(args).replaceAll(",", " ").replaceAll("\\[|\\]", ""));
        switch (serverAnswer.nextLine().toUpperCase()) {
            case "UNKNOWN COMMAND":
                view.showErrorFromServer("Unknown command");
                break;
            case "CALC COMMAND":
                if (serverAnswer.nextLine().toUpperCase().equals("PARSE 0")) {
                    view.showServerMessage(serverAnswer.nextLine());
                    requestToServer.println("QUIT");
                } else {
                    view.showErrorFromServer("Enter number greater than 0!");
                }
                break;
            case "HELP COMMAND":
                view.showServerMessage(serverAnswer.nextLine());
                requestToServer.println("CMD");
                break;
            case "QUIT COMMAND":
                view.showServerMessage(serverAnswer.nextLine());
                break;
        }
    }

}
