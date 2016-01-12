using System.Web;
using System.Web.Optimization;

namespace MvcMovie
{
    public class BundleConfig
    {
        // For more information on bundling, visit http://go.microsoft.com/fwlink/?LinkId=301862
        public static void RegisterBundles(BundleCollection bundles)
        {
            bundles.Add(new ScriptBundle("~/bundles/jquery").Include(
                        "~/Scripts/jquery-{version}.js"));

            bundles.Add(new ScriptBundle("~/bundles/jqueryval").Include(
                        "~/Scripts/jquery.validate*"));

            // Use the development version of Modernizr to develop with and learn from. Then, when you're
            // ready for production, use the build tool at http://modernizr.com to pick only the tests you need.
            bundles.Add(new ScriptBundle("~/bundles/modernizr").Include(
                        "~/Scripts/modernizr-*"));

            bundles.Add(new ScriptBundle("~/bundles/bootstrap").Include(
                      "~/Scripts/bootstrap.js",
                      "~/Scripts/respond.js"));

            bundles.Add(new StyleBundle("~/Content/css").Include(
                      "~/Content/bootstrap.css",
                      "~/Content/site.css"));
            bundles.Add(new StyleBundle("~/Content/front").Include(
                "~/Content/Front/bootstrap.css",
                "~/Content/Front/jquery-ui.css",
                "~/Content/Front/owl.carousel.css",
                "~/Content/Front/style.css"));
            bundles.Add(new ScriptBundle("~/bundles/front").Include(
                "~/Scripts/Front/jquery-min.js",
                "~/Scripts/Front/jquery.flexisel.js",
                "~/Scripts/Front/jquery.ui.js",
                "~/Scripts/Front/owl.carousel.js",
                "~/Scripts/Front/responsiveslides.min.js"
                ));
            bundles.Add(new StyleBundle("~/Content/back").Include(
                "~/Content/Back/bootstrap.css",
                "~/Content/Back/AdminLTE.css",
                "~/Content/Back/skins/skin-green.css",
                "~/plugins/iCheck/flat/green.css",
                "~/plugins/datepicker/datepicker3.css",
                "~/plugins/bootstrap-wysihtml5/bootstrap3-wysihtml5.min.css",
                "~/plugins/datatables/dataTables.bootstrap.css"
                ));
            bundles.Add(new ScriptBundle("~/bundles/back").Include(
                "~/plugins/jQuery/jQuery-2.1.3.min.js",
                "~/Scripts/bootstrap.min.js",
                "~/plugins/datepicker/bootstrap-datepicker.js",
                "~/plugins/bootstrap-wysihtml5/bootstrap3-wysihtml5.all.min.js",
                "~/Scripts/Back/app.min.js",
                "~/Scripts/Back/highcharts.js",
                "~/Scripts/Back/exporting.js",
                "~/plugins/datatables/jquery.dataTables.min.js",
                "~/plugins/datatables/dataTables.bootstrap.min.js"
                ));
        }
    }
}
