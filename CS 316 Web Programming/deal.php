<?php
// deal.sphp Cut the cards PHP example
// Author: Paul Piwowarski (modified from web example)
// Date: 10/2010
// Executed from deal.html
// Randomly shuffles a deck of cards
// "cuts" the deck from user input, displays resulting cards
// uncut and cut

// Get post data via $_POST hash by name
$starting_point = $_POST['startpoint'];
// verify card supplied is between 1-52
// Set up suits and card value arrays
$suit = array("clubs","diamonds","hearts","spades");
$number = array("Ace","2","3","4","5","6","7",
          "8","9","10","Jack","Queen","King");
$cards = array();   // cards put in here
// Create $cards array of unshuffled deck from these arrays
$i=0;   // card number 0-51 index into $cards
// for the four suits
for ($j=0;$j<4;$j++) {
        // for the 13 cards in each suit
	for ($k=0;$k<13;$k++) {
                // put the card in $cards array: card value and suit
		$cards[$i]= $number[$k]." of ".$suit[$j];
		$i++;
	}
}
// Random number seed based on time of day
srand(time());
// Create array of randomly distributed cards, put in $deck
// example from web: inefficient but works
for($i = 0; $i <= 52; $i++)    
{
	$count = count($cards);   // count of cards in $cards
	$random = (rand()%$count);  // random number 0-51
        // if card picked before (is blank)
	if($cards[$random] == "")
	{
		$i++;// try again
	}
	else 
	{
 	        // found a card not picked before
        	$deck[$i] = $cards[$random];  // put in $deck array
		$cards[$random] = "";       // remove from $cards array
	}
}
// This shows how to randomly select starting point
//srand(time());
//$starting_point = (rand()%51);
print("Starting point for cut cards is: $starting_point<p>");
// Arrays indexed from 0, so subtract 1 from starting point supplied by user
$starting_point--;
// Display shuffled cards uncut and from starting point
for ($index = 0; $index < 52; $index++)
{
	// If reached end of deck, start at beginning
        if ($starting_point == 52) { 
           $starting_point = 0;
        }
	$cardnumber = $index+1;  
        print("Card number: <strong>$cardnumber</strong> ");
	print("Uncut card: <strong>$deck[$index]</strong> ");
	print("Cut card: <strong>$deck[$starting_point]</strong><br>");
	$starting_point++;
}
?>

