<?php
/*
	Author: Steven Liu
	
	This page serves as the brain of the Jeopardy program.  It will
	have access to the setup and confidence data necessary to setup 
	the game.  It also houses the logic that will calculate Watson’s
	bet value.  Finally this page will perform calculation of right/wrong 
	for each player and sum up their final scores.
*/

try
{
	//the server program to run must be specified
	if(!isset($_GET["program"]) || !is_string($_GET["program"]))
	{
		throw new Exception("Program value not set or not a string");
	}
		
	switch($_GET["program"])
	{
		/*
			Setup program gets the values needed to setup a game of 
			final Jeopardy by looking at the files "program3data.txt"
			and "confidence.txt"
			
			Will return to browser the found setup values or
			an error message if any errors were encountered
		*/
		case "setup":
			//types of data needed
				//filenames, line #, and error message on each type
			$setups	= array(
				"setup"			=> array(
					"filename"		=> "program3data.txt",
					//setup's line is just stdnum
					"line"			=> intval($_GET["stdnum"]),		
					"error_msg"		=> "Standard amounts run number"					
				),
				"confidence"	=> array(
					"filename"		=> "confidence.txt",
					//confidence's line # is length of subject without whitespace
					"line"			=> strlen(preg_replace("/\s/", "", $_GET["subject"])),
					"error_msg"		=> "Confidence"
				)
			);
			
			//open file and save data for each file type
			foreach($setups as $type=>$setup)
			{
				//attempt to open file / check for file existance
				$file_lines	= file($setup["filename"]);
				//file() returns:
					//on successful file open, an array of all lines in file
					//on unsuccessful file open, boolean false
				if($file_lines===false)
				{
					throw new Exception("File ".$setup["filename"]." cannot be opened");
				}
				
				//go to specified line # in the file
				$line_num	= $setup["line"]-1;	//-1 because array index starts from 0
				if(isset($file_lines[$line_num]))	//line exists in file
				{
					//remove \r and \n from line
					$file_lines[$line_num]	= preg_replace(array("/\n/", "/\r/"), "", $file_lines[$line_num]);
					//save the contents of the line
					$return_data[$type]	= $file_lines[$line_num];	
				}
				else //line doesn't exist (out of range)
				{
					throw new Exception($setup["error_msg"]." out of range");
				}
			}
			break;
		default:
			throw new Exception("Invalid program");
			break;
	}
	
	//return the data back to browser
	echo json_encode(array(
		"status"	=> "ok",
		"data"		=> $return_data
	));
}
catch(Exception $e)
{
	//return error status and error message to browser
	echo json_encode(array(
		"status"	=> "error",
		"message"	=> $e->getMessage()
	));
}




?>