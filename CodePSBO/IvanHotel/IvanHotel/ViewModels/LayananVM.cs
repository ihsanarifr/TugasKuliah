using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace IvanHotel.ViewModels
{
    public class LayananVM
    {
        public int ID { get; set; }
        public Nullable<int> TipeLayananID { get; set; }
        //public int LayananID { get; set; }
        public string NamaTipeLayanan { get; set; }
        public string Nama { get; set; }
        public string Satuan { get; set; }
        public Nullable<int> Harga { get; set; }
        public Nullable<System.TimeSpan> Durasi { get; set; }
        public string Peralatan { get; set; }
        public string Deskripsi { get; set; }
        public string Kualitas { get; set; }
        public LayananVM()
        {
            this.ID = 0;
            this.TipeLayananID = 0;
            this.NamaTipeLayanan = "";
            this.Nama = "";
            this.Satuan = "";
            this.Satuan = "";
            this.Harga = 0;
            this.Durasi = TimeSpan.Zero;
            this.Peralatan = "";
            this.Deskripsi = "";
            this.Kualitas = "";
        }

        public LayananVM(int id, int tipelayananid, string namalayanan, string namatipelayanan, int harga)
        {
            ID = id;
            Nama = namalayanan;
            NamaTipeLayanan = namatipelayanan;
            Harga = harga;
        }
    }
}