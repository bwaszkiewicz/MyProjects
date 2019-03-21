package pl.polsl.calculationpiclient;

import pl.polsl.calculationpiclient.controller.ConnectionController;
import java.io.IOException;
import pl.polsl.calculationpiclient.controller.InvalidPortFormatException;

/**
 * Main class of the client application that communicates with 
 * server application realizing calculating the Pi value.
 * 
 * @author BW
 * @version 1.0
 */
public class CalculationPiClient {

    /**
     * Main method of client application.
     * 
     * @param args first argument   - command quit/-help/-calc
     *             second argument  - (only with -calc command) number of points
     *                                to calculate the value of the Pi
     */
    public static void main(String[] args){

        try {
            ConnectionController controller = new ConnectionController();
            if(args.length == 0){
                try {
                    controller.manualService();
                } catch (IOException e) {
                    System.err.println("Streams connection broken");
                }
            }
            else{
                try{
                    controller.commandLineService(args);
                } catch (IOException e){
                    System.err.println("Streams connection broken");
                }
            }
        } catch (InvalidPortFormatException e) {
            System.err.println(e.getMessage());
        } catch(IOException e){
        System.err.println("Server connection broken");
        } 
    }
}
