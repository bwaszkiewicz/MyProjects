/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.polsl.calculationpi.controller;

import pl.polsl.calculationpi.exceptions.InvalidArgumentException;
import pl.polsl.calculationpi.exceptions.InvalidNumberOfArguments;

/**
 *  Interface of Controller
 * 
 * @author BW
 * @version 1.0
 */
public interface Controller {
    
    /**
     * Method responsible for taking the input data from the user
     * @throws pl.polsl.calculationpi.exceptions.InvalidArgumentException
     *         when numberOfPoints is less than 1
     */
    void choosingNumberOfPoints() throws InvalidArgumentException;
    
    /**
     * Method responsible for sending data for calculations 
     * in the model and sending the result to the view.
     * @throws pl.polsl.calculationpi.exceptions.InvalidArgumentException
     *         when numberOfPoints is less than 1
     */
    void calculateResult() throws InvalidArgumentException;
   
    /**
     * Method supporting arguments from the command line
     * 
     * @param args array of arguments from the command line
     * @throws pl.polsl.calculationpi.exceptions.InvalidNumberOfArguments
     *         when attempting use more arguments than allowed on the command line
     */
    void commandLineSupport(String args[]) throws InvalidNumberOfArguments;
}
