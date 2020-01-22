<!DOCTYPE html>
<html>
<head>
<title>Table with database</title>
<style>
table {
border-collapse: collapse;
width: 100%;
color: #588c7e;
font-family: monospace;
font-size: 20px;
text-align: left;
}
th {
background-color: #588c7e;
color: white;
}
tr:nth-child(even) {background-color: #f2f2f2}
</style>
</head>
<body>
<table>
<tr>
<th>Id</th>
<th>Temperature</th>
<th>Humidity</th>
<th>Date</th>
</tr>
<?php
$conn = mysqli_connect("localhost", "root", "", "temp");
// Check connection
if ($conn->connect_error) {
die("Connection failed: " . $conn->connect_error);
}
$sql = "SELECT id, temperature, humidity, date FROM dht11";
$result = $conn->query($sql);
if ($result->num_rows > 0) {
// output data of each row
while($row = $result->fetch_assoc()) {
echo "<tr><td>" . $row["id"]. "</td><td>" . $row["temperature"]. "</td><td>" . $row["humidity"]. "</td><td>" . $row["date"]. "</td></tr>";}
echo "</table>";
} else { echo "0 results"; }
$conn->close();
?>
</table>
</body>
</html>