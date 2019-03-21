package pl.polsl.calculationpiweb.database;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import javax.servlet.ServletConfig;
import pl.polsl.calculationpiweb.data.CalculationResults;

/**
 * Class responsible for service and communication with the database
 *
 * @author BW
 * @version 1.0
 */
public class DatabaseController {

    /**
     * Connection object with the database
     */
    private Connection con;

    /**
     * Constructor of the class managing the connection and communication with
     * the database
     *
     * @param config object that stores information about the connection
     * configuration with the database
     * @throws DatabaseConnectionException when a database access error occurs
     * @throws DatabaseSQLException when SQL queries error occur
     */
    public DatabaseController(ServletConfig config) throws DatabaseConnectionException, DatabaseSQLException {
        try {
            // loading the JDBC driver
            Class.forName(config.getInitParameter("JdbcDriver"));
        } catch (ClassNotFoundException cnfEx) {
            throw new DatabaseConnectionException();
        }

        try {
            this.con = DriverManager.getConnection("jdbc:derby://localhost:1527/"
                    + config.getInitParameter("DatabaseName"),
                    config.getInitParameter("DatabaseUserName"),
                    config.getInitParameter("DatabaseUserPassword"));
        } catch (SQLException sqlEx) {
            throw new DatabaseSQLException();
        }

    }

    /**
     * Method that creates the table structure in the database 
     * 
     * @throws DatabaseSQLException when SQL queries error occur
     */
    public void createTables() throws DatabaseSQLException{
        try {
            Statement statement = con.createStatement();
            statement.executeUpdate("CREATE TABLE Dane "
                    + "(id INTEGER NOT NULL GENERATED ALWAYS AS IDENTITY (START WITH 1, INCREMENT BY 1),"
                    + " numberOfPoints INTEGER,"
                    + " result REAL,"
                    + " CONSTRAINT primary_key PRIMARY KEY (id)) ");
            //System.out.println("Table created");
        } catch (SQLException sqlEx) {
            throw new DatabaseSQLException();
        }
    }

    /**
     * Method that enters data into the appropriate table
     * 
     * @param numberOfPoints number of points to generate
     * @param value value of the result (calculated value of the
     * number Pi)
     * @throws DatabaseSQLException when SQL queries error occur
     */
    public void insertData(int numberOfPoints, double value) throws DatabaseSQLException {
        try {
            Statement statement = con.createStatement();
            statement.executeUpdate("INSERT INTO Dane(numberOfPoints, result) VALUES (" + numberOfPoints + ", " + value + ")");
            //System.out.println("Data inserted");
        } catch (SQLException sqlEx) {
            throw new DatabaseSQLException();
        }
    }

    /**
     * Method that selects data from the table
     * 
     * @return CalculationResults containing information on the calculated 
     * results (contained in the table)
     * @throws DatabaseSQLException when SQL queries error occur
     */
    public CalculationResults selectData() throws DatabaseSQLException {

        CalculationResults results = new CalculationResults();
        try {
            Statement statement = con.createStatement();
            ResultSet rs = statement.executeQuery("SELECT * FROM Dane");
            while (rs.next()) {

                results.addResult(Double.toString(rs.getDouble("result")), rs.getInt("numberOfPoints"));
            }
            rs.close();
        } catch (SQLException sqlEx) {
            throw new DatabaseSQLException();
        }
        return results;
    }

    /**
     * Method that closes the connection to the database
     * 
     * @throws DatabaseSQLException when SQL queries error occur
     */
    public void closeDataConnection() throws DatabaseSQLException {
        try {
            con.close();
        } catch (SQLException sqlEx) {
            throw new DatabaseSQLException();
        }
    }

    /**
     * Method to check whether there is a suitable table 
     * for storing data in the database
     * 
     * @return Boolean: true - table exists
     *                  false - table not exists
     */
    public Boolean isTablesCreated() {
        try {
            Statement statement = con.createStatement();
            ResultSet rs = statement.executeQuery("SELECT * FROM Dane");
        } catch (SQLException sqlEx) {
            return false;
        }
        return true;
    }

}
