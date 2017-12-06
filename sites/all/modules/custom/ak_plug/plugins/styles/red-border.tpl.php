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
    <div class="blue-border">
      <?php print $item; ?>
    </div>
<?php endforeach; ?>
</div>
