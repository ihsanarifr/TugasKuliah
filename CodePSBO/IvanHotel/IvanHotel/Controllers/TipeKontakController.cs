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
    public class TipeKontakController : Controller
    {
        private DBReservasiHotelEntities db = new DBReservasiHotelEntities();

        // GET: /TipeKontak/
        public ActionResult Index()
        {
            ViewBag.Menu =10;
            return View(db.TipeKontak.ToList());
        }

        // GET: /TipeKontak/Details/5
        public ActionResult Details(int? id)
        {
            ViewBag.Menu =10;
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            TipeKontak tipekontak = db.TipeKontak.Find(id);
            if (tipekontak == null)
            {
                return HttpNotFound();
            }
            return View(tipekontak);
        }

        // GET: /TipeKontak/Create
        public ActionResult Create()
        {
            ViewBag.Menu =10;
            return View();
        }

        // POST: /TipeKontak/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include="ID,Nama")] TipeKontak tipekontak)
        {
            if (ModelState.IsValid)
            {
                db.TipeKontak.Add(tipekontak);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            return View(tipekontak);
        }

        // GET: /TipeKontak/Edit/5
        public ActionResult Edit(int? id)
        {
            ViewBag.Menu =10;
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            TipeKontak tipekontak = db.TipeKontak.Find(id);
            if (tipekontak == null)
            {
                return HttpNotFound();
            }
            return View(tipekontak);
        }

        // POST: /TipeKontak/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include="ID,Nama")] TipeKontak tipekontak)
        {
            if (ModelState.IsValid)
            {
                db.Entry(tipekontak).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            return View(tipekontak);
        }

        // GET: /TipeKontak/Delete/5
        public ActionResult Delete(int? id)
        {
            ViewBag.Menu =10;
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            TipeKontak tipekontak = db.TipeKontak.Find(id);
            if (tipekontak == null)
            {
                return HttpNotFound();
            }
            return View(tipekontak);
        }

        // POST: /TipeKontak/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            TipeKontak tipekontak = db.TipeKontak.Find(id);
            db.TipeKontak.Remove(tipekontak);
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
