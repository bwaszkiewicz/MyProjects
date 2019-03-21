/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.polsl.calculationpi.controller;

import java.util.InputMismatchException;
import java.util.Scanner;
import pl.polsl.calculationpi.exceptions.InvalidArgumentException;
import pl.polsl.calculationpi.exceptions.InvalidNumberOfArguments;
import pl.polsl.calculationpi.model.Model;
import pl.polsl.calculationpi.view.View;

/**
 * Controller to support the console version of the program
 *
 * @author BW
 * @version 1.0
 */
public class ConsoleController implements Controller {

    /**
     * The currently used view, 
     * allows to change to a console view / GUI
     */
    private final View CURRENT_VIEW;
    /**
     * The currently used model
     */
    private final Model CURRENT_MODEL;
    /**
     * The number of points to be used in the Monte Carlo method
     */
    private int numberOfPoints;
    /**
     * Informs whether the command line has been used
     */
    private Boolean cmdMode=false;

    /**
     * Constructor assigning the current view and model to the controller
     * 
     * @param view currently used view
     * @param model currently used model
     */
    public ConsoleController(View view, Model model) {
        this.CURRENT_VIEW = view;
        this.CURRENT_MODEL = model;
    }

    /**
     * Method responsible for taking the input data from the user
     * 
     * @throws pl.polsl.calculationpi.exceptions.InvalidArgumentException 
     * when numberOfPoints is less than 1 
     */
    @Override
    public void choosingNumberOfPoints() throws InvalidArgumentException {
        CURRENT_VIEW.showHello();
        Scanner input = new Scanner(System.in);
        try{
            this.numberOfPoints = input.nextInt();
        }
        catch(InputMismatchException e){
            System.err.println("Input data error. Enter an integer!");
            System.exit(2);
        }
        finally{
            input.close();
        }
        
        if(this.numberOfPoints<1){
            throw new InvalidArgumentException("The number of points should be greater than '0'!");
        }
    }
    
    /**
     * Method responsible for sending data for calculations
     * in the model and sending the result to the view.
     * 
     * @throws pl.polsl.calculationpi.exceptions.InvalidArgumentException 
     * when numberOfPoints is less than '1'
     */
    @Override
    public void calculateResult() throws InvalidArgumentException {
        if(this.numberOfPoints<1){
            throw new InvalidArgumentException("Result couldn't be calculated.");
        }
        else{
            try{
            CURRENT_VIEW.showResult(CURRENT_MODEL.calculatePi(numberOfPoints)); 
            }
            catch(InvalidArgumentException e){
                System.err.println(e.getMessage());
            }
        }
    }
    
    /**
     * Method supporting arguments from the command line
     * 
     * @param args array of arguments from the command line
     * @throws pl.polsl.calculationpi.exceptions.InvalidNumberOfArguments
     *         when attempting use more arguments than allowed on the command line
     */
    @Override
    public void commandLineSupport(String args[]) throws InvalidNumberOfArguments{
        if(args.length == 1)
        {
            try{
                this.numberOfPoints = Integer.parseInt(args[0]);   
            }
            catch(NumberFormatException e){
                System.err.println("No number of type int!");
                System.exit(1);
            }
            this.cmdMode=true;
        }
        else{
            if(args.length > 1){
                throw new InvalidNumberOfArguments("Number of arguments in command line more than '1'");
            }
        }
    }
    
    /**
     * Gettfer for 'cmdMode' field
     * 
     * @return information whether the arguments will be downloaded from the command line
     */
    public Boolean getCmdMode(){
        return cmdMode;
    }
}
