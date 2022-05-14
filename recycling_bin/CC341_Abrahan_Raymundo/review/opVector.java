/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package review;

import static java.lang.Math.sqrt;


public class opVector {
    //Vector vector=new Vector();
    
    public Vector sumar(Vector vector, Vector v){
        Vector suma=new Vector(v.count());
        for(int i=0; i<v.count(); i++){
            suma.setItem(i, (v.getItem(i)+ vector.getItem(i)));
        }
        return suma;
    }
    
    public Vector resta(Vector vector, Vector v){
        Vector resta=new Vector(v.count());
        for(int i=0; i<v.count(); i++){
            resta.setItem(i, (vector.getItem(i)- v.getItem(i)));
        }
        return resta;
    }
    
    public float magnitud(Vector vector){
        float mag;
        float sumCuad=0;
        for(int i=0; i<vector.count(); i++){
            sumCuad=sumCuad + (vector.getItem(i)*vector.getItem(i));
        }
        mag = (float) sqrt(sumCuad);
        return mag;
    }
    
}
