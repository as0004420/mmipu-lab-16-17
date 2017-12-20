# Лабораторная работа №3 
## PAC 7188D 


Выполнила:  
студентка 3 курса  
группы АС-44, ФЭИС  
Воронко О. А.  
Проверил:  
Иванюк Д. С.  

*Цель работы:* Изучить документацию (..\ICP CON\*). Собрать программу "Hello world" для данного контроллера используя Turbo C. Продемонстрировать работу программы преподавателю.

*Текст программы:*
```
#include "i7188.h"

int main()
{
        while(1)
	{
    Show5DigitLedSeg(1,55); // H
    Show5DigitLedSeg(2,79); // E
    Show5DigitLedSeg(3,14); // L
    Show5DigitLedSeg(4,14); // L
    Show5DigitLedSeg(5,126); // O
	      DelayMs(1000); // задержка в 1 с 
    Show5DigitLedSeg(1,126); // O
    Show5DigitLedSeg(2,126); // O
    Show5DigitLedSeg(3,126); // O
    Show5DigitLedSeg(4,126); // O
    Show5DigitLedSeg(5,126); // O
	      DelayMs(1000); // задержка в 1 с 
    Show5DigitLedSeg(1,62); // W
    Show5DigitLedSeg(2,126); // O
    Show5DigitLedSeg(3,70); // R
    Show5DigitLedSeg(4,14); // L
    Show5DigitLedSeg(5,61); // D
	      DelayMs(1000); // задержка в 1 с 
	}
}
```

*Отличия:*
Вместо "HELLO WORLD" выводит "HELLO OOOOO WORLD".

*Вывод:* В ходе выполнения лабораторной работы собрали программу "Hello world" для контроллерa.
