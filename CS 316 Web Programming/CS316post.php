<?php
 print "<h2>";
  print "get post name/value pairs<p>";
  foreach ($_POST as $n => $v) { 
	print "<p>";
	print "name:  $n<br>";
	print  "value: $v<br>";
  } 
 print "</h2>";
 ?> 