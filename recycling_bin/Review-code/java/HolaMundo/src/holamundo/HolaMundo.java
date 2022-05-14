/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package holamundo;
import java.util.Scanner;

/**
 *
 * @author ACER NITRO 5
 */
public class HolaMundo {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Ingrese a: ");
        int a = input.nextInt();
        System.out.println("Ingrese b: ");
        int b = input.nextInt();
        int suma = a+b;
        System.out.println(""+ a + "+" + b + "=" + suma);
    }
    
}
