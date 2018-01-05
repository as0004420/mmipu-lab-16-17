# Лабораторная работа №3 
### Тема: «PAC 7188D»
----------
**Выполнил:** <br>                                                                                                                       Студент 3 курса <br> 
Факультета ЭИС <br>                                                                                                                                      Группы АС-44  <br> 
Герасимчук А.А.<br> 
**Проверил:**<br> 
Иванюк Д.С. 

----------
***Цель:***
Изучить документацию (..\ICP CON\*). Собрать программу "Hello world" для данного контроллера используя Turbo C. Продемонстрировать работу программы преподавателю.

### *Код программы на С:*
```
#include "I7188.H"

int main()
{
   while(1)
  {
DelayMs(100);
    Show5DigitLedSeg(1,55);
    Show5DigitLedSeg(2,0);
    Show5DigitLedSeg(3,0);
    Show5DigitLedSeg(4,0);
    Show5DigitLedSeg(5,0);
DelayMs(100);
    Show5DigitLedSeg(1,0);
    Show5DigitLedSeg(2,0);
    Show5DigitLedSeg(3,0);
    Show5DigitLedSeg(4,0);
    Show5DigitLedSeg(5,0);
DelayMs(100);
    Show5DigitLedSeg(1,55);
    Show5DigitLedSeg(2,79);
    Show5DigitLedSeg(3,0);
    Show5DigitLedSeg(4,0);
    Show5DigitLedSeg(5,0);
DelayMs(100);
    Show5DigitLedSeg(1,55);
    Show5DigitLedSeg(2,0);
    Show5DigitLedSeg(3,0);
    Show5DigitLedSeg(4,0);
    Show5DigitLedSeg(5,0);
DelayMs(100);
    Show5DigitLedSeg(1,55);
    Show5DigitLedSeg(2,79);
    Show5DigitLedSeg(3,14);
    Show5DigitLedSeg(4,0);
    Show5DigitLedSeg(5,0);
DelayMs(100);
    Show5DigitLedSeg(1,55);
    Show5DigitLedSeg(2,79);
    Show5DigitLedSeg(3,0);
    Show5DigitLedSeg(4,0);
    Show5DigitLedSeg(5,0);
DelayMs(100);
    Show5DigitLedSeg(1,55);
    Show5DigitLedSeg(2,79);
    Show5DigitLedSeg(3,14);
    Show5DigitLedSeg(4,14);
    Show5DigitLedSeg(5,0);  
DelayMs(100);
    Show5DigitLedSeg(1,55);
    Show5DigitLedSeg(2,79);
    Show5DigitLedSeg(3,14);
    Show5DigitLedSeg(4,0);
    Show5DigitLedSeg(5,0);
DelayMs(100);
    Show5DigitLedSeg(1,55);
    Show5DigitLedSeg(2,79);
    Show5DigitLedSeg(3,14);
    Show5DigitLedSeg(4,14);
    Show5DigitLedSeg(5,126);
DelayMs(1000);
    Show5DigitLedSeg(1,0);
    Show5DigitLedSeg(2,0);
    Show5DigitLedSeg(3,0);
    Show5DigitLedSeg(4,0);
    Show5DigitLedSeg(5,0);
DelayMs(1000);
    Show5DigitLedSeg(1,55);
    Show5DigitLedSeg(2,79);
    Show5DigitLedSeg(3,14);
    Show5DigitLedSeg(4,14);
    Show5DigitLedSeg(5,126);
DelayMs(1000);
    Show5DigitLedSeg(1,0);
    Show5DigitLedSeg(2,0);
    Show5DigitLedSeg(3,0);
    Show5DigitLedSeg(4,0);
    Show5DigitLedSeg(5,0);
DelayMs(1000);
    Show5DigitLedSeg(1,55);
    Show5DigitLedSeg(2,79);
    Show5DigitLedSeg(3,14);
    Show5DigitLedSeg(4,14);
    Show5DigitLedSeg(5,126);
DelayMs(1000);
    Show5DigitLedSeg(1,0);
    Show5DigitLedSeg(2,0);
    Show5DigitLedSeg(3,0);
    Show5DigitLedSeg(4,0);
    Show5DigitLedSeg(5,0);
DelayMs(10000);
    Show5DigitLedSeg(1,62);
    Show5DigitLedSeg(2,126);
    Show5DigitLedSeg(3,0);
    Show5DigitLedSeg(4,0);
    Show5DigitLedSeg(5,0);
DelayMs(100);
    Show5DigitLedSeg(1,0);
    Show5DigitLedSeg(2,0);
    Show5DigitLedSeg(3,0);
    Show5DigitLedSeg(4,0);
    Show5DigitLedSeg(5,0);
DelayMs(100);
    Show5DigitLedSeg(1,62);
    Show5DigitLedSeg(2,126);
    Show5DigitLedSeg(3,5);
    Show5DigitLedSeg(3,0);
    Show5DigitLedSeg(4,0);
    Show5DigitLedSeg(5,0);
DelayMs(100);
    Show5DigitLedSeg(1,62);
    Show5DigitLedSeg(2,126);
    Show5DigitLedSeg(3,0);
    Show5DigitLedSeg(4,0);
    Show5DigitLedSeg(5,0);
DelayMs(100);
    Show5DigitLedSeg(1,62);
    Show5DigitLedSeg(2,126);
    Show5DigitLedSeg(3,5);
    Show5DigitLedSeg(4,14);
    Show5DigitLedSeg(5,0);
DelayMs(100);
    Show5DigitLedSeg(1,62);
    Show5DigitLedSeg(2,126);
    Show5DigitLedSeg(3,5);
    Show5DigitLedSeg(4,0);
    Show5DigitLedSeg(5,0);
DelayMs(100);
    Show5DigitLedSeg(1,62);
    Show5DigitLedSeg(2,126);
    Show5DigitLedSeg(3,5);
    Show5DigitLedSeg(4,14);
    Show5DigitLedSeg(5,61);
DelayMs(1000);
    Show5DigitLedSeg(1,0);
    Show5DigitLedSeg(2,0);
    Show5DigitLedSeg(3,0);
    Show5DigitLedSeg(4,0);
    Show5DigitLedSeg(5,0);
DelayMs(1000);
    Show5DigitLedSeg(1,62);
    Show5DigitLedSeg(2,126);
    Show5DigitLedSeg(3,5);
    Show5DigitLedSeg(4,14);
    Show5DigitLedSeg(5,61);
DelayMs(1000);
    Show5DigitLedSeg(1,0);
    Show5DigitLedSeg(2,0);
    Show5DigitLedSeg(3,0);
    Show5DigitLedSeg(4,0);
    Show5DigitLedSeg(5,0);
DelayMs(1000);
    Show5DigitLedSeg(1,62);
    Show5DigitLedSeg(2,126);
    Show5DigitLedSeg(3,5);
    Show5DigitLedSeg(4,14);
    Show5DigitLedSeg(5,61);
DelayMs(1000);
    Show5DigitLedSeg(1,0);
    Show5DigitLedSeg(2,0);
    Show5DigitLedSeg(3,0);
    Show5DigitLedSeg(4,0);
    Show5DigitLedSeg(5,0);
DelayMs(10000);
  }
}
```

### *Результат выполнения данной программы:* <br>
После сборки получается файл с расширением .exe, который нам необходимо поместить в память контроллера и запустить. В результате мы получаем следующее сообщение на дисплее контроллера: [видео с результатом работы](https://github.com/idzm/mmipu-lab-16-17/blob/master/trunk/as0004407/task_03/mutevideo1514107362051.mp4)

-------------
### Вывод: 
В результате выполнения данной лабораторной работы, была реализована программа, выводящая на дисплей контроллера фразу Hello world. Вывод фразы осуществляется согласно следующему алгоритму: последняя буква исчезает на 100 мс и появляется вместе со следующей буквой, через 100 мс процесс повторяется. При заполнении всего циферблата, всё слово мигает 2 раза с задержкой в 1000 мс, далее записывается следующее слово.
