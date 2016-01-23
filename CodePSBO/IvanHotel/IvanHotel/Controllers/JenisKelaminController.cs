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
    public class JenisKelaminController : Controller
    {
        private DBReservasiHotelEntities db = new DBReservasiHotelEntities();

        // GET: /Default1/
        public ActionResult Index()
        {
            ViewBag.Menu = 4;
            return View(db.JenisKelamin.ToList());
        }

        // GET: /Default1/Details/5
        public ActionResult Details(int? id)
        {
            ViewBag.Menu = 4;
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            JenisKelamin jeniskelamin = db.JenisKelamin.Find(id);
            if (jeniskelamin == null)
            {
                return HttpNotFound();
            }
            return View(jeniskelamin);
        }

        // GET: /Default1/Create
        public ActionResult Create()
        {
            ViewBag.Menu = 4;
            return View();
        }

        // POST: /Default1/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include="ID,Nama")] JenisKelamin jeniskelamin)
        {
            ViewBag.Menu = 4;
            if (ModelState.IsValid)
            {
                db.JenisKelamin.Add(jeniskelamin);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            return View(jeniskelamin);
        }

        // GET: /Default1/Edit/5
        public ActionResult Edit(int? id)
        {
            ViewBag.Menu = 4;
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            JenisKelamin jeniskelamin = db.JenisKelamin.Find(id);
            if (jeniskelamin == null)
            {
                return HttpNotFound();
            }
            return View(jeniskelamin);
        }

        // POST: /Default1/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include="ID,Nama")] JenisKelamin jeniskelamin)
        {
            if (ModelState.IsValid)
            {
                db.Entry(jeniskelamin).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            return View(jeniskelamin);
        }

        // GET: /Default1/Delete/5
        public ActionResult Delete(int? id)
        {
            ViewBag.Menu = 4;
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            JenisKelamin jeniskelamin = db.JenisKelamin.Find(id);
            if (jeniskelamin == null)
            {
                return HttpNotFound();
            }
            return View(jeniskelamin);
        }

        // POST: /Default1/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            JenisKelamin jeniskelamin = db.JenisKelamin.Find(id);
            db.JenisKelamin.Remove(jeniskelamin);
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
