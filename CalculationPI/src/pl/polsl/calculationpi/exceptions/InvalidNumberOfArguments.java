/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.polsl.calculationpi.exceptions;

/**
 * Exception class for objects generated when attempting
 * use more arguments than allowed on the command line.
 * 
 * @author BW
 * @version 1.0
 */
public class InvalidNumberOfArguments extends Exception{
    
    /**
    * Non-parameter constructor 
    */
    public InvalidNumberOfArguments(){
    }
    
    /**
     * Single-parameter constructor
     * 
     * @param message display message
     */
    public InvalidNumberOfArguments(String message){
        super(message);
    }
}
