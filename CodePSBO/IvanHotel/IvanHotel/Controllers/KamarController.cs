using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using IvanHotel.Models;
//using IvanHotel.ViewModels;
//using IvanHotel.BussinessModels;

namespace IvanHotel.Controllers
{
    public class KamarController : Controller
    {
        private DBReservasiHotelEntities db = new DBReservasiHotelEntities();

        // GET: /Kamar/
        public ActionResult Index()
        {
            ViewBag.Menu = 1;
            var kamar = db.Kamar.Include(k => k.TipeKamar);
            return View(kamar.ToList());
        }

        // GET: /Kamar/Details/5
        public ActionResult Details(int? id)
        {
            ViewBag.Menu = 1;
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Kamar kamar = db.Kamar.Find(id);
            ViewBag.ListFasilitas = db.FasilitasKamar.Where(x => x.KamarID == id).Select(x => x.Fasilitas.Nama);
            if (kamar == null)
            {
                return HttpNotFound();
            }
            return View(kamar);
        }

        // GET: /Kamar/Create
        public ActionResult Create()
        {
            ViewBag.Menu = 1;
            ViewBag.TipeKamarID = new SelectList(db.TipeKamar, "ID", "Nama");
            ViewBag.Fasilitas = db.Fasilitas.ToList();
            return View();
        }

        // POST: /Kamar/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include="ID,NomorKamar,Kapasitas,Status,TipeKamarID,Lantai")] Kamar kamar)
        {
            ViewBag.Menu = 1;
            if (ModelState.IsValid)
            {
                kamar.HargaWeekDay = Int32.Parse(Request["hargaweekday"].ToString());
                kamar.HargaWeekEnd = Int32.Parse(Request["hargaweekday"].ToString());
                db.Kamar.Add(kamar);
                db.SaveChanges();

                String[] fasilitasid = Request["fasilitasid"].Split(',');
                FasilitasKamar data = new FasilitasKamar();
                for(int i=0;i<fasilitasid.Length;i++){
                    data.KamarID = db.Kamar.Max(item => item.ID);
                    data.FasilitasID = Int32.Parse(fasilitasid[i]);
                    db.FasilitasKamar.Add(data);
                    db.SaveChanges();
                }
                return RedirectToAction("Index");
            }
            ViewBag.Fasilitas = db.Fasilitas.ToList();
            ViewBag.TipeKamarID = new SelectList(db.TipeKamar, "ID", "Nama", kamar.TipeKamarID);
            return View(kamar);
        }

        // GET: /Kamar/Edit/5
        public ActionResult Edit(int? id)
        {
            ViewBag.Menu = 1;
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Kamar kamar = db.Kamar.Find(id);
            if (kamar == null)
            {
                return HttpNotFound();
            }
            ViewBag.TipeKamarID = new SelectList(db.TipeKamar, "ID", "Nama", kamar.TipeKamarID);
            return View(kamar);
        }

        // POST: /Kamar/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include="ID,NomorKamar,Kapasitas,Status,TipeKamarID,Lantai")] Kamar kamar)
        {
            ViewBag.Menu = 1;
            if (ModelState.IsValid)
            {
                db.Entry(kamar).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            ViewBag.TipeKamarID = new SelectList(db.TipeKamar, "ID", "Nama", kamar.TipeKamarID);
            ViewBag.Fasilitas = db.Fasilitas.ToList();
            return View(kamar);
        }

        // GET: /Kamar/Delete/5
        public ActionResult Delete(int? id)
        {
            ViewBag.Menu = 1;
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Kamar kamar = db.Kamar.Find(id);
            if (kamar == null)
            {
                return HttpNotFound();
            }
            return View(kamar);
        }

        // POST: /Kamar/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            ViewBag.Menu = 1;
            Kamar kamar = db.Kamar.Find(id);

            int count = db.FasilitasKamar.Where(x => x.KamarID == id).Count();
            if (count != 0)
            {
                for (int i = 0; i < count; i++)
                {
                    FasilitasKamar fasil = db.FasilitasKamar.Where(x => x.KamarID == id).First();
                    db.FasilitasKamar.Remove(fasil);
                    db.SaveChanges();
                }
            }
            db.Kamar.Remove(kamar);
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
