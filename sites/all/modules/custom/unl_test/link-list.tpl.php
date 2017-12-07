<?php

/**
 * @file
 * Display content with list of links.
 *
 * - $vars: The content of the box.
 */
?>

<?php if (!empty($variables['content'])): ?>
  <div class="link-list">
      <?php foreach ($variables['content'] as $key => $item): ?>
          <div class="item-link <?php echo $key ?>">
            <?php print (l($item['link_title'], $item['link_path'])) ?>
          </div>
      <?php endforeach;?>
  </div>
<?php endif; ?>

<?php print ($variables['ajax_link']) ?>
