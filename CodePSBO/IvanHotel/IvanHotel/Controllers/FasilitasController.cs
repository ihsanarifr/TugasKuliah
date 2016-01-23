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
    public class FasilitasController : Controller
    {
        private DBReservasiHotelEntities db = new DBReservasiHotelEntities();

        // GET: /Fasilitas/
        public ActionResult Index()
        {
            ViewBag.Menu = 5;
            return View(db.Fasilitas.ToList());
        }

        // GET: /Fasilitas/Details/5
        public ActionResult Details(int? id)
        {
            ViewBag.Menu = 5;
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Fasilitas fasilitas = db.Fasilitas.Find(id);
            if (fasilitas == null)
            {
                return HttpNotFound();
            }
            return View(fasilitas);
        }

        // GET: /Fasilitas/Create
        public ActionResult Create()
        {

            ViewBag.Menu = 5;
            return View();
        }

        // POST: /Fasilitas/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include="ID,Nama")] Fasilitas fasilitas)
        {
            ViewBag.Menu = 5;
            if (ModelState.IsValid)
            {
                db.Fasilitas.Add(fasilitas);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            return View(fasilitas);
        }

        // GET: /Fasilitas/Edit/5
        public ActionResult Edit(int? id)
        {
            ViewBag.Menu = 5;
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Fasilitas fasilitas = db.Fasilitas.Find(id);
            if (fasilitas == null)
            {
                return HttpNotFound();
            }
            return View(fasilitas);
        }

        // POST: /Fasilitas/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include="ID,Nama")] Fasilitas fasilitas)
        {
            if (ModelState.IsValid)
            {
                db.Entry(fasilitas).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            return View(fasilitas);
        }

        // GET: /Fasilitas/Delete/5
        public ActionResult Delete(int? id)
        {
            ViewBag.Menu = 5;
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Fasilitas fasilitas = db.Fasilitas.Find(id);
            if (fasilitas == null)
            {
                return HttpNotFound();
            }
            return View(fasilitas);
        }

        // POST: /Fasilitas/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            Fasilitas fasilitas = db.Fasilitas.Find(id);
            db.Fasilitas.Remove(fasilitas);
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
