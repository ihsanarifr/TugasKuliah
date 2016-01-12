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
            ViewBag.TipeIdentitasID = new SelectList(db.TipeIdentitas, "ID", "Nama");
            ViewBag.JenisKelaminID = new SelectList(db.JenisKelamin, "ID", "Nama");
            //ViewBag.Kecamatan = new SelectList(db.Kecamatan, "ID", "Nama");
            ////ViewBag.KabupatenKota = new SelectList(db.KabupatenKota, "ID", "Nama");
            ViewBag.TipeKamar = new SelectList(db.TipeKamar, "ID", "Nama");
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
                return RedirectToAction("Index");
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

        // GET: /Booking/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Tamu tamu = db.Tamu.Find(id);
            if (tamu == null)
            {
                return HttpNotFound();
            }
            return View(tamu);
        }

        // GET: /Booking/Create
        public ActionResult Create()
        {
            ViewBag.JenisKelaminID = new SelectList(db.JenisKelamin, "ID", "Nama");
            ViewBag.TipeIdentitasID = new SelectList(db.TipeIdentitas, "ID", "Nama");
            return View();
        }

        // POST: /Booking/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include="ID,Nama,NomorIdentitas,TipeIdentitasID,JenisKelaminID")] Tamu tamu)
        {
            if (ModelState.IsValid)
            {
                db.Tamu.Add(tamu);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            ViewBag.JenisKelaminID = new SelectList(db.JenisKelamin, "ID", "Nama", tamu.JenisKelaminID);
            ViewBag.TipeIdentitasID = new SelectList(db.TipeIdentitas, "ID", "Nama", tamu.TipeIdentitasID);
            return View(tamu);
        }

        // GET: /Booking/Edit/5
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Tamu tamu = db.Tamu.Find(id);
            if (tamu == null)
            {
                return HttpNotFound();
            }
            ViewBag.JenisKelaminID = new SelectList(db.JenisKelamin, "ID", "Nama", tamu.JenisKelaminID);
            ViewBag.TipeIdentitasID = new SelectList(db.TipeIdentitas, "ID", "Nama", tamu.TipeIdentitasID);
            return View(tamu);
        }

        // POST: /Booking/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include="ID,Nama,NomorIdentitas,TipeIdentitasID,JenisKelaminID")] Tamu tamu)
        {
            if (ModelState.IsValid)
            {
                db.Entry(tamu).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            ViewBag.JenisKelaminID = new SelectList(db.JenisKelamin, "ID", "Nama", tamu.JenisKelaminID);
            ViewBag.TipeIdentitasID = new SelectList(db.TipeIdentitas, "ID", "Nama", tamu.TipeIdentitasID);
            return View(tamu);
        }

        // GET: /Booking/Delete/5
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Tamu tamu = db.Tamu.Find(id);
            if (tamu == null)
            {
                return HttpNotFound();
            }
            return View(tamu);
        }

        // POST: /Booking/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            Tamu tamu = db.Tamu.Find(id);
            db.Tamu.Remove(tamu);
            db.SaveChanges();
            return RedirectToAction("Index");
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
