/*
	Author: Steven Liu
	
	This javascript-only page contains the logic of UI for the program.
	It will respond to DOM events such as button clicks.  It will also
	use AJAX to request data from the server and inserting any valid 
	data received from the server into the DOM of “jeopardy.php”.
*/


$(document).ready(function(){
	/*
		Handles click event for "setup" button
		
		Gets user specified setup and subject values,
		Sends the values to server program "setup" via AJAX to process,
		Inserts good data return from server onto DOM
	*/
	$("input.setup").on("click", function(){
		$.ajax({
			url			: "jeopardy.api.php",	//server program url
			data		: {		//values to send to server
				"program"	: "setup",
				"stdnum"	: $("input[name='stdnum']").val(),		//setup number,
				"subject"	: $("input[name='subject']").val()		//subject string
				},
			dataType	: "json",		//server response data type
			success		: function(json){	//callback for successful AJAX return
				if(json && json["status"]=="error"){	//server sent error
					alert(json["message"]);
					return;
					}
				else if(json && json["status"]=="ok"){	//server status ok
					//insert data into DOM
					
					//insert Watson's confidence
					$("input[name='watsonconfidence']").val(json["data"]["confidence"]);	
					
					//parse setup values string into array
					var setup_values	= json["data"]["setup"].split(",");
					
					//insert stake values
					$("input[name='watson']").val(setup_values[0]);
					$("input[name='opponent1']").val(setup_values[1]);
					$("input[name='opponent2']").val(setup_values[2]);
					
					//insert bet values
					$("input[name='opponent1bet']").val(setup_values[3]);
					$("input[name='opponent2bet']").val(setup_values[4]);
					
					//insert confidence values
					$("input[name='opponent1confidence']").val(setup_values[5]);
					$("input[name='opponent2confidence']").val(setup_values[6]);
					}
				}
			});
		});
		
	});