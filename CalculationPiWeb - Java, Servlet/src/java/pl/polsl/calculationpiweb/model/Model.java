package pl.polsl.calculationpiweb.model;


/**
 * Interface of Model
 * 
 * @author BW
 * @version 1.0
 */
public interface Model {
    
    /**
     * Calculates the Pi value
     * 
     * @param numberOfPoints number of points to generate and check
     * @return a double containing the calculated value of the number Pi
     * @throws pl.polsl.calculationpiweb.model.InvalidArgumentException
     *         when attempt to divide by zero
     */
    double calculatePi(long numberOfPoints)throws InvalidArgumentException;
}
