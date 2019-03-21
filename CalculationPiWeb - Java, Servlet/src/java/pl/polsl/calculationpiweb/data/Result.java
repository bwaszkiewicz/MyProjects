/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.polsl.calculationpiweb.data;

/**
 * Class representing a particular calculation result
 * 
 * @author BW
 * @version 1.0
 */
public class Result {
    /**
     * Value of the result (calculated value of the number Pi)
     */
    private String resultValue;
    
    /**
     * Number of points used to calculate the Pi value
     */
    private int numberOfPoints;
    
    
    /**
     * Two-argument constructor of the Result class
     * 
     * @param resultValue value of the result (calculated value of the number Pi)
     * @param numberOfPoints number of points used to calculate the Pi value
     */
    Result(String resultValue, int numberOfPoints){
        this.resultValue = resultValue;
        this.numberOfPoints = numberOfPoints;
    }
    
    /**
     * Setter for 'resultValue' field
     * 
     * @param result Value of the result (calculated value of the number Pi)
     */
    public void setResultValue(String result){
        this.resultValue = result;
    }
    
    /**
     * Setter for 'getNumberOfPoints' field
     * 
     * @param numberOfPoints number of points used to calculate the Pi value
     */
    public void setNumberOfPoints(int numberOfPoints){
        this.numberOfPoints = numberOfPoints;
    }
    
    /**
     * Getter for 'resultValue' field
     * 
     * @return a String containing value of the result (calculated value of the number Pi)
     */
    public String getResultValue(){
        return this.resultValue;
    }
    
    /**
     * Getter for 'getNumberOfPoints' field
     * 
     * @return a int containing number of points used to calculate the Pi value
     */
    public int getNumberOfPoints(){
        return this.numberOfPoints;
    }
}
