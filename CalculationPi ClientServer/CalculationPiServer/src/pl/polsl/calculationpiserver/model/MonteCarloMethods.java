/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.polsl.calculationpiserver.model;

import java.util.ArrayList;
import java.util.List;

/**
 * The class responsible for calculating the Pi value
 * 
 * @author BW
 * @version 2.0
 */
public class MonteCarloMethods implements Model {
    
    /**
     * Calculates the Pi value
     * 
     * @param numberOfPoints number of points to generate and check
     * @return calculated value of the number Pi
     * @throws InvalidArgumentException when attempt to divide by zero
     */
    @Override
    public double calculatePi(int numberOfPoints) throws InvalidArgumentException{
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
     * @return list of generated points
     */
    @SuppressWarnings("unchecked")
    private List<Point> generatePoints(int numberOfPoints){
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
     * @return number of points in circle
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
