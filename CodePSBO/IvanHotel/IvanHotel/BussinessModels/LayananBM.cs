using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using IvanHotel.ViewModels;
using IvanHotel.Models;
using System.Data.Entity;

namespace IvanHotel.BussinessModels
{
    public class LayananBM
    {
        DBReservasiHotelEntities db = new DBReservasiHotelEntities();
        public LayananBM()
        {
            db = new DBReservasiHotelEntities();
        }

        public List<LayananVM> Layanan()
        {
            List<LayananVM> layanan = new List<LayananVM>();

            var list = from i in db.Layanan
                       select new
                       {
                           i.ID,
                           NamaLayanan = i.Nama,
                           i.TipeLayananID,
                           NamaTipeLayanan = i.TipeLayanan.Nama,
                           Harga = i.Harga,
                           //i.Spa.Durasi,
                           //i.Laundry.Satuan
                       };
            foreach (var item in list)
            {
                layanan.Add(new LayananVM((int)item.ID, (int)item.TipeLayananID, item.NamaLayanan, item.NamaTipeLayanan, (int)item.Harga/*, (TimeSpan)item.Durasi, item.Satuan*/));
            }
            return layanan;
        }

        public LayananVM details(int id)
        {
            LayananVM data = new LayananVM();
            Layanan layanan = new Layanan();

            int? tipelayananid = db.Layanan.Where(x=>x.ID.Equals(id)).Select(x=>x.TipeLayananID).SingleOrDefault();
            layanan = db.Layanan.Find(id);

            data.Nama = layanan.Nama;
            data.Harga = layanan.Harga;
            data.Deskripsi = layanan.Deskripsi;
            data.NamaTipeLayanan = layanan.TipeLayanan.Nama;
            data.TipeLayananID = layanan.TipeLayananID;

            if (tipelayananid == 1)
            {
                Laundry laundry = db.Laundry.Find(id);
                data.ID = laundry.ID;
                data.Satuan = laundry.Satuan;
                data.Kualitas = laundry.Kualitas;
            }else
            {
                Spa spa = db.Spa.Find(id);
                data.ID = spa.ID;
                data.Durasi = spa.Durasi;
                data.Peralatan = spa.Alat;
            }
            return data;
        }

        public void create(LayananVM data)
        {
            // insert ke tabel layanan
            Layanan layanan = new Layanan();
            layanan.Nama = data.Nama;
            layanan.TipeLayananID = data.TipeLayananID;
            layanan.Harga = data.Harga;
            layanan.Deskripsi = data.Deskripsi;
            db.Layanan.Add(layanan);
            db.SaveChanges();

            // layanan laundry
            if (data.TipeLayananID == 1)
            {
                Laundry laundry = new Laundry();
                laundry.ID = db.Layanan.Max(x => x.ID);
                laundry.Satuan = data.Satuan;
                laundry.Kualitas = data.Kualitas;
                db.Laundry.Add(laundry);
                db.SaveChanges();
            }
            // layanan spa
            else
            {
                Spa spa = new Spa();
                spa.ID = db.Layanan.Max(x => x.ID);
                spa.Alat = data.Peralatan;
                spa.Durasi = data.Durasi;
                db.Spa.Add(spa);
                db.SaveChanges();
            }
        }

        public void update(LayananVM data)
        {
            Layanan layanan = new Layanan();
            layanan.Nama = data.Nama;
            layanan.Harga = data.Harga;
            layanan.TipeLayananID = data.TipeLayananID;
            layanan.Deskripsi = data.Deskripsi;
            db.Entry(layanan).State = EntityState.Modified;
            db.SaveChanges();

            if (data.TipeLayananID == 1)
            {
                Laundry laundry = new Laundry();
                laundry.ID = data.ID;
                laundry.Kualitas = data.Kualitas;
                laundry.Satuan = data.Satuan;
                db.Entry(laundry).State = EntityState.Modified;
                db.SaveChanges();
            }
            else
            {
                Spa spa = new Spa();
                spa.Alat = data.Peralatan;
                spa.Durasi = data.Durasi;
                db.Entry(spa).State = EntityState.Modified;
                db.SaveChanges();
            }
        }

        public void delete(int ID,int TipeLayananID)
        {
            if (TipeLayananID == 1)
            {
                Laundry data = db.Laundry.Find(ID);
                db.Laundry.Remove(data);
                db.SaveChanges();
            }
            else
            {
                Spa data = db.Spa.Find(ID);
                db.Spa.Remove(data);
                db.SaveChanges();
            }

            Layanan layanan = db.Layanan.Find(ID);
            db.Layanan.Remove(layanan);
            db.SaveChanges();
        }
    }
}