<!DOCTYPE html>
<meta http-equiv="Content-Type" content="text/html;charset=utf-8" />
<html>
<body>

<?php
echo "Test for PHP-DAO insert method";
$db = new Counter;
$db->open();
$row = new CRow;
echo "<br> PASSED: new CRow";
$row->addColumn("name", "test");
echo "<br> PASSED: row->addColumn";
$db->insert("person", $row);
echo "<br> PASSED: row->insert";

$rows = new CRows;
echo "<br> PASSED: CRows";
echo "<br> size:";
print $rows->size();
echo "<br> PASSED: rows->size()";

$rows->pushBack($row);
echo "<br> PASSED: rows->pushBack()";
echo "<br> size:";
print $rows->size();

echo "<br> Read table data ...";

$rowsRes = new CRows;
$db->read("person", $rowsRes);
$it = $rowsRes->createIterator();
for($it->first(); !$it->isDone(); $it->next()) {
    $row_it = $it->currentItem();
    echo "<br> ";
    print $row_it->getColumnValue("id");
    echo " |";
    print $row_it->getColumnValue("name");
}

echo "<br>=== TEST PASSED ===";

?>

</body>
</html>
