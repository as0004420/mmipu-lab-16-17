#### BSTU
#### Department of Informatics and Applied Mathematics
#### Laboratory work N3
#### Theme: Controller 
#### Studen: Tikhonov D. N.
#### Checked By: Ivaniuk D.S.

### Goal
Create Hello world programm for controller PAC 7188D using Turbo C. This program must move the word hello on the display. That word at first moves to the right and then to the left then to the right again etc.

###Code
    #include<stdlib.h>
    #include<stdio.h>
    #include<conio.h>
    #include<dos.h>
    #include<string.h>
    #include <i7188.h>
    void showSymbols(char *c,int pos);
    void showSymbol(char c, int pos);
    void startShow(char* c,int len);
    void main(void)
    {
      int type;
      int ver;
      char str[16]="     hello     ";
      type = Is7188();      /*detect the current operation system*/
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
          startShow(str,15);
         }
    void showSymbols(char *c, int pos)//pos starts from 0 -- hello  with pos 0 will show hello on controller
    {
        int i;
        for (i=1; i<6; i++)
        {
            displayletter(i, c[pos + i - 1]);
        }
        DelayMs(200);
    }
    void startShow(char *c, int len){//length of string
        int dir = 0;//0 - to right 1 - to left
        int i = 0;
        while(1>0){
            if(dir == 0)
            {
                for(i = 0; i < len - 5; i++)
                {
                    showSymbols(c,i);
                }
                dir = 1;
            }
            if(dir == 1)
            {
                for(i = len - 5; i > - 1;i--)
                {
                    showSymbols(c,i);
                }
                dir = 0;
             }
        }
    }
    //_._._hello_._._
    void showSymbol(char c, int pos)
    {
        switch(c)
        {
            case 'h':
            {
                Show5DigitLedSeg(pos,55);   //h
                break;
            }
            case 'e':
            {
                Show5DigitLed(pos,14);  //e
                break;
            }
            case 'l':
            {
                Show5DigitLedSeg(pos,14);   //l
                break;
            }
            case 'o':
            {
                Show5DigitLedSeg(pos,126);  //o
                break;
            }
            case ' ':
            {
                Show5DigitLed(pos,16);  //space
                break;
            }
        }
    }
### Conclusion: 
I understood how to work with controller and understood basics of creating programs for it and how to launch them on it.