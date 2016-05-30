// http://www.cs.toronto.edu/~andria/csc/108s98/programs/tut4/Triangle.java
package Tugas1;

public class Segitiga extends Titik{

    private Titik A;
    private Titik B;
    private Titik C;

    public Segitiga(){
        this.A = new Titik(0.0,0.0);
        this.B = new Titik(0.0,0.0);
        this.C = new Titik(0.0,0.0);
    }
    
    // constructor
    public Segitiga(Titik a, Titik b, Titik c) {
        this.A = a;
        this.B = b;
        this.C = c;
    }

    // setter & getter
    public Titik getA() {
        return A;
    }

    public void setA(Titik A) {
        this.A = A;
    }

    public Titik getB() {
        return B;
    }

    public void setB(Titik B) {
        this.B = B;
    }

    public Titik getC() {
        return C;
    }

    public void setC(Titik C) {
        this.C = C;
    }

    public boolean isSikuSiku() {
        // scalene triangle
        if ((A != B) && (A != C) && (B != C)) {
            return true;
        } else {
            return false;
        }
    }

    public boolean isSamaSisi() {
        // equilateral triangle
        if ((A == B) && (A == C)) {
            return true;
        } else {
            return false;
        }
    }

    public boolean isSamaKaki() {
        // isosceles triangle
        if (((A == B) && (A != C))
                || ((A == B) && (A != B))
                || ((B == C) && (B != A))) {
            return true;
        } else {
            return false;
        }
    }
}
