using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using IvanHotel.Models;

namespace IvanHotel.Controllers
{
    public class KabupatenKotaController : Controller
    {
        private DBReservasiHotelEntities db = new DBReservasiHotelEntities();

        // GET: /KabupatenKota/
        public ActionResult Index()
        {
            ViewBag.Menu = 6;
            var kabupatenkota = db.KabupatenKota.Include(k => k.Provinsi);
            return View(kabupatenkota.ToList());
        }

        // GET: /KabupatenKota/Details/5
        public ActionResult Details(int? id)
        {
            ViewBag.Menu = 4;
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            KabupatenKota kabupatenkota = db.KabupatenKota.Find(id);
            if (kabupatenkota == null)
            {
                return HttpNotFound();
            }
            return View(kabupatenkota);
        }

        // GET: /KabupatenKota/Create
        public ActionResult Create()
        {
            ViewBag.Menu = 4;
            ViewBag.ProvinsiID = new SelectList(db.Provinsi, "ID", "Nama");
            return View();
        }

        // POST: /KabupatenKota/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include="ID,Nama,ProvinsiID")] KabupatenKota kabupatenkota)
        {
            if (ModelState.IsValid)
            {
                db.KabupatenKota.Add(kabupatenkota);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            ViewBag.ProvinsiID = new SelectList(db.Provinsi, "ID", "Nama", kabupatenkota.ProvinsiID);
            return View(kabupatenkota);
        }

        // GET: /KabupatenKota/Edit/5
        public ActionResult Edit(int? id)
        {
            ViewBag.Menu = 4;
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            KabupatenKota kabupatenkota = db.KabupatenKota.Find(id);
            if (kabupatenkota == null)
            {
                return HttpNotFound();
            }
            ViewBag.ProvinsiID = new SelectList(db.Provinsi, "ID", "Nama", kabupatenkota.ProvinsiID);
            return View(kabupatenkota);
        }

        // POST: /KabupatenKota/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include="ID,Nama,ProvinsiID")] KabupatenKota kabupatenkota)
        {
            ViewBag.Menu = 4;
            if (ModelState.IsValid)
            {
                db.Entry(kabupatenkota).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            ViewBag.ProvinsiID = new SelectList(db.Provinsi, "ID", "Nama", kabupatenkota.ProvinsiID);
            return View(kabupatenkota);
        }

        // GET: /KabupatenKota/Delete/5
        public ActionResult Delete(int? id)
        {
            ViewBag.Menu = 4;
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            KabupatenKota kabupatenkota = db.KabupatenKota.Find(id);
            if (kabupatenkota == null)
            {
                return HttpNotFound();
            }
            return View(kabupatenkota);
        }

        // POST: /KabupatenKota/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            KabupatenKota kabupatenkota = db.KabupatenKota.Find(id);
            db.KabupatenKota.Remove(kabupatenkota);
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
