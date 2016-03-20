package Tugas3;

public class Main {

    public static void main(String[] args) {
        Intern peg1 = new Intern(10, 2, 3, "Smanda");
        Tetap peg2 = new Tetap(10, 2, 10, "Kepala TU");
        
        peg1.PrintKeterangan();
        peg2.PrintKeterangan();
    }
}