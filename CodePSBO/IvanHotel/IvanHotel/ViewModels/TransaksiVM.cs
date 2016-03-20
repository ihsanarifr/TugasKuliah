using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace IvanHotel.ViewModels
{
    public class TransaksiVM
    {
        public int no { get; set; }
        public int ID { get; set; }
        public string Nama { get; set; }
        public string JenisKelamin { get; set; }
        public int NomorIdentitas { get; set; }
        public DateTime? TMT { get; set; }
        public string Registrasi { get; set; }
        public int TamuID { get; set; }
        public int TransaksiID { get; set; }
        public int NomorKamar { get;set; }
        public string TipeKamar { get; set; }
        public DateTime CheckIn { get; set; }
        public DateTime CheckOut { get; set; }
        public int Harga { get; set; }
        public string NamaTipeLayanan { get; set; }
        public string LayananID { get; set; }

        public TransaksiVM()
        {
            this.no = 0;
            this.ID = 0;
            this.Nama = "";
            this.JenisKelamin = "";
            this.NomorIdentitas = 0;
            this.TMT = DateTime.Now;
            this.Registrasi = "";
            this.TamuID = 0;
            this.TransaksiID = 0;
            this.NomorKamar = 0;
            this.TipeKamar = "";
            this.CheckIn = DateTime.Now;
            this.CheckOut = DateTime.Now;
            this.Harga = 0;
            this.LayananID = "";
        }

        public TransaksiVM(int no,int id, string nama, string jk, int noid,DateTime? tmt,string registrasi,int tamuid)
        {
            ID = id;
            Nama = nama;
            JenisKelamin = jk;
            NomorIdentitas = noid;
            TMT = tmt;
            Registrasi = registrasi;
            TamuID = tamuid;
        }

        public TransaksiVM(int no,int transaksiid, int nokar, string tikar,DateTime checkin,DateTime checkout,int harga)
        {
            TransaksiID = transaksiid;
            NomorKamar = nokar;
            TipeKamar = tikar;
            CheckIn = checkin;
            CheckOut = checkout;
            Harga = harga;
        }

        public TransaksiVM(int no,int id, string nama, int harga, string namalayanan)
        {
            ID = id;
            Nama = nama;
            Harga = harga;
            NamaTipeLayanan = namalayanan;
        }
    }
}