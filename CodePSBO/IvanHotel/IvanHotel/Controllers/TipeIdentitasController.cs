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
    public class TipeIdentitasController : Controller
    {
        private DBReservasiHotelEntities db = new DBReservasiHotelEntities();

        // GET: /TipeIdentitas/
        public ActionResult Index()
        {
            ViewBag.Menu = "tipeidentitas";
            return View(db.TipeIdentitas.ToList());
        }

        // GET: /TipeIdentitas/Details/5
        public ActionResult Details(int? id)
        {
            ViewBag.Menu = "tipeidentitas";
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            TipeIdentitas tipeidentitas = db.TipeIdentitas.Find(id);
            if (tipeidentitas == null)
            {
                return HttpNotFound();
            }
            return View(tipeidentitas);
        }

        // GET: /TipeIdentitas/Create
        public ActionResult Create()
        {
            ViewBag.Menu = "tipeidentitas";
            return View();
        }

        // POST: /TipeIdentitas/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include="ID,Nama")] TipeIdentitas tipeidentitas)
        {
            if (ModelState.IsValid)
            {
                db.TipeIdentitas.Add(tipeidentitas);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            return View(tipeidentitas);
        }

        // GET: /TipeIdentitas/Edit/5
        public ActionResult Edit(int? id)
        {
            ViewBag.Menu = "tipeidentitas";
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            TipeIdentitas tipeidentitas = db.TipeIdentitas.Find(id);
            if (tipeidentitas == null)
            {
                return HttpNotFound();
            }
            return View(tipeidentitas);
        }

        // POST: /TipeIdentitas/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include="ID,Nama")] TipeIdentitas tipeidentitas)
        {
            if (ModelState.IsValid)
            {
                db.Entry(tipeidentitas).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            return View(tipeidentitas);
        }

        // GET: /TipeIdentitas/Delete/5
        public ActionResult Delete(int? id)
        {
            ViewBag.Menu = "tipeidentitas";
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            TipeIdentitas tipeidentitas = db.TipeIdentitas.Find(id);
            if (tipeidentitas == null)
            {
                return HttpNotFound();
            }
            return View(tipeidentitas);
        }

        // POST: /TipeIdentitas/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            TipeIdentitas tipeidentitas = db.TipeIdentitas.Find(id);
            db.TipeIdentitas.Remove(tipeidentitas);
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
