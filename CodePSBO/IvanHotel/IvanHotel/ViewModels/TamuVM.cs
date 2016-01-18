using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace IvanHotel.ViewModels
{
    public class TamuVM
    {
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

        public TamuVM(string nama, int nomor,string jk,string alamat,string kec,string kab,string nok,string tipid,string tiko,int transaksiid)
        {
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