package pl.polsl.calculationpiclient.controller;

/**
 * Exception class for objects thrown when attempting wrong port format
 * 
 * @author BW
 * @version 1.0
 */
public class InvalidPortFormatException extends Exception {
    /**
     * Non-parameter constructor 
     */
    public InvalidPortFormatException(){
    }
    
    /**
     * Single-parameter constructor 
     * 
     * @param message display message
     */
    public InvalidPortFormatException(String message){
        super(message);
    }
}
