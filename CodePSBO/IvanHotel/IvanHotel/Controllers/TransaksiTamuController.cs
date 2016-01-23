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
            ViewBag.Menu = 3;
            TransaksiBM data = new TransaksiBM();
            return View(data.Transaksi());
        }

        public ActionResult Verifikasi(int? id)
        {
            ViewBag.Menu = 3;
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
            ViewBag.Menu = 3;
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            TransaksiBM transaksi = new TransaksiBM();
            ViewBag.ListTransaksiKamar = transaksi.TransaksiKamar((int)id);
            ViewBag.ListTransaksiLayanan = transaksi.TrasaksiLayanan((int)id);
            return View(transaksi.details(id));
        }



        public ActionResult TambahTransaksiLayanan(int id)
        {
            ViewBag.Menu = 3;
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            TransaksiBM data = new TransaksiBM();
            if (data == null)
            {
                return HttpNotFound();
            }
            ViewBag.Layanan = new SelectList(db.Layanan, "ID", "Nama");
            ViewBag.TransaksiID = id;
            return View(data.details(id));
        }

        [HttpPost]
        public ActionResult TambahTransaksiLayanan()
        {
            ViewBag.Menu = 3;
            TransaksiBM data = new TransaksiBM();
            TransaksiVM view = new TransaksiVM();
            if (data == null)
            {
                return HttpNotFound();
            }
            else
            {
                view.LayananID = Request["Layanan"].ToString();
                view.TransaksiID = Int32.Parse(Request["TransaksiID"].ToString());
                data.TambahTransaksiLayanan(view);

            }
            return RedirectToAction("Details", new { id=view.TransaksiID });
        }

        public ActionResult Delete(int id)
        {
            ViewBag.Menu = 3;
            TransaksiLayanan data = db.TransaksiLayanan.Find(id);
            int TransaksiID = (int)data.TransaksiTamuID;

            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            else
            {
                db.TransaksiLayanan.Remove(data);
            }
            db.SaveChanges();
            return RedirectToAction("Details", new { id = TransaksiID });
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
