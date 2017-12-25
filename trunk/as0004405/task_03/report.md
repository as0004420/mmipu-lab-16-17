#### Лабораторная работа №3
#### Тема: Контроллер I7188
 Выполнил:<br>
 Студент ФЭИС<br>
 3 курса<br>
 Группы АС-44<br>
 Вакула М.Н.<br>
 Проверил:<br>
 Иванюк Д.С.
  
#### Цель: 
  Собрать программу "Hello world" для данного контроллера используя Turbo C. Продемонстрировать работу программы преподавателю.<br>
  #### Код C программы:
```C
#include "I7188.H"

int main(void)
{
	 while(1)
	{
		Show5DigitLedSeg(1,23);  	//H
		Show5DigitLedSeg(2,79);		//E
		Show5DigitLedSeg(3,48);		//l
		Show5DigitLedSeg(4,48);		//l
		Show5DigitLedSeg(5,61);		//o
DelayMs(700);
		Show5DigitLedSeg(1,28);		//u
		Show5DigitLedSeg(2,29);		//o
		Show5DigitLedSeg(3,5);		//r
		Show5DigitLedSeg(4,48);		//l
		Show5DigitLedSeg(5,61);		//d
DelayMs(700);
		Show5DigitLedSeg(1,28);		
		Show5DigitLedSeg(2,0);		
		Show5DigitLedSeg(3,5);		
		Show5DigitLedSeg(4,48);		
		Show5DigitLedSeg(5,61);		
DelayMs(400);

		Show5DigitLedSeg(1,28);		
		Show5DigitLedSeg(2,0);		
		Show5DigitLedSeg(3,5);		
		Show5DigitLedSeg(4,0);		
		Show5DigitLedSeg(5,61);		
DelayMs(400);
		Show5DigitLedSeg(1,28);		
		Show5DigitLedSeg(2,0);		
		Show5DigitLedSeg(3,5);		
		Show5DigitLedSeg(4,0);		
		Show5DigitLedSeg(5,0);		
DelayMs(400);
		Show5DigitLedSeg(1,0);		
		Show5DigitLedSeg(2,0);		
		Show5DigitLedSeg(3,5);		
		Show5DigitLedSeg(4,0);		
		Show5DigitLedSeg(5,0);		
DelayMs(400);
		Show5DigitLedSeg(1,0);		
		Show5DigitLedSeg(2,0);		
		Show5DigitLedSeg(3,0);		
		Show5DigitLedSeg(4,0);		
		Show5DigitLedSeg(5,0);		
DelayMs(400);
	}
}

```
#### Результат ввыполнения программы: <br>
![Result](https://github.com/idzm/mmipu-lab-16-17/tree/master/trunk/as0004405/task_03/report.mkv)
<br>
#### Вывод: 
Написал программу, по результатам которой на дисплее контроллера i7188 появилась надпись "Hello world". Познакомился с программированием для контроллеров на TurboC++.
