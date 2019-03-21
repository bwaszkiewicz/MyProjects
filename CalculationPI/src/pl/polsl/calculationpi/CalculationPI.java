/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.polsl.calculationpi;

import pl.polsl.calculationpi.exceptions.InvalidArgumentException;
import pl.polsl.calculationpi.controller.ConsoleController;
import pl.polsl.calculationpi.exceptions.InvalidNumberOfArguments;
import pl.polsl.calculationpi.model.MonteCarloMethods;
import pl.polsl.calculationpi.view.ConsoleView;





/**
 * Main class of the application realizing calculating the Pi value.
 * 
 * @author BW
 * @version 2.0
 */
public class CalculationPI {

    /**
     * Main method of the application.
     * 
     * @param args first arg - number of points to calculate the value of the number Pi
     */
    public static void main(String[] args){
        // Creating a new controller for the console version with a view for the console version and a specific model
    ConsoleController controller = new ConsoleController(new ConsoleView(), new MonteCarloMethods());
    
    try{
        // Checking if there are arguments on the command line
        controller.commandLineSupport(args);
    }
    catch(InvalidNumberOfArguments e)
    {
        System.err.println(e.getMessage());
    }
    
    // If no arguments were found on the command line
    if(!controller.getCmdMode())
    {
        try{
        // Taking arguments from the user
        controller.choosingNumberOfPoints();
        }
        catch(InvalidArgumentException e){
            System.err.println(e.getMessage());
        }
    }
    
    try{
        // Calculation of the Pi value
        controller.calculateResult();
    }
    catch(InvalidArgumentException e){
        System.err.println(e.getMessage());
        System.exit(3);
    }
        
    }
    
}
