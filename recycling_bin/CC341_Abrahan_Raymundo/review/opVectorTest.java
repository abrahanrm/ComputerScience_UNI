/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package review;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author ACER NITRO 5
 */
public class opVectorTest {
    
    public opVectorTest() {
    }
    
    @BeforeClass
    public static void setUpClass() {
    }
    
    @AfterClass
    public static void tearDownClass() {
    }
    
    @Before
    public void setUp() {
    }
    
    @After
    public void tearDown() {
    }

    /**
     * Test of sumar method, of class opVector.
     */
    @Test
    public void testSumar() {
        System.out.println("sumar");
        float v1[] = {1,2,3};
        float v2[] = {2,3,4};
        Vector vector = new Vector(v1);
        Vector v = new Vector(v2);
      
        opVector instance = new opVector();
        Vector expResult = null;
        Vector result = instance.sumar(vector, v);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of resta method, of class opVector.
     */
    @Test
    public void testResta() {
        System.out.println("resta");
        float v1[] = {1,2,3};
        float v2[] = {2,3,4};
        Vector vector = new Vector(v1);
        Vector v = new Vector(v2);
        opVector instance = new opVector();
        Vector expResult = null;
        Vector result = instance.resta(vector, v);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of magnitud method, of class opVector.
     */
    @Test
    public void testMagnitud() {
        System.out.println("magnitud");
        float v1[] = {1,2,3};
        Vector vector = new Vector(v1);
        opVector instance = new opVector();
        float expResult = 0.0F;
        float result = instance.magnitud(vector);
        assertEquals(expResult, result, 0.0);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }
    
}
