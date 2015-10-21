package Tugas3;

public class Intern extends Pegawai implements Kerja,Administrasi{
    protected String AsalSekolah;
    protected int Keliling;

    public Intern(int k, int a, int c,String as) {
        super(k, a, c);
        AsalSekolah = as;
    }

    public String getAsalSekolah() {
        return AsalSekolah;
    }

    public void setAsalSekolah(String AsalSekolah) {
        this.AsalSekolah = AsalSekolah;
    }

    @Override
    public void PrintKeterangan() {
        System.out.println("Pegawai Intern");
        System.out.println("Asal Sekolah : "+AsalSekolah);
        kerjaKubus(lamaKerja);
        kerjaPersegi(lamaCuti);
        hitungGaji(jumlahAnak, lamaCuti);
        hitungPotongan(lamaCuti);
    }

    @Override
    public void kerjaPersegi(int s) {
        Keliling = s*4;
        System.out.println("Keliling Persegi : "+Keliling);
    }

    @Override
    public void kerjaKubus(int r) {
        Keliling = r*4;
        System.out.println("Keliling Kubus : "+Keliling);
    }

    @Override
    public void hitungGaji(int anak, int lama) {
        System.out.println("Gaji : "+lama*500000);
    }

    @Override
    public void hitungPotongan(int cuti) {
        System.out.println("Potongan : "+cuti*100000);
    }
}
