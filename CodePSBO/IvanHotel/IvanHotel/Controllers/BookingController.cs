using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using IvanHotel.Models;
using IvanHotel.BussinessModels;
using IvanHotel.ViewModels;

namespace IvanHotel.Controllers
{
    public class BookingController : Controller
    {
        private DBReservasiHotelEntities db = new DBReservasiHotelEntities();

        // GET: /Booking/
        public ActionResult Index()
        {
            var tamu = db.Tamu.Include(t => t.JenisKelamin).Include(t => t.TipeIdentitas);
            BookingBM data = new BookingBM();
            ViewBag.TipeIdentitasID = new SelectList(db.TipeIdentitas, "ID", "Nama");
            ViewBag.JenisKelaminID = new SelectList(db.JenisKelamin, "ID", "Nama");
            //ViewBag.Kecamatan = new SelectList(db.Kecamatan, "ID", "Nama");
            ////ViewBag.KabupatenKota = new SelectList(db.KabupatenKota, "ID", "Nama");
            //ViewBag.TipeKamar = data.listKamar();
            ViewBag.TipeKamar = new SelectList(db.TipeKamar, "ID", "Nama");
            ViewBag.InfoKamar = data.listKamar();
            TempData["status"] = "false";
            //TempData["pesan"] = "Data Pemesanan Anda sudah terdaftar. Rincian konfirmasi sudah dikirim melalui nomor Handphone";
            return View(tamu.ToList());
        }
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Index([Bind(Include = "ID,Nama,NomorIdentitas,TipeIdentitasID,JenisKelaminID")] Tamu tamu)
        {

            if (ModelState.IsValid)
            {
                BookingBM data = new BookingBM();
                db.Tamu.Add(tamu);
                db.SaveChanges();

                BookingVM viewbooking = new BookingVM();
                // untuk tabel kontak
                viewbooking.Kontak1 = Int32.Parse(Request["phone"].ToString());
                viewbooking.TamuID = db.Tamu.Max(x=>x.ID);
                viewbooking.TipeKontakID = 2;

                // untuk tabel alamat
                viewbooking.Alamat1 = Request["alamat"].ToString();
                viewbooking.KabupatenKotaID = 0;
                viewbooking.KecamatanID = 0;
                
                // untuk tabel transaksi tamu langsung di BM
                // untuk tabel transaksi kamar
                viewbooking.KamarID = Request["TipeKamar"].ToString();
                viewbooking.CheckIn = Request["checkin"].ToString();
                viewbooking.CheckOut = Request["checkout"].ToString();

                data.Create(viewbooking);
                TempData["status"] = "false";
                TempData["pesan"] = "Data Pemesanan Anda sudah terdaftar. Rincian konfirmasi sudah dikirim melalui nomor Handphone";
                ViewBag.Message = "";
                return RedirectToAction("Selesai");
            }

            TempData["status"] = "true";
            TempData["pesan"] = "Silahkan isi data dengan benar";

            ViewBag.TipeIdentitasID = new SelectList(db.TipeIdentitas, "ID", "Nama");
            ViewBag.JenisKelaminID = new SelectList(db.JenisKelamin, "ID", "Nama");
            //ViewBag.Kecamatan = new SelectList(db.Kecamatan, "ID", "Nama");
            //ViewBag.KabupatenKota = new SelectList(db.KabupatenKota, "ID", "Nama");
            ViewBag.TipeKamar = new SelectList(db.TipeKamar, "ID", "Nama");
            return View(tamu);
        }

        public ActionResult Selesai()
        {
            return View();
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                db.Dispose();
            }
            base.Dispose(disposing);
        }
    }
}
