using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using IvanHotel.Models;

namespace IvanHotel.Controllers
{
    public class HomeController : Controller
    {
        DBReservasiHotelEntities db = new DBReservasiHotelEntities();
        public ActionResult Index()
        {
            ViewBag.Menu = 1;
            ViewBag.TipeKamar = db.TipeKamar.ToList();

            return View();
        }

        public ActionResult About()
        {
            return View();
        }

        public ActionResult Contact()
        {
            ViewBag.Menu = 5;
            return View();
        }

        public ActionResult Fasilitas()
        {
            ViewBag.Menu = 2;
            return View();
        }
        public ActionResult Restoran()
        {
            ViewBag.Menu = 3;
            return View();
        }
        public ActionResult Room()
        {
            ViewBag.Menu = 4;
            return View();
        }
    }
}
