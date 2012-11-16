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
      <ul>
        <li class="mbta-destination">
          <?php print $k ?>
          <ul>
            <?php foreach ($v as $val): ?>
              <li class="mbta-arrival">
                <?php
                if (floor($val/60) > 0) {
                  print floor($val / 60) . ' minutes ';
                }
                print $val % 60 . " seconds"; ?>
              <?php endforeach; ?>
          </ul>
      </ul>
    <?php endforeach; ?>
  <?php else: ?>
    <p><?php
  print
      t('Sorry.  We are unable to find any arrivals for your stop.');
    ?></p>
  <?php endif; ?>
</div>