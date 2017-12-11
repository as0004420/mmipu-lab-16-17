#include"7188.h"

void displayletters(char *c);
void displayletter(char c, int pos);

void main(void)
{
  int type;
  int ver;
  char c[5] = {' ', ' ', ' ', ' ', 'h'}, 
		c1[5] = {' ', ' ', ' ', 'h', 'e'}, 
		c2[5] = {' ', ' ', 'h', 'e', 'l'},
		c3[5] = {' ', 'h', 'e', 'l', 'l'},
		c4[5] = {'h', 'e', 'l', 'l', 'o'},
		c5[5] = {'e', 'l', 'l', 'o', ' '},
		c6[5] = {'l', 'l', 'o', ' ', 'w'},
		c7[5] = {'l', 'o', ' ', 'w', 'o'},
		c8[5] = {'o', ' ', 'w', 'o', 'r'},
		c9[5] = {' ', 'w', 'o', 'r', 'l'},
		c10[5] = {'w', 'o', 'r', 'l', 'd'},
		c11[5] = {'o', 'r', 'l', 'd', ' '},
		c12[5] = {'r', 'l', 'd', ' ', ' '},
		c13[5] = {'l', 'd', ' ', ' ', ' '},
		c14[5] = {'d', ' ', ' ', ' ', ' '};
		c15[5] = {' ', ' ', ' ', ' ', ' '};
  type = Is7188();		/*detect the current operation system*/
   if(type)
     {
     ver=GetLibVersion();
     Print("Hello 7188x! (Flash memory is %d K)\n\r",type);
     Print("Library version is %d.%02d",ver>>8,ver&0xff);
     }
   else
     {
     Print("Hello PC!, this program is not run under I-7188.");
     return;
     }	  
	  Init5DigitLed();	  
	  displayletters(c);
	  displayletters(c1);
	  displayletters(c2);
	  displayletters(c3);
	  displayletters(c4);
	  displayletters(c5);
	  displayletters(c6);
	  displayletters(c7);
	  displayletters(c8);
	  displayletters(c9);
	  displayletters(c10);
	  displayletters(c11);
	  displayletters(c12);
	  displayletters(c13);
	  displayletters(c14);
	  displayletters(c15);
}

void displayletters(char *c)
{
	int i;
	for (i=1; i<6; i++)
	{
		displayletter(i, c[i-1]);
	}
	DelayMs(500);
}

void displayletter(int pos, char c)
{
	switch(c)
	{
		case 'h':
		{
			Show5DigitLedSeg(pos,55);	//h
			break;
		}
		case 'e':
		{
			Show5DigitLed(pos,14);	//e
			break;
		}
		case 'l':
		{
			Show5DigitLedSeg(pos,14);	//l
			break;
		}
		case 'o':
		{
			Show5DigitLedSeg(pos,126);	//o
			break;
		}
		case 'w':
		{
			Show5DigitLedSeg(pos,30);	//w, first half
			break;
		}
		case 'y':
		{
			Show5DigitLedSeg(pos,30);	//w, second half
			break;
		}
		case 'r':
		{
			Show5DigitLedSeg(pos,70);	//r
			break;
		}
		case 'd':
		{
			Show5DigitLed(pos,13);	//d
			break;
		}
		case ' ':
		{
			Show5DigitLed(pos,16);	//	space  
			break;
		}
	}
}
