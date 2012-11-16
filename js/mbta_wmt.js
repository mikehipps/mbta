$(document).ready(function () {
  $("#whichtrain_blue").parent().hide()
  $("#whichtrain_orange").parent().hide();
  $("#whichtrain_red").parent().hide();
  
   $("#mbta-whichline").change(function() {
      $line = $(this).val();
      $div = "#whichtrain_" + $line;
      $("#whichtrain_blue").parent().hide()
      $("#whichtrain_orange").parent().hide();
      $("#whichtrain_red").parent().hide();
      $($div).parent().show();
  })
});