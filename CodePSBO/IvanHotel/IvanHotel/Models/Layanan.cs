//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated from a template.
//
//     Manual changes to this file may cause unexpected behavior in your application.
//     Manual changes to this file will be overwritten if the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace IvanHotel.Models
{
    using System;
    using System.Collections.Generic;
    
    public partial class Layanan
    {
        public Layanan()
        {
            this.TransaksiLayanan = new HashSet<TransaksiLayanan>();
        }
    
        public int ID { get; set; }
        public Nullable<int> TipeLayananID { get; set; }
        public string Nama { get; set; }
    
        public virtual Laundry Laundry { get; set; }
        public virtual Spa Spa { get; set; }
        public virtual TipeLayanan TipeLayanan { get; set; }
        public virtual ICollection<TransaksiLayanan> TransaksiLayanan { get; set; }
    }
}
