using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace MvcMovie.Controllers
{
    public class HomeController : Controller
    {
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult Fasilitas()
        {
            ViewBag.Message = "Your application description page.";

            return View();
        }

        public ActionResult Restoran()
        {
            ViewBag.Message = "Your contact page.";

            return View();
        }
        public ActionResult Room()
        {
            ViewBag.Message = "Your contact page.";

            return View();
        }
        public ActionResult Booking()
        {
            ViewBag.Message = "Your contact page.";

            return View();
        }
        public ActionResult Kontak()
        {
            ViewBag.Message = "Your contact page.";

            return View();
        }
    }
}