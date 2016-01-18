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
    public class TransaksiTamuController : Controller
    {
        private DBReservasiHotelEntities db = new DBReservasiHotelEntities();

        // GET: /TransaksiTamu/
        public ActionResult Index()
        {
            TransaksiBM data = new TransaksiBM();
            return View(data.Transaksi());
        }

        public ActionResult Verifikasi(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            TransaksiBM data = new TransaksiBM();
            if (data == null)
            {
                return HttpNotFound();
            }
            else
            {
                data.Verifikasi((int)id);
            }
            return RedirectToAction("index");
        }

        // GET: /TransaksiTamu/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            TransaksiBM transaksi = new TransaksiBM();
            ViewBag.ListTransaksiKamar = transaksi.TransaksiKamar((int)id);
            ViewBag.ListTransaksiLayanan = transaksi.TrasaksiLayanan((int)id);
            return View(transaksi.details(id));
        }

        // GET: /TransaksiTamu/Create
        public ActionResult Create()
        {
            ViewBag.PegawaiID = new SelectList(db.Pegawai, "ID", "NIP");
            ViewBag.TamuID = new SelectList(db.Tamu, "ID", "Nama");
            return View();
        }

        // POST: /TransaksiTamu/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include="ID,PegawaiID,TamuID,TMT,TST")] TransaksiTamu transaksitamu)
        {
            if (ModelState.IsValid)
            {
                db.TransaksiTamu.Add(transaksitamu);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            ViewBag.PegawaiID = new SelectList(db.Pegawai, "ID", "NIP", transaksitamu.PegawaiID);
            ViewBag.TamuID = new SelectList(db.Tamu, "ID", "Nama", transaksitamu.TamuID);
            return View(transaksitamu);
        }

        // GET: /TransaksiTamu/Edit/5
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            TransaksiTamu transaksitamu = db.TransaksiTamu.Find(id);
            if (transaksitamu == null)
            {
                return HttpNotFound();
            }
            ViewBag.PegawaiID = new SelectList(db.Pegawai, "ID", "NIP", transaksitamu.PegawaiID);
            ViewBag.TamuID = new SelectList(db.Tamu, "ID", "Nama", transaksitamu.TamuID);
            return View(transaksitamu);
        }

        // POST: /TransaksiTamu/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include="ID,PegawaiID,TamuID,TMT,TST")] TransaksiTamu transaksitamu)
        {
            if (ModelState.IsValid)
            {
                db.Entry(transaksitamu).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            ViewBag.PegawaiID = new SelectList(db.Pegawai, "ID", "NIP", transaksitamu.PegawaiID);
            ViewBag.TamuID = new SelectList(db.Tamu, "ID", "Nama", transaksitamu.TamuID);
            return View(transaksitamu);
        }

        // GET: /TransaksiTamu/Delete/5
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            TransaksiTamu transaksitamu = db.TransaksiTamu.Find(id);
            if (transaksitamu == null)
            {
                return HttpNotFound();
            }
            return View(transaksitamu);
        }

        // POST: /TransaksiTamu/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            TransaksiTamu transaksitamu = db.TransaksiTamu.Find(id);
            db.TransaksiTamu.Remove(transaksitamu);
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
