package pl.polsl.calculationpi.test;

import pl.polsl.calculationpi.model.*;
import org.junit.*;
import static org.junit.Assert.*;
import pl.polsl.calculationpi.exceptions.InvalidArgumentException;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * The test case of MonteCarloMethod methods
 * 
 * @author BW
 * @version 2.0
 */
public class MonteCarloMethodsTest {
    
    MonteCarloMethods monteCarloModel = new MonteCarloMethods();
    
    /**
     * Test that validates the CalculatePi method
     */
    @Test
    public void testCalculatePi(){
        
        try{
            
            assertEquals("Pi value calculated on the basis of 100 points", monteCarloModel.calculatePi(1000), 3.14, 0.1);
            
            assertEquals("Pi value calculated on the basis of 100 points", monteCarloModel.calculatePi(10000), 3.14, 0.05);
            
            monteCarloModel.calculatePi(-5);
            fail("An exception should be thrown when the argument is less than zero");
        }
        catch(InvalidArgumentException e){
        }
        
        try{
            monteCarloModel.calculatePi(0);
            fail("An exception should be thrown when the argument is zero");
        }
        catch(InvalidArgumentException e){
        }
        

        
    }
}
