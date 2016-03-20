$(document).ready(function(){
    $(document.body).bind('hidden.bs.modal', function () {
      $('#myModal').removeData('bs.modal')
    });
});

$(".alert1").alert();
window.setTimeout(function() { $(".alert1").alert('close'); }, 2000);



