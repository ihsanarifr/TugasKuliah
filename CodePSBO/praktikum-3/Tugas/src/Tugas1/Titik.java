package Tugas1;

public class Titik {
    private double x;
    private double y;
    
    // membuat titik dengan koordinat (0,0)
    public Titik(){
        this.x = 0;
        this.y = 0;
    }
    
    // membuat titik dengan koordinat yang diberikan (x,y)
    public Titik(double x, double y){
        this.x = x;
        this.y = y;
    }
    
    //setter & getter

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }
    
    public double Jarak(Titik p){
        double dx = this.x - p.getX();
        double dy = this.y - p.getY();
        return Math.sqrt(dx*dx+dy*dy);
    }
}
