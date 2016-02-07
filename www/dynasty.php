<!DOCTYPE html>
<meta http-equiv="Content-Type" content="text/html;charset=utf-8" />
<html>
<body>

Dynasty

<?php
$db = new Counter;
$db->open();
$rows = new CRows;
$db->read("person", $rows);
$it = $rows->createIterator();
for($it->first(); !$it->isDone(); $it->next()) {
    $row_it = $it->currentItem();
    echo "<br> ";
    print $row_it->getColumnValue("id");
    echo " |";
    print $row_it->getColumnValue("name");
}


?>

</body>
</html>
