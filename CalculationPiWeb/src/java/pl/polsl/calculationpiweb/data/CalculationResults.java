/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.polsl.calculationpiweb.data;

import java.util.ArrayList;

/**
 * Class for stores the results of calculations
 * 
 * @author BW
 * @version 1.0
 */
public class CalculationResults {
    /**
     * List of all saved results
     */
    private ArrayList<Result>results = new ArrayList();
    
    /**
     * Method adds a new result to the rest of the results
     * 
     * @param resultValue value of the result (calculated value of the number Pi)
     * @param numberOfPoints number of points used to calculate the Pi value
     */
    public void addResult(String resultValue, int numberOfPoints){
        this.results.add(new Result(resultValue, numberOfPoints));
    }
    
    /**
     * Gettfer for 'results' field
     * 
     * @return a ArrayList list of all saved results
     */
    public ArrayList<Result> getResult(){
        return this.results;
    }
}
