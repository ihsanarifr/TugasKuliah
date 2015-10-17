// http://www.tutorialspoint.com/java/java_overriding.htm
package Tugas2;

public abstract class Hewan {
    protected String nama;
    protected static int JmlBunyi;
    
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
