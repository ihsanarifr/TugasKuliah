using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace IvanHotel.ViewModels
{
    public class BookingVM
    {
        public int ID { get; set; }
        public string Nama { get; set; }
        public Nullable<int> NomorIdentitas { get; set; }
        public Nullable<int> TipeIdentitasID { get; set; }
        public Nullable<int> JenisKelaminID { get; set; }
        public string Alamat1 { get; set; }
        public Nullable<int> RT { get; set; }
        public Nullable<int> RW { get; set; }
        public Nullable<int> KodePos { get; set; }
        public Nullable<int> KecamatanID { get; set; }
        public Nullable<int> KelurahanID { get; set; }
        public Nullable<int> KabupatenKotaID { get; set; }
        public Nullable<int> TamuID { get; set; }

        public Nullable<System.DateTime> TMT { get; set; }
        public string CheckIn { get; set; }
        public string CheckOut { get; set; }
        public string KamarID { get; set; }
        public Nullable<int> Kontak1 { get; set; }
        public Nullable<int> TipeKontakID { get; set; }

        public BookingVM()
        {
            this.ID = 0;
            this.Nama = "";
            this.NomorIdentitas = 0;
            this.TipeIdentitasID = 0;
            this.JenisKelaminID = 0;
            this.Alamat1 = "";
            this.RT = 0;
            this.RW = 0;
            this.KodePos = 0;
            this.KecamatanID = 0;
            this.KelurahanID = 0;
            this.KabupatenKotaID = 0;
            this.TamuID = 0;
            this.TMT = DateTime.Now;
            this.CheckIn = "";
            this.CheckOut = "";
        }
    }
}