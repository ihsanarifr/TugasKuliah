// http://www.tutorialspoint.com/java/java_overriding.htm
// http://logos.cs.uic.edu/examples%20and%20notes/notes/Java/Inheritance/
package Tugas2;

public abstract class Hewan {
    protected String nama;
    protected static int JmlBunyi;

    public static int getJmlBunyi() {
        return JmlBunyi;
    }

    public static void setJmlBunyi(int JmlBunyi) {
        Hewan.JmlBunyi = JmlBunyi;
    }
    
    public Hewan(String h){
        this.nama = h;
    }

    public String getNama() {
        return nama;
    }

    public void setNama(String nama) {
        this.nama = nama;
    }
    
    public abstract void berbunyi();
    
    public void print(){
        System.out.println("Nama : "+ nama );
        System.out.println("Jumlah Bunyi : "+JmlBunyi);
    }
    
}
