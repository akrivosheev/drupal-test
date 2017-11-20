<?php

/**
 * @file
 * My template.
 */
?>

<div class="ak_page_5_nodes-template-wrapped">
  <div class="body">
    <?php if(is_array($nodes)):?>
      <?php foreach ($nodes as $node):?>
        <?php echo $node->title . "\n" . format_date($node->created, 'custom', 'Y-m-d H:i:s', 'UTC') . '<br>';?>
      <?php endforeach;?>
    <?php endif;?>
  </div>
</div>
