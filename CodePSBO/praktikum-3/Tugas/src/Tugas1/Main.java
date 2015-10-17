package Tugas1;
import java.io.*;
public class Main {

    public static void main(String[] args) {
        // TODO code application logic here
        //Titik titik = new Titik(3.0,4.0);
        Titik titikA = new Titik(2,1);
        Titik titikB = new Titik(6,6);
        Titik titikC = new Titik(10,1);
        
        //System.out.println(titik2.Jarak(titik));
        
        Segitiga triangle = new Segitiga();
        
        triangle.setA(titikA);
        triangle.setB(titikB);
        triangle.setC(titikC);
        
        System.out.println(triangle.isSamaKaki());
        System.out.println(triangle.isSamaSisi());
        System.out.println(triangle.isSikuSiku());
    }
}