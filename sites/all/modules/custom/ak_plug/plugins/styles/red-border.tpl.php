<?php

/**
 * @file
 * Display content with red and blue borders.
 *
 * - $content: The content of the box.
 */
?>
<div class="red-border">
<?php foreach ($content as $item): ?>
      <?php print $item; ?>
<?php endforeach; ?>
</div>
