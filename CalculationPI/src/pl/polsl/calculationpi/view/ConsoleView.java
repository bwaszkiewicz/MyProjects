/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.polsl.calculationpi.view;

/**
 * View to support the console version of the program
 * 
 * @author BW
 * @version 1.0
 */
public class ConsoleView implements View {

    /**
     * Method instructing the user
     */
    @Override
    public void showHello() {
        System.out.println("Enter the number of points to generate: ");
    }

    /**
     * Method displaying the result of the calculation
     * 
     * @param calculatedPiValue calculated value of pi number to show
     */
    @Override
    public void showResult(double calculatedPiValue) {
        System.out.println("The calculated value of pi is: "+calculatedPiValue);
    }
    
}
