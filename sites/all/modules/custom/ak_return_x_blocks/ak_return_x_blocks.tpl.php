<?php

/**
 * @file
 * My template.
 */
?>

<div class="ak_return_x_blocks-template-wrapped">
    <div class="body">
      <?php if (!$block): ?>
          Блоков нет.
      <?php else:?>
      <?php print $block;?>
      <?php endif;?>
    </div>
</div>
