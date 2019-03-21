package pl.polsl.calculationpiweb.database;

/**
 * Exception class for objects thrown when 
 * problems with SQL queries occur
 * 
 * @author BW
 * @version 1.0
 */
public class DatabaseSQLException extends Exception {

    /**
     * Non-parameter constructor
     */
    public DatabaseSQLException() {

    }

    /**
     * Single-parameter constructor
     *
     * @param message display message
     */
    public DatabaseSQLException(String message) {
        super(message);
    }

}
