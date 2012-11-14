<?php

/**
 * @file MBTA Where's My Train Template.
 */
?>

<div id="mbta-wmt-title">
  <?php print $title; ?>
</div>
<div id="mbta-wmt-info">
  <?php if ($arrivals) : ?>
    <?php foreach ($arrivals as $k => $v): ?>
      <?php foreach ($v as $val): ?>
        <li class="mbta-arrival">
          <?php print $k . ": " . $val . " seconds" ?>
        </li>
      <?php endforeach;?>
    <?php endforeach;?>
  <div id="mbta-wmt-arrivals">
    <?php print $locations; ?>
  </div>
  <?php else: ?>
    <p><?php print
      t('Sorry.  We are unable to find any arrivals for your stop.');
    ?></p>
  <?php endif; ?>
</div>