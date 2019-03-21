package pl.polsl.calculationpiweb.database;

/**
 * Exception class for objects thrown when 
 * there are problems connecting to the database
 *
 * @author BW
 * @version 1.0
 */
public class DatabaseConnectionException extends Exception {

    /**
     * Non-parameter constructor
     */
    public DatabaseConnectionException() {

    }

    /**
     * Single-parameter constructor
     *
     * @param message display message
     */
    public DatabaseConnectionException(String message) {
        super(message);
    }
}
