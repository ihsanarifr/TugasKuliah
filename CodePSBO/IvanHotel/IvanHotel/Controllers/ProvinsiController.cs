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
    public class ProvinsiController : Controller
    {
        private DBReservasiHotelEntities db = new DBReservasiHotelEntities();

        // GET: /Provinsi/
        public ActionResult Index()
        {
            ViewBag.Menu = 7;
            return View(db.Provinsi.ToList());
        }

        // GET: /Provinsi/Details/5
        public ActionResult Details(int? id)
        {
            ViewBag.Menu = 7;
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Provinsi provinsi = db.Provinsi.Find(id);
            if (provinsi == null)
            {
                return HttpNotFound();
            }
            return View(provinsi);
        }

        // GET: /Provinsi/Create
        public ActionResult Create()
        {
            ViewBag.Menu = 7;
            return View();
        }

        // POST: /Provinsi/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include="ID,Nama")] Provinsi provinsi)
        {
            if (ModelState.IsValid)
            {
                db.Provinsi.Add(provinsi);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            return View(provinsi);
        }

        // GET: /Provinsi/Edit/5
        public ActionResult Edit(int? id)
        {
            ViewBag.Menu = 7;
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Provinsi provinsi = db.Provinsi.Find(id);
            if (provinsi == null)
            {
                return HttpNotFound();
            }
            return View(provinsi);
        }

        // POST: /Provinsi/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include="ID,Nama")] Provinsi provinsi)
        {
            if (ModelState.IsValid)
            {
                db.Entry(provinsi).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            return View(provinsi);
        }

        // GET: /Provinsi/Delete/5
        public ActionResult Delete(int? id)
        {
            ViewBag.Menu = 7;
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Provinsi provinsi = db.Provinsi.Find(id);
            if (provinsi == null)
            {
                return HttpNotFound();
            }
            return View(provinsi);
        }

        // POST: /Provinsi/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            Provinsi provinsi = db.Provinsi.Find(id);
            db.Provinsi.Remove(provinsi);
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
