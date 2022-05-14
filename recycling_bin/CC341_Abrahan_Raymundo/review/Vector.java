/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package review;

import static java.lang.Math.sqrt;

/**
 *
 * @author ACER NITRO 5
 
public class Vector {
    private float vector[];
    private float x[];
    private float y[];
    
    public Vector(int n){
        vector = new float[n];
    }
    
    public Vector(float[] x){
        for(int i=0; i<x.length; i++)
            y[i]=x[i];
    }
    
}
*/

public class Vector{

private float vector[];
private float x[];
private float y[];
private float v[];
    
    public Vector(int n){
        vector = new float[n];
    }
    
    public Vector(float[] x){
        for(int i=0; i<x.length; i++)
            y[i]=x[i];
    }
    
    public float getItem(int i){
        return vector[i];
    }
    
    public void setItem(int i, float val){
        vector[i]=val;
    }
    
    public int count(){
        return vector.length;
    }
    
    public float max(){
        float max=0;
        for(int i=0; i<vector.length; i++)
            if(max<vector[i]) max=vector[i];
        return max;
    }
    
    public float min(){
        float min=0;
        for(int i=0; i<vector.length; i++)
            if(min>vector[i]) min=vector[i];
        return min;
    }
    
    public float avg(){
        float prom;
        float sum=0;
        for(int i=0; i<vector.length; i++)
            sum=vector[i]+sum;
        prom = sum/vector.length;
        return prom;
    }
    
}