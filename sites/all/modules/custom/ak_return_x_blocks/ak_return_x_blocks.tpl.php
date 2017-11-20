<?php

/**
 * @file
 * My template.
 */
?>

<div class="ak_return_x_blocks-template-wrapped">
    <div class="body">
      <?php if ($number == NULL): ?>
          Блоков нет.
      <?php endif ?>
      <?php print $block;?>
    </div>
</div>
