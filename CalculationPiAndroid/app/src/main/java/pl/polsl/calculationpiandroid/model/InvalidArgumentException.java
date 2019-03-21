package pl.polsl.calculationpiandroid.model;

/**
 * Exception class for objects thrown when attempting
 * use forbidden value range
 *
 * @author BW
 * @version 1.0
 */
public class InvalidArgumentException extends Exception {

    /**
     * Non-parameter constructor
     */
    public InvalidArgumentException(){
    }

    /**
     * Single-parameter constructor
     *
     * @param message display message
     */
    public InvalidArgumentException(String message){
        super(message);
    }
}
