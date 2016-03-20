package Tugas3;

public abstract class Pegawai {
    protected int lamaKerja;
    protected int jumlahAnak;
    protected int lamaCuti;
    
    public Pegawai(int k,int a, int c){
        lamaKerja = k;
        jumlahAnak = a;
        lamaCuti = c;
    }
    
    // mencetak seluruh informasi
    public abstract void PrintKeterangan();
}
