/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.polsl.calculationpiweb.data;

/**
 * Class for counting events
 * 
 * @author BW
 * @version 1.0
 */
public class Counter {
    /**
     * Number of counted events
     */
    int numberOfCounted;
    
    /**
     * Method of incrementing the counter
     */
    public void hitCounter(){
        this.numberOfCounted++;
    }
    
    /**
     * Gettfer for 'numberOfCounted' field
     * 
     * @return a int containing number of counted events
     */
    public int getNumberOfCounted(){
        return this.numberOfCounted;
    }
}
