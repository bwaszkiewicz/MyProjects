package pl.polsl.calculationpi.test;

import pl.polsl.calculationpiweb.model.*;
import org.junit.*;
import static org.junit.Assert.*;

/**
 * The test case of MonteCarloMethod methods
 *
 * @author BW
 * @version 3.0
 */
public class MonteCarloMethodsTest {

    MonteCarloMethods monteCarloModel = new MonteCarloMethods();

    /**
     * Test that validates the CalculatePi method with correct argument
     */
    @Test
    public void testCorrectCalculation() {

        try {

            assertEquals("Pi value calculated on the basis of 100 points", monteCarloModel.calculatePi(1000), 3.14, 0.1);

            assertEquals("Pi value calculated on the basis of 100 points", monteCarloModel.calculatePi(10000), 3.14, 0.05);

        } catch (InvalidArgumentException e) {
            fail("Unexpected Invalid Argument Exception");
        }
    }

    /*
    * Test that validates the CalculatePi method with negative argument
    */
    @Test
    public void testNegativeArgument() {
        try {
            monteCarloModel.calculatePi(-5);
            fail("An exception should be thrown when the argument is less than zero");
        } catch (InvalidArgumentException e) {
        }
    }

    /*
    * Test that validates the CalculatePi method with zero argument
    */
    @Test
    public void testZeroArgument() {
        try {
            monteCarloModel.calculatePi(0);
            fail("An exception should be thrown when the argument is zero");
        } catch (InvalidArgumentException e) {
        }
    }
}
