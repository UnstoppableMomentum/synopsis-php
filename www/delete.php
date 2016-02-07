<!DOCTYPE html>
<meta http-equiv="Content-Type" content="text/html;charset=utf-8" />
<html>
<body>

<?php
echo "Test for PHP-DAO Delete method";
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

echo "<br> PASSED: db->read('person', rowsRes);";
echo "<br> Testing Delete method";

$rowDel = new CRow;
echo "<br> PASSED: new CRowDel";
$rowDel->addColumn("name", "test");
echo "<br> PASSED: new rowDel>addColumn('name', 'test');";
$db->Delete("person", $rowDel);
echo "<br> PASSED: db->Delete('person', rowDel);";
echo "<br> Read table data ...";

$rowsRes2 = new CRows;
$db->read("person", $rowsRes2);
$it2 = $rowsRes2->createIterator();
for($it2->first(); !$it2->isDone(); $it2->next()) {
    $row_it2 = $it2->currentItem();
    echo "<br> ";
    print $row_it2->getColumnValue("id");
    echo " |";
    print $row_it2->getColumnValue("name");
}

echo "<br>=== TEST PASSED ===";

?>

</body>
</html>
