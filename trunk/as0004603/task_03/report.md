#### BSTU
#### Department of Informatics and Applied Mathematics
#### Laboratory work N3
#### Theme: PAC 7188D.
#### Student: Kapura A.V.
#### Checked By: Ivaniuk D.S.

##### Goal: 
Using Turbo C, create a "Hello world" program for controller i7188D. Output must be produced on the 5 Led Digit Segments Indicators like ticker and the direction from left to right.

### Code:
	
	#include<stdlib.h>
	#include<stdio.h>`
	#include<conio.h>
	#include<dos.h>
	#include<string.h>
	#include<i7188.h>
	
	void main(void)
	{
		int type;
		int ver;
		int hello[20] = {
			16,   //'space'
			16,   //'space'
			16,   //'space'
			16,   //'space'
			0x37, //00110111 H
			0x4F, //01001111 E
			0xE,  //00001110 L
			0xE,  //00001110 L
			0x7E, //01111110 O
			16,   //'space'
			0x1E, //00011110 first part of W
			0x3C, //00011110 second part of W
			0x7E, //01111110 O
			0x77, //01110111 R
			0xE,  //00001110 L
			0x7A, //01111010 D
			16,   //'space'
			16,   //'space'
			16,   //'space'
			16    //'space'		
		};
		type = Is7188();
		if(type){
		}
		else{
			return;
		}	
  
		Init5DigitLed();
			  	
		for (int lngth = 19; lngth >= 4; lngth--){		
			Show5DigitLedSeg(1,hello[lngth-4]);
			Show5DigitLedSeg(2,hello[lngth-3]);
			Show5DigitLedSeg(3,hello[lngth-2]);	
			Show5DigitLedSeg(4,hello[lngth-1);	
			Show5DigitLedSeg(5,hello[lngth]);
			DelayMs(500);	
		}
	}

### Result:
After launching this program on a controller we could see next output on indicators (# - mean empty):
	
	D####                                                                                                                                               
	LD###                                                                                                                      
	RLD##                                                                                                                                            
	ORLD#   
	VORLD                                                                                                                                          
	VVORL                                                                                                                                            
	#VVOR                                                                                                                                            
	O#VVO                                                                                                                                            
	LO#VV                                                                                                                                            
	LLO#V                                                                                                                                            
	ELLO#                                                                                                                                            
	HELLO
	#HELL
  	##HEL
   	###HE
   	####H