using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using IvanHotel.Models;
namespace IvanHotel.ViewModels
{
    public class KamarViewModel
    {
        public int ID { get; set; }
        public Nullable<int> NomorKamar { get; set; }
        public string Nama { get; set; }
        public Nullable<int> Kapasitas { get; set; }
        public Nullable<bool> Status { get; set; }
        public Nullable<int> TipeKamarID { get; set; }
        public Nullable<int> Lantai { get; set; }

        public IList<Fasilitas> Fasilitas { get; set; }
        public virtual ICollection<FasilitasKamar> FasilitasKamar { get; set; }
        public virtual TipeKamar TipeKamar { get; set; }
        public virtual ICollection<TransaksiTamu> TransaksiTamu { get; set; }

        public KamarViewModel()
        {
            ID = 0;
            NomorKamar = 0;
            Kapasitas = 0;
            Status = true;
            TipeKamarID = 0;
            Lantai = 0;
        }

        public KamarViewModel(int ID, string nama, int jumlah)
        {
            this.ID = ID;
            this.Nama = nama;
            this.Kapasitas = jumlah;
        }
    }
}