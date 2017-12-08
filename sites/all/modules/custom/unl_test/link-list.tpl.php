<?php

/**
 * @file
 * Display content with list of links.
 *
 * - $variables: The content.
 */
?>

<?php if (!empty($variables['content'])): ?>
  <div class="link-list">
      <?php foreach ($variables['content'] as $key => $item): ?>
        <?php print (l($item['link_title'], $item['link_path'])) . '<br>'?>
      <?php endforeach;?>
  </div>
<?php endif; ?>

<?php print ($variables['ajax_link']) ?>
