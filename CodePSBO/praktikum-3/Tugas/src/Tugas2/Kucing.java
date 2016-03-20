package Tugas2;

public class Kucing extends Hewan {
    
    public Kucing(String h) {
        super(h);
    }
    @Override
    public void print() {
        super.print();
        System.out.println("Ini Kucing");
    }

    @Override
    public void berbunyi() {
        System.out.println("Meong");
    }
    
    public void berbunyi(int n){
        Hewan.setJmlBunyi(n);
        for(int i = 0;i<n;i++)
            berbunyi();        
    }
}
