<?php
//array to hold data to update
$values	= array(
	"common1"	=> "hello",
	"common2"	=> "world"
);

//set mid level values // OVERWRITES common!
$mid_values	= array(
	"common1"	=> "BAH",
	"mid1"		=> "bye"
);
$values	= array_merge($values, $mid_values);

//set admin specific values
$admin_values	= array(
	"admin1"	=> "special",
	"admin2"	=> "commands"
);
$values	= array_merge($values, $admin_values);

//update/insert values
echo "<pre>";
print_r( $values );
echo "<pre/>";


$fields	= array(
	"common1",
	"common2",
	"common3"
);

if(true)
{
	$fields	= array_merge($fields, array("admin1", "admin2"));
}

echo "<pre>";
print_r( $fields );
echo "<pre/>";
?>
