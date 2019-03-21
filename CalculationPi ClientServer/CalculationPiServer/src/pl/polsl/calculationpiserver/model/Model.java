package pl.polsl.calculationpiserver.model;


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
     * @return the calculated value of the number Pi
     * @throws pl.polsl.calculationpiserver.model.InvalidArgumentException
     *         when attempt to divide by zero
     */
    double calculatePi(int numberOfPoints)throws InvalidArgumentException;
}
