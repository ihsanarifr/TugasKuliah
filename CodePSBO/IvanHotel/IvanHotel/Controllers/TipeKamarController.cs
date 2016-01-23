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
    public class TipeKamarController : Controller
    {
        private DBReservasiHotelEntities db = new DBReservasiHotelEntities();

        // GET: /TipeKamar/
        public ActionResult Index()
        {
            ViewBag.Menu = 9;
            return View(db.TipeKamar.ToList());
        }

        // GET: /TipeKamar/Details/5
        public ActionResult Details(int? id)
        {
            ViewBag.Menu = 9;
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            TipeKamar tipekamar = db.TipeKamar.Find(id);
            if (tipekamar == null)
            {
                return HttpNotFound();
            }
            return View(tipekamar);
        }

        // GET: /TipeKamar/Create
        public ActionResult Create()
        {
            ViewBag.Menu = 9;
            return View();
        }

        // POST: /TipeKamar/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include="ID,Nama")] TipeKamar tipekamar)
        {
            if (ModelState.IsValid)
            {
                db.TipeKamar.Add(tipekamar);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            return View(tipekamar);
        }

        // GET: /TipeKamar/Edit/5
        public ActionResult Edit(int? id)
        {
            ViewBag.Menu = 9;
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            TipeKamar tipekamar = db.TipeKamar.Find(id);
            if (tipekamar == null)
            {
                return HttpNotFound();
            }
            return View(tipekamar);
        }

        // POST: /TipeKamar/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include="ID,Nama")] TipeKamar tipekamar)
        {
            if (ModelState.IsValid)
            {
                db.Entry(tipekamar).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            return View(tipekamar);
        }

        // GET: /TipeKamar/Delete/5
        public ActionResult Delete(int? id)
        {
            ViewBag.Menu = 9;
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            TipeKamar tipekamar = db.TipeKamar.Find(id);
            if (tipekamar == null)
            {
                return HttpNotFound();
            }
            return View(tipekamar);
        }

        // POST: /TipeKamar/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            ViewBag.Menu = 9;
            TipeKamar tipekamar = db.TipeKamar.Find(id);
            db.TipeKamar.Remove(tipekamar);
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
