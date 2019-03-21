/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.polsl.calculationpi.model;

/**
 * Representation of the point
 * 
 * @author BW
 * @version 2.0
 */
class Point<T extends Number> {
    /**
     * Value of horizontal position
     */
    private final T X;
    
    /**
     * Value of vertical position
     */
    private final T Y;
    
    /**
     * Creates the point
     * 
     * @param x value of horizontal position
     * @param y value of vertical position
     */
    Point(T x, T y)
    {
        this.X=x;
        this.Y=y;
    }
    
    /**
     * Getter for 'x' field
     * 
     * @return current value of x (horizontal position)
     */
    T getPointX(){
        return this.X;
    }
    
    /**
     * Gettfer for 'y' field
     * 
     * @return current value of y (vertical position)
     */
    T getPointY(){
        return this.Y;
    }
}
