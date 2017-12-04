<?php

/**
 * @file
 * Template for a 3 column * 3 line panel layout.
 */
?>

<div class="panel-display panel-3col-33 clearfix"
  <?php if (!empty($css_id)) {print "id=\"$css_id\"";
  } ?>>

    <div class="panel-panel panel-col-first line-1">
        <div class="inside"><?php print $content['11']; ?></div>
    </div>
    <div class="panel-panel panel-col line-1">
        <div class="inside"><?php print $content['12']; ?></div>
    </div>
    <div class="panel-panel panel-col-last line-1">
        <div class="inside"><?php print $content['13']; ?></div>
    </div>

    <div class="panel-panel panel-col-first line-2">
        <div class="inside"><?php print $content['21']; ?></div>
    </div>
    <div class="panel-panel panel-col line-2">
        <div class="inside"><?php print $content['22']; ?></div>
    </div>
    <div class="panel-panel panel-col-last line-2">
        <div class="inside"><?php print $content['23']; ?></div>
    </div>

    <div class="panel-panel panel-col-first line-3">
        <div class="inside"><?php print $content['31']; ?></div>
    </div>
    <div class="panel-panel panel-col line-3">
        <div class="inside"><?php print $content['32']; ?></div>
    </div>
    <div class="panel-panel panel-col-last line-3">
        <div class="inside"><?php print $content['33']; ?></div>
    </div>

</div>
