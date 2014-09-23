<?php
// Get the user name
$name=$_POST["name"];
// Check if a previous cookie exists for this user
// Update or create the cookie for the user
// Put the number of user accesses (not counting this one)
// in $number


if(isset($_COOKIE["Name"]) && is_string($_COOKIE["Name"]) && $name==$_COOKIE["Name"])
{
	$number = intval($_COOKIE["Number"])+1;
}
else //first time
{
	$number = 0;
}

setcookie("Name", $_POST["name"]);
setcookie("Number", $number);

?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" >
<head>
<title>Cookie test</title>
<script language="javascript"  type="text/javascript">
var url = "cs316cookie.php"; // The server-side script
function handleHttpResponse() {
  if (http.readyState == 4) {

}

function getHTTPObject() {
  var xmlhttp;
  // Error handling
  if (!xmlhttp && typeof XMLHttpRequest != 'undefined') {
    try {
      xmlhttp = new XMLHttpRequest();
    } catch (e) {
      xmlhttp = false;
    }
  }
  return xmlhttp;
}
var http = getHTTPObject(); // We create the HTTP Object
</script>
</head>
<body>
<?php
print ("<h1>Hello  $name ");


if ($number == 0) {
	print ("this is your first access today</h1>");
}
else {
	print ("you have accessed this page $number time(s) today</h1>");
}
?>
</body>
</html>


