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
    public class LayananController : Controller
    {
        private DBReservasiHotelEntities db = new DBReservasiHotelEntities();
        LayananBM layananbm = new LayananBM();

        // GET: /Layanan/
        public ActionResult Index()
        {
            ViewBag.Menu = 2;
            ViewBag.ListLayanan = layananbm.Layanan();
            return View();
        }

        // GET: /Layanan/Details/5
        public ActionResult Details(int? id)
        {
            ViewBag.Menu = 2;
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            LayananVM layanan = layananbm.details((int)id);
            if (layanan == null)
            {
                return HttpNotFound();
            }
            return View(layanan);
        }

        // GET: /Layanan/Create
        public ActionResult CreateSpa()
        {
            ViewBag.Menu = 2;
            return View();
        }

        // POST: /Layanan/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult CreateSpa([Bind(Include="Nama,Durasi,Peralatan,Harga,Deskripsi")] LayananVM layanan)
        {
            ViewBag.Menu = 2;
            if (ModelState.IsValid)
            {
                layanan.TipeLayananID = 2;
                layananbm.create(layanan);
                return RedirectToAction("Index");
            }
            return View(layanan);
        }
        // GET: /Layanan/Create
        public ActionResult CreateLaundry()
        {
            ViewBag.Menu = 2;
            return View();
        }

        // POST: /Layanan/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult CreateLaundry([Bind(Include = "Nama,Satuan,Kualitas,Harga,Deskripsi")] LayananVM layanan)
        {
            ViewBag.Menu = 2;
            if (ModelState.IsValid)
            {
                layanan.TipeLayananID = 1;
                layananbm.create(layanan);
                return RedirectToAction("Index");
            }
            return View(layanan);
        }
        
        // GET: /Layanan/Edit/5
        public ActionResult EditSpa(int? id)
        {
            ViewBag.Menu = 2;
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            LayananVM data = layananbm.details((int)id);
            if (data == null)
            {
                return HttpNotFound();
            }
            return View(data);
        }

        // POST: /Layanan/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult EditSpa([Bind(Include = "Nama,Durasi,Peralatan,Harga,Deskripsi")] LayananVM layanan)
        {
            ViewBag.Menu = 2;
            if (ModelState.IsValid)
            {
                layananbm.update(layanan);
                return RedirectToAction("Index");
            }
            return View(layanan);
        }
        
        // GET: /Layanan/Edit/5
        public ActionResult EditLaundry(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            LayananVM data = layananbm.details((int)id);
            if (data == null)
            {
                return HttpNotFound();
            }
            return View(data);
        }

        // POST: /Layanan/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult EditLaundry([Bind(Include = "Nama,Satuan,Kualitas,Harga,Deskripsi")] LayananVM layanan)
        {
            ViewBag.Menu = 2;
            if (ModelState.IsValid)
            {
                layananbm.update(layanan);
                return RedirectToAction("Index");
            }
            return View(layanan);
        }

        // GET: /Layanan/Delete/5
        public ActionResult Delete(int? id)
        {
            ViewBag.Menu = 2;
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            LayananVM layanan = layananbm.details((int)id);
            if (layanan == null)
            {
                return HttpNotFound();
            }
            return View(layanan);
        }

        // POST: /Layanan/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            ViewBag.Menu = 2;
            LayananVM data = layananbm.details(id);
            layananbm.delete(id,(int)data.TipeLayananID);
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
