$(document).ready(function () {
  $("#whichtrain_blue").parent().hide()
  $("#whichtrain_orange").parent().hide();
  $("#whichtrain_red").parent().hide();
  $(".whichtrain_submit").hide();

  
  $("#mbta-whichline").change(function() {
    $line = $(this).val();
    $div = "#whichtrain_" + $line;
    $("#whichtrain_blue").parent().hide()
    $("#whichtrain_orange").parent().hide();
    $("#whichtrain_red").parent().hide();
    $($div).parent().show();
    $($div).change(function() {
      $stop = $(this).val();
      window.location.href = "/mbta/wheresmytrain?stop=" + $stop + '&line=' + $line;  
    });
  });
  

});