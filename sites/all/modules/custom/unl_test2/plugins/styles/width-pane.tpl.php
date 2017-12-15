<?php

/**
 * @file
 * Display content with red and blue borders.
 *
 * - $content: The content of the box.
 * - $display: The display of the box.
 * - $pane: The pane of the box.
 */
?>

<?php if (!empty($content)): ?>
    <div class="width-pane">
      <?php print $content; ?>
    </div>
<?php endif; ?>
