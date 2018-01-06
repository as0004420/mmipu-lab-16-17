Лабораторная работа № 1
«Моделирование объекта управления»
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
Моделирование объекта управления, температура которого описывается уравнением y(τ+1)=a(T)y(τ)+b(T)u(τ). <br>
### **Задание**: <br>
На языке C++ реализовать программу,<br>
моделирующую рассмотренный выше объект управления, использую эти модели. <br> 
Использовать ООП, должно быть не менее трех классов (один из них абстрактный) и наследование. <br>

Линейная модель: y(t+1)=0.988y(t)+0.232u(t) <br>
Нелинейная модель: y(t+1)=0.9y(t)-0.001y(t-1)^2+u(t)+sin⁡(u(t-1)) <br>

-------------

**Ход работы:** <br>
*1. Код работы на яп С++*

```
#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;
int u[9];
double y[9];

class model {
public:
model(void) {

for (int t = 0; t <= 9; t++) {
u[t] = t;
}
}
//объявление виртуальной функции, общей для линейного и нелинейного классов
virtual void Abstr(void) = 0;

~model() {
cout « endl;
}
};
//класс линейной функции
class lin : public model {
public:
lin(void) {
cout « "y(t+1) = 0.988y(t) + 0.232u(t):" « endl;
}
void Abstr(void) {
cout « "u(t) | y(t)" « endl;
//начальное значение температуры на входе = 0
y[0] = 0;
//расчет последующих значений температуры по уравнению
for (int t = 0; t <= 9; t++) {
y[t + 1] = 0.988*y[t] + 0.232*u[t];
cout « u[t] « " | ";
cout « y[t] « endl;
}
}
~lin() {} 
};
// класс нелинейной функции
class unlin : public model {
public:
unlin(void) {
cout « "y(t+1) = 0.9*y(t) - 0.001*y^2(t-1) + u(t) + sin(u(t-1)):" « endl;
}
void Abstr(void) {
cout « "u(t) | y(t)" « endl;
y[0] = 0; y[1] = 0; // начальное значение температуры на входе = 0
for (int t = 0; t <= 9; t++) {
u[t] = t;
} cout « y[0] « " | " « u[0] « endl;
for (int t = 1; t <= 9; t++) { // расчет последующих значений температуры по уравнению
y[t + 1] = 0.9*y[t] + 0.232*y[t - 1] * y[t - 1] + u[t];
cout « u[t] « " | ";
cout « y[t] « endl;
}
}
~unlin() {} 

};

int main() {
//! создание объекта линейного класса
lin l;
l.Abstr();
//! создание объекта нелинейного класса
unlin n;
n.Abstr();
return 0;
}
```
**Результат работы программы:**
![Result](https://github.com/idzm/mmipu-lab-16-17/blob/master/trunk/as0004408/task_01/result.png) <br>
### *Графики:*
![Linear](https://github.com/idzm/mmipu-lab-16-17/blob/master/trunk/as0004407/task_01/linear.png) 
![Nolinear](https://github.com/idzm/mmipu-lab-16-17/blob/master/trunk/as0004407/task_01/nolinear.png)

*2. Построение графиков в программе matlab:*

Линейная модель:<br>

![](linear.png)

Нелинейная модель:<br>

![](nolinear.png)

**Вывод:** <br>
В ходе лабораторной работы на языке C++ реализовал программу,<br>
моделирующую рассмотренный выше объект управления.<br>
Построил графики используя программу matlab.

