using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using IvanHotel.ViewModels;
using IvanHotel.Models;
using System.Data.Entity;

namespace IvanHotel.BussinessModels
{
    public class TransaksiBM
    {
        DBReservasiHotelEntities db = new DBReservasiHotelEntities();

        public TransaksiBM()
        {
            db = new DBReservasiHotelEntities();
        }

        public List<TransaksiVM> Transaksi(){
            List<TransaksiVM> transaksi = new List<TransaksiVM>();

            var query = from tm in db.TransaksiTamu
                        select new
                        {
                            tm.ID,
                            tm.TamuID,
                            tm.Tamu.Nama,
                            JenisKelamin = tm.Tamu.JenisKelamin.Nama,
                            tm.Tamu.NomorIdentitas,
                            tm.TMT,
                            Registrasi = (tm.IsRegistrasiUlang == true ? "Ya" : "Tidak")
                        };
            int no = 1;
            foreach (var item in query)
            {
                transaksi.Add(new TransaksiVM(no++,item.ID, item.Nama, item.JenisKelamin, (int)item.NomorIdentitas,item.TMT,item.Registrasi,(int)item.TamuID));
            }
            return transaksi;
        }

        public void Verifikasi(int id)
        {
            TransaksiTamu data = db.TransaksiTamu.Find(id);
            data.IsRegistrasiUlang = true;
            db.Entry(data).State = EntityState.Modified;
            db.SaveChanges();
        }

        public TamuVM details(int? id)
        {
            TransaksiTamu data = db.TransaksiTamu.Find(id);
            TamuVM tamu = new TamuVM();

            var query = (from t in db.Tamu
                        join al in db.Alamat on t.ID equals al.TamuID
                        join ko in db.Kontak on t.ID equals ko.TamuID
                        where t.ID == data.TamuID
                        select new
                        {
                            t.ID,
                            t.Nama,
                            t.NomorIdentitas,
                            JenisKelamin = t.JenisKelamin.Nama,
                            TipeIdentitas = t.TipeIdentitas.Nama,
                            Alamat = al.Alamat1,
                            Kabupaten = al.KabupatenKota.Nama,
                            Kecamatan = al.Kecamatan.Nama,
                            NomorKontak = ko.Kontak1,
                            TipeKontak = ko.TipeKontak.Nama
                        }).FirstOrDefault();
            
            tamu.ID = query.ID;
            tamu.Nama = query.Nama;
            tamu.NomorKontak = query.NomorIdentitas.ToString();
            tamu.JenisKelamin = query.JenisKelamin;
            tamu.NamaTipeIdentitas = query.TipeIdentitas;
            tamu.Alamat = query.Alamat;
            tamu.Kabupaten = query.Kabupaten;
            tamu.Kecamatan = query.Kecamatan;
            tamu.NomorKontak = query.NomorKontak.ToString();
            tamu.NamaTipeKontak = query.TipeKontak;
            tamu.TransaksiID = (int)id;
            return tamu;
        }

        public List<TransaksiVM> TransaksiKamar(int id)
        {
            List<TransaksiVM> data = new List<TransaksiVM>();
            var query = from i in db.TransaksiKamar
                        where i.TransaksiTamuID == id
                        select new
                        {
                            i.ID,
                            i.Kamar.NomorKamar,
                            TipeKamar = i.Kamar.TipeKamar.Nama,
                            i.CheckIn,
                            i.CheckOut,
                            i.Kamar.HargaWeekDay,
                            i.Kamar.HargaWeekEnd
                            //Harga = (i.CheckIn.Value.DayOfWeek.Equals(1)|| i.CheckIn.Value.DayOfWeek.Equals(2) ? i.Kamar.HargaWeekEnd : i.Kamar.HargaWeekDay)
                        };
            int Harga;
            int no=1;
            foreach (var item in query)
            {
                if ((int)item.CheckIn.Value.DayOfWeek == 1 || (int)item.CheckIn.Value.DayOfWeek == 2)
                {
                    Harga = (int)item.HargaWeekEnd;
                }
                else
                {
                    Harga = (int)item.HargaWeekDay;
                }
                data.Add(new TransaksiVM(no++,item.ID, (int)item.NomorKamar, item.TipeKamar,(DateTime)item.CheckIn,(DateTime)item.CheckOut,Harga));
            }
            return data;
        }

        public List<TransaksiVM> TrasaksiLayanan(int id)
        {
            List<TransaksiVM> data = new List<TransaksiVM>();

            var query = from i in db.TransaksiLayanan
                        where i.TransaksiTamuID == id
                        select new
                        {
                            i.ID,
                            i.Layanan.Nama,
                            i.Layanan.Harga,
                            NamaTipeLayanan = i.Layanan.TipeLayanan.Nama
                        };
            int no = 1;
            foreach (var item in query)
            {
                data.Add(new TransaksiVM(no++,item.ID,item.Nama,(int)item.Harga,item.NamaTipeLayanan));
            }
            return data;
        }

        public void TambahTransaksiLayanan(TransaksiVM transaksi)
        {
            TransaksiLayanan layanan = new TransaksiLayanan();
            // tambah ke transaksi layanan
            string[] layananid = transaksi.LayananID.Split(',');
            for (int i = 0; i < layananid.Length; i++)
            {
                layanan.LayananID = Int32.Parse(layananid[i]);
                layanan.TransaksiTamuID = transaksi.TransaksiID;
                db.TransaksiLayanan.Add(layanan);
                db.SaveChanges();
            }
        }
    }
}