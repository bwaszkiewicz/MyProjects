package pl.polsl.calculationpiandroid.model;

import java.util.ArrayList;
import java.util.List;

/**
 * The class responsible for calculating the Pi value
 *
 * @author BW
 * @version 3.0
 */
public class MonteCarloMethods implements Model {

    /**
     * Calculates the Pi value
     *
     * @param numberOfPoints number of points to generate and check
     * @return a double containing calculated value of the number Pi
     * @throws InvalidArgumentException when attempt to divide by zero
     */
    @Override
    public double calculatePi(long numberOfPoints) throws InvalidArgumentException{
        if(numberOfPoints<0)
            throw new InvalidArgumentException("The number of points should be greater than '0'!");
        List<Point> listOfPoints = generatePoints(numberOfPoints);

        /**
         * Number of points inside the circle
         */
        int pointsInCircle = countPointsInCircle(listOfPoints);
        if(numberOfPoints == 0)
            throw new InvalidArgumentException("Don't divide by zero!");

        double ratioOfPoints = (double) pointsInCircle/numberOfPoints;

        /**
         * Multiply by 4 because this is the area of square.
         * This is due to the formula:
         * Pi = P Square * point Inside Circle / Point Outside Circle
         */
        return 4*ratioOfPoints;
    }

    /**
     * Generates points
     *
     * @param numberOfPoints number of points to generate
     * @return a List containing list of generated points
     */
    @SuppressWarnings("unchecked")
    private List<Point> generatePoints(long numberOfPoints){
        List<Point> listOfPoints = new ArrayList<>();
        for(int i=0;i<numberOfPoints;i++){
            listOfPoints.add(new Point((double)Math.random(),(double)Math.random()));
        }
        return listOfPoints;
    }

    /**
     * Counts the points contained in the circle
     *
     * @param listOfPoints list of points to check if they are in a circle
     * @return a int containing number of points in circle
     */
    private int countPointsInCircle(List<Point> listOfPoints){
        int pointsInCircle=0;
        for(Point i: listOfPoints)
        {
            if((double)i.getPointX()*(double)i.getPointX()+(double)i.getPointY()*(double)i.getPointY()<=1){
                pointsInCircle++;
            }
        }
        return pointsInCircle;
    }
}
