package Tugas2;
import java.io.*;
import Tugas2.*;
public class Main {

    public static void main(String[] args) {
        Anjing animal = new Anjing("Rubi");
        Kucing animal2 = new Kucing("cat");
        
        animal2.berbunyi();
        animal2.berbunyi(2);
        animal2.print();
        
        animal.berbunyi(3);
        animal.print();
    }
}