using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace IvanHotel.ViewModels
{
    public class TamuVM
    {
        public int ID { get; set; }
        public string Nama { get; set; }
        public int NomorIdentitas { get; set; }
        public string NamaTipeIdentitas {get;set;}
        public string JenisKelamin { get; set; }
        public string Alamat { get; set; }
        public string Kecamatan { get; set; }
        public string Kabupaten { get; set; }
        public string NomorKontak { get; set; }
        public string NamaTipeKontak { get; set; }
        public int TransaksiID { get; set; }

        public TamuVM()
        {
            ID = 0;
            Nama = "";
            NomorIdentitas = 0;
            JenisKelamin = "";
            Alamat = "";
            Kecamatan = "";
            Kabupaten = "";
            NomorKontak = "";
            NamaTipeIdentitas = "";
            NamaTipeKontak = "";
            TransaksiID = 0;
        }

        public TamuVM(int id,string nama, int nomor,string jk,string alamat,string kec,string kab,string nok,string tipid,string tiko,int transaksiid)
        {
            ID = id;
            Nama = nama;
            NomorIdentitas = nomor;
            JenisKelamin = jk;
            Alamat = alamat;
            Kecamatan = kec;
            Kabupaten = kab;
            NomorKontak = nok;
            NamaTipeIdentitas = tipid;
            NamaTipeKontak = tiko;
            TransaksiID = transaksiid;
        }
    }
}