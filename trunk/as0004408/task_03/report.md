
### Лабораторная работа № 3
## PAC 7188D 
----------
 Выполнил:<br>
 Студент ФЭИС <br>
 3 курса <br>
 Группы АС-44 <br>
 Гришан О.А. <br>
 Проверил: <br>
 Иванюк Д.С. <br> 

------------
### **Цель работы**: <br>
Изучить документацию (..\ICP CON\*). Собрать программу "Hello world" для данного контроллера используя Turbo C. 
Продемонстрировать работу программы преподавателю.

**Ход работы:** <br>
*1. Код работы на яп С++*
```
#include "I7188.H"
int main()
{
	while (1)
	{
	Show5DigitLedSeg (1,55);
	Show5DigitLedSeg (2,79);
	Show5DigitLedSeg (3,14);
	Show5DigitLedSeg (4,14);
	Show5DigitLedSeg (5,126);
	DelayMs(250);
	Show5DigitLedSeg (1,28);
	Show5DigitLedSeg (2,29);
	Show5DigitLedSeg (3,5);
	Show5DigitLedSeg (4,48);
	Show5DigitLedSeg (5,61);
	DelayMs(250);
	Show5DigitLedSeg (1,127);
	Show5DigitLedSeg (2,0);
	Show5DigitLedSeg (3,0);
	Show5DigitLedSeg (4,0);
	Show5DigitLedSeg (5,0);
	DelayMs(100);
	Show5DigitLedSeg (1,0);
	Show5DigitLedSeg (2,126);
	Show5DigitLedSeg (3,0);
	Show5DigitLedSeg (4,127);
	Show5DigitLedSeg (5,0);
	DelayMs(100);
	Show5DigitLedSeg (1,0);
	Show5DigitLedSeg (2,0);
	Show5DigitLedSeg (3,0);
	Show5DigitLedSeg (4,0);
	Show5DigitLedSeg (5,126);
	DelayMs(100);
	}
}
```
-------------------
**Отличия:**<br>
Программа поочередно выводит на дисплей два слова "HELLO" и "world", затем пробегает строка (0 8).

-------

**Вывод:**<br>
В ходе выполнения лабораторной работы собрали программу "Hello world" для контроллерa.
