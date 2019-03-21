/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.polsl.calculationpi.model;

import pl.polsl.calculationpi.exceptions.InvalidArgumentException;


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
     * @throws pl.polsl.calculationpi.exceptions.InvalidArgumentException
     *         when attempt to divide by zero
     */
    double calculatePi(int numberOfPoints)throws InvalidArgumentException;
}
