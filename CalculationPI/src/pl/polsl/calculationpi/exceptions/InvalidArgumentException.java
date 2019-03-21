/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.polsl.calculationpi.exceptions;

/**
 * Exception class for objects thrown when attempting
 * use forbidden value range
 * 
 * @author BW
 * @version 1.0
 */
public class InvalidArgumentException extends Exception {
    
    /**
     * Non-parameter constructor 
     */
    public InvalidArgumentException(){
    }
    
    /**
     * Single-parameter constructor 
     * 
     * @param message display message
     */
    public InvalidArgumentException(String message){
        super(message);
    }
}
