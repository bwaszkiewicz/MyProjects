/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.polsl.calculationpi.view;

/**
 * Interface of View
 * 
 * @author BW
 * @version 1.0
 */
public interface View {
    /**
     * The method responsible for instructing the user
     */
    void showHello();
    
    /**
     * Method displaying the result of the calculation
     * 
     * @param calculatedPiValue calculated value of pi number to show
     */
    void showResult(double calculatedPiValue);
}
