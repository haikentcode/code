<?php

echo number_format(disk_free_space ('/')/disk_total_space('/') * 100, 2).'%';


?>
