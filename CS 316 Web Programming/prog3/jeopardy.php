<?php
/*
	Author: Steven Liu
	
	This page will perform two primary duties.  First is to set cookies
	for the user and count the number of visits for the user.  Second is
	to act as the User Interface (UI) for the user.  The user will 
	interact with this page’s form elements such as input boxes and 
	buttons.  This page will also display the game’s status to the user.
*/


$SECONDS_IN_DAY		= 24*60*60;					//seconds in a day
$EXPIRE_TOMORROW	= time()+$SECONDS_IN_DAY;	//time of cookie expiration = 24hours from now

/*
	Checks cookie for user's previous visits to this web page.
	Modifies visit number that matches his actual visits to page.
	Generate welcome message appropriate to his visit #
*/
if(isset($_COOKIE["user_name"])
	&& is_string($_COOKIE["user_name"]) 
	&& $_POST["user_name"]==$_COOKIE["user_name"])
{
	//user exists, therefore increment user's visit number
	$num_visits = intval($_COOKIE["num_visits"])+1;
	$welcome_message	= "Hello ".$_POST["user_name"]." you have accessed this page ".$num_visits." times today";
}
else
{
	//user's first time visiting, so set visit number to 0
	$num_visits = 0;
	$welcome_message	= "Hello ".$_POST["user_name"]." welcome to my final Jeopardy simulation";
}

//set cookies for next visit
setcookie("user_name", $_POST["user_name"], $EXPIRE_TOMORROW);
setcookie("num_visits", $num_visits, $EXPIRE_TOMORROW);
?>






<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" >
<html>
	<head>
		<title>Final Jeopardy Simulation</title>
		<!-- jQuery library pulled from Google's Hosted Libraries -->
		<script src="//ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js"></script>
		<script src="//ajax.googleapis.com/ajax/libs/jqueryui/1.8.23/jquery-ui.min.js"></script>
		<!-- Steven Liu's program3 javascript code -->
		<script src="jeopardy.js"></script>
		<style>
			table td:first-child
			{
				font-weight: bold;
			}
		</style>
	</head>
	
	<body>
		<h3><?php echo $welcome_message; ?></h3>
		
		<center>
		<h2> Final Jeopardy Simulation by Steven Liu</h2>


		<form name="JForm">

			<table>
				<thead>
					<tr> 
						<th></th>
						<th>Watson</th>
						<th>Opponent 1</th>
						<th>Opponent 2</th>
					</tr>
				</thead>
				<tbody>
					<tr>
						<td>Confidence of correct answer: </td>
						<td><input name="watsonconfidence" size="12" value="0"  type="text"/></td>
						<td><input name="opponent1confidence" size="12" value="0"  type="text"/></td>
						<td><input name="opponent2confidence" size="12" value="0"  type="text"/></td>
					</tr>
					<tr>
						<td>Stake going into final jeopardy</td> 
						<td><input name="watson" size="12" value="0"  type="text"></td>
						<td><input name="opponent1" size="12" value="0"  type="text"></td>
						<td><input name="opponent2" size="12" value="0"  type="text"></td>
					</tr>
					<tr> 
						<td>Amount bet in final jeopardy </td>
						<td><input name="watsonbet" size="12" value="0"  type="text"></td>
						<td><input name="opponent1bet" size="12" value="0"  type="text"></td>
						<td><input name="opponent2bet" size="12" value="0"  type="text"></td>
					</tr>
					<tr> 
						<td>Right/wrong</td>
						<td><input name="watsonanswer" size="12" value=""  type="text"></td>
						<td><input name="opponent1answer" size="12" value=""  type="text"></td>
						<td><input name="opponent2answer" size="12" value=""  type="text"></td>
					</tr>
				</tbody>
			</table>

			<br />

			<strong>Final Jeopardy subject:</strong>
			<input name="subject" size="20" value=""  type="text"> 
			<p />
			
			<table>
				<tr>
					<td>Perform setup with this standard amounts run number:</td>
					<td><input name="stdnum" size="5" value="0"  type="text"></td>
					<td><input value="Setup" class="setup" type="button"></td>
				</tr>
				<tr>
					<td>Run this number of times:</th>
					<td><input name="runnum" size="5" value="0"  type="text"></td>
					<td><input value="Run" class="run" type="button"></td>
				</tr>
			</table>
		
		</form>

		<h2>
			<div id="data"></div>
		</h2>
		</center>
	</body>
</html>
