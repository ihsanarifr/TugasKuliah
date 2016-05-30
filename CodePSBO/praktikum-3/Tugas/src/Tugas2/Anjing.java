package Tugas2;

public class Anjing extends Hewan {
    
    public Anjing(String h) {
        super(h);
    }
    @Override
    public void print() {
        super.print();
        System.out.println("Ini Anjing");
    }

    @Override
    public void berbunyi() {
        System.out.println("Guk");
    }
    
    public void berbunyi(int n){
        Hewan.setJmlBunyi(n);
        for(int i = 0;i<n;i++)
            berbunyi();        
    }
}
