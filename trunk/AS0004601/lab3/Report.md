#### BSTU
 #### Department of Informatics and Applied Mathematics
 #### Laboratory work N3
 #### Topic: PAC 7188D.
 #### Student: Borisiuk E.R.
 #### Checked By: Ivaniuk D.S.
 
 ##### Goal: 
 Using Turbo C, create a "Hello world" program for controller i7188D. The program shows HELLO and then WORLD symbol by symbol.
 
 ### Code:
 	
	 	#include<stdlib.h>
	 	#include<stdio.h>
	 	#include<conio.h>
	 	#include<string.h>
	 	#include<i7188.h>
	 	#include<dos.h>
	 	void main(void)
	 	{
	 		int type; 
	 		int ver;  
	 		int arr[9] = {
	 			0x37,  //H 0
	 			0x4F, // E 1
	 			0xE,  // L 2
	 			0x7E, // O 3
	 			0x1E, //1 part of W 4
	 			0x3C, //2 part of W 5
	 			0x77, // R 6 
	 			0x7A, // D 7
	 			16 // spacebar 8};
	 		type = Is7188();
	 		if(type){
	 		     ver=GetLibVersion();
	     		 Print("Hello 7188x! (Flash memory is %d K)\n\r",type);
	    		 Print("Library version is %d.%02d",ver>>8,ver&0xff);}
	 		else
	 		{
	 		  Print("Hello PC!, this program is not run under I-7188.");
	 			return;
	 		}	
	 		Init5DigitLed();	
	 			//shows HELLO
	 			Show5DigitLedSeg(1,arr[0]); 
	 			Show5DigitLedSeg(2,arr[1]);
	 			Show5DigitLedSeg(3,arr[2]);	
	 			Show5DigitLedSeg(4,arr[2]);	
	 			Show5DigitLedSeg(5,arr[3]);
	 			DelayMs(1000);	
	 			//shows ###W(W consists of two parts)
	 			Show5DigitLedSeg(1,arr[8]);
	 			Show5DigitLedSeg(2,arr[8]);
	 			Show5DigitLedSeg(3,arr[8]);	
	 			Show5DigitLedSeg(4,arr[4]);	
	 			Show5DigitLedSeg(5,arr[5]);
	 			DelayMs(300);	
	 			//shows ##WO
	 			Show5DigitLedSeg(1,arr[8]);
	 			Show5DigitLedSeg(2,arr[8]);
	 			Show5DigitLedSeg(3,arr[4]);	
	 			Show5DigitLedSeg(4,arr[5]);	
	 			Show5DigitLedSeg(5,arr[3]);
	 			DelayMs(300);	
	 			//shows #WOR
	 			Show5DigitLedSeg(1,arr[8]);
	 			Show5DigitLedSeg(2,arr[4]);
	 			Show5DigitLedSeg(3,arr[5]);	
	 			Show5DigitLedSeg(4,arr[3]);	
	 			Show5DigitLedSeg(5,arr[6]);
	 			DelayMs(300);	
	 			//shows WORL
	 			Show5DigitLedSeg(1,arr[4]);
	 			Show5DigitLedSeg(2,arr[5]);
	 			Show5DigitLedSeg(3,arr[3]);	
	 			Show5DigitLedSeg(4,arr[6]);	
	 			Show5DigitLedSeg(5,arr[2]);
	 			DelayMs(300);	
	 			//shows JORLD(J as the second part of W) 
	 			Show5DigitLedSeg(1,arr[5]);
	 			Show5DigitLedSeg(2,arr[3]);
	 			Show5DigitLedSeg(3,arr[6]);	
	 			Show5DigitLedSeg(4,arr[2]);	
	 			Show5DigitLedSeg(5,arr[7]);
	 		}
	 	}
	 
 ### Output:
 The result of this program was shown during the laboratory work.
