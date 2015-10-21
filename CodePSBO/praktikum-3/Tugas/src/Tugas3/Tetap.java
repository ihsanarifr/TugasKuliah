package Tugas3;

public class Tetap extends Pegawai implements Kerja,Administrasi{
    
    protected String Jabatan;
    protected int Luas;
    protected int hitung;
    
    public Tetap(int k, int a, int c, String j) {
        super(k, a, c);
        Jabatan = j;
    }

    @Override
    public void PrintKeterangan() {
        System.out.println("Pegawai Tetap");
        System.out.println("Jabatan : "+Jabatan);
        kerjaKubus(lamaKerja);
        kerjaPersegi(lamaCuti);
        hitungGaji(jumlahAnak, lamaCuti);
        hitungPotongan(lamaCuti);
    }

    @Override
    public void kerjaPersegi(int s) {
        Luas = (2*s)+(2*s)+(2*s);
        System.out.println("Luas Persegi : "+Luas);
    }

    @Override
    public void kerjaKubus(int r) {
        Luas= r*r*r;
        System.out.println("Luas Kubus : "+Luas);
    }

    @Override
    public void hitungGaji(int anak, int lama) {
        hitung = (lama*1500000) + (anak*5000000);
        System.out.println("Gaji : "+hitung);
    }

    @Override
    public void hitungPotongan(int cuti) {
        hitung = cuti*50000;
        System.out.println("Cuti : "+hitung);
    }
    
}
