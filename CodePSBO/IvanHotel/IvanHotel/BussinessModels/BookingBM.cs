using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Web;
using IvanHotel.Models;
using IvanHotel.ViewModels;

namespace IvanHotel.BussinessModels
{
    public class BookingBM
    {
        DBReservasiHotelEntities db = new DBReservasiHotelEntities();
        public BookingBM()
        {
            db = new DBReservasiHotelEntities();
        }

        public List<KamarViewModel> listKamar()
        {
            List<KamarViewModel> lkamar = new List<KamarViewModel>();
            var query = from i in db.TipeKamar
                        select new
                        {
                            i.ID,
                            i.Nama,
                            JumlahKosong = (from k in db.Kamar where k.TipeKamarID == i.ID && k.Status== true select k.ID).Count()
                        };
            foreach (var item in query)
            {
                lkamar.Add(new KamarViewModel(item.ID, item.Nama, item.JumlahKosong));
            }
            return lkamar;
        }

        public List<KamarViewModel> InforKamarNotAvailable()
        {
            List<KamarViewModel> lkamar = new List<KamarViewModel>();
            var query = from i in db.TipeKamar
                        select new
                        {
                            i.ID,
                            i.Nama,
                            JumlahKosong = (from k in db.Kamar where k.TipeKamarID == i.ID && k.Status == false select k.ID).Count()
                        };
            foreach (var item in query)
            {
                lkamar.Add(new KamarViewModel(item.ID, item.Nama, item.JumlahKosong));
            }
            return lkamar;
        }

        public void Create(BookingVM book)
        {
            // tambah tabel kontak
            Kontak kontak = new Kontak();
            kontak.Kontak1 = book.Kontak1;
            kontak.TipeKontakID = book.TipeKontakID;
            kontak.TamuID = book.TamuID;
            db.Kontak.Add(kontak);
            db.SaveChanges();

            // tambah ke tabel alamat
            Alamat alamat = new Alamat();
            alamat.Alamat1 = book.Alamat1;
            alamat.KabupatenKotaID = 1;
            alamat.KecamatanID = 1;
            alamat.KelurahanID = 1;
            alamat.RT = 0;
            alamat.RW = 0; ;
            alamat.KodePos = 0 ;
            alamat.TamuID = book.TamuID;
            db.Alamat.Add(alamat);
            db.SaveChanges();

            // tambah ke transaksi tamu
            TransaksiTamu transaksitamu = new TransaksiTamu();
            transaksitamu.PegawaiID = 1;
            transaksitamu.TamuID = book.TamuID;
            transaksitamu.TMT = DateTime.Today;
            transaksitamu.TST = "";
            transaksitamu.IsBayar = false;
            transaksitamu.IsRegistrasiUlang = false;
            db.TransaksiTamu.Add(transaksitamu);
            db.SaveChanges();

            // tambah ke transaksi kamar
            string[] kamarid = book.KamarID.Split(',');
            string[] checkin = book.CheckIn.Split(',');
            string[] checkout = book.CheckIn.Split(',');

            for (int i = 0; i < kamarid.Length; i++)
            {
                TransaksiKamar transaksikamar = new TransaksiKamar();
                transaksikamar.CheckIn = DateTime.Parse(checkin[i]);//DateTime.ParseExact(checkin[i], "yyyy-mm-dd", System.Globalization.CultureInfo.InvariantCulture);
                transaksikamar.CheckOut = DateTime.Parse(checkin[i]);//DateTime.ParseExact(checkout[i],"yyyy-mm-dd",System.Globalization.CultureInfo.InvariantCulture);
                //transaksikamar.KamarID = db.Kamar.Where(x => x.TipeKamarID.Equals(kamarid[i]) && x.Status.Equals(true)).Select(x => x.ID).SingleOrDefault();
                transaksikamar.KamarID = cekKamarKosong(Int32.Parse(kamarid[i]));
                transaksikamar.TransaksiTamuID = db.TransaksiTamu.Max(x => x.ID);
                db.TransaksiKamar.Add(transaksikamar);
                db.SaveChanges();

                // update status kamar
                Kamar kamar = db.Kamar.Find(transaksikamar.KamarID);
                kamar.Status = false;
                db.Entry(kamar).State = EntityState.Modified;
                db.SaveChanges();
            }
        }

        public int cekKamarKosong(int TipeKamarID)
        {
            int KamarID = (from i in db.Kamar
                           where i.TipeKamarID == TipeKamarID && i.Status == true
                           orderby i.ID ascending
                           select i.ID).FirstOrDefault();
            return KamarID;
        }
    }
}