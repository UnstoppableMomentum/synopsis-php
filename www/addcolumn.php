<!DOCTYPE html>
<meta http-equiv="Content-Type" content="text/html;charset=utf-8" />
<html>
<body>

<?php
echo "Test for PHP-DAO CRow::AddColumn method";
$row = new CRow;
echo "<br> PASSED: new CRow";

$row->addColumn("id", 1);
echo "<br> row->addColumn('id', 1)";

$row->addColumn("name", "test");
echo "<br> row->addColumn('name', 'test')";

$row->addColumn("val", 0.5);
echo "<br> row->addColumn('val', 0.5)";


echo "<br>=== TEST PASSED ===";

?>

</body>
</html>
