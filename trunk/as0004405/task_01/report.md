#### Лабораторная работа №1
#### Тема: Моделирование объекта управления
 Выполнил:<br>
 Студент ФЭИС<br>
 3 курса<br>
 Группы АС-44<br>
 Вакула М.Н.<br>
 Проверил:<br>
 Иванюк Д.С.
  
#### Цель: 
  На языке C++ реализовать программу, моделирующую рассмотренный объект управления.  Использовать ООП, должно быть не менее трех классов (один из них абстрактный) и наследование. Сделать проверку в matlab. <br>
  Линейная модель: y(t+1)=0.988y(t)+0.232u(t) <br>
  Нелинейная модель: y(t+1)=0.9y(t)-0.001y(t-1)^2+u(t)+sin⁡(u(t-1)) 
  #### Код C++ программы:
```cpp
#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

class Abstruct
{
public:
	double Y_t_1, U_t_1;
	double Y_t, U_t;
	double Y_t1;
	virtual void Output()
	{
		cout << "Y(t + 1)= " << Y_t1 << endl;
	}
};

class First : public Abstruct
{
public:
	First() : Abstruct()
	{}
		
	void Input1()
	{
		cout << "Enter Yt and Ut: ";
		cin >> Y_t >> U_t;
	}

	double Funct1()
	{
		cout << "Y_t1 = 0.988 * " << Y_t << " + 0.232 * " << U_t << endl;
		Y_t1 = 0.988 * Y_t + 0.232 * U_t;
		return Y_t1;
	}
};
class Second : public Abstruct
{
public:
	Second() : Abstruct()
	{}

	void Input2() {
		cout << "Enter Yt-1 and Ut-1, Yt and Ut: ";
		cin >> Y_t_1 >> U_t_1;
		cin >> Y_t >> U_t;
	}

	double Funct2() {
		cout << "Y_t1 = 0.9 * " << Y_t << " - 0.001 * " << Y_t_1 << "^2 + " << U_t << " + sin(" << U_t_1 << ")" << endl;
		Y_t1 = 0.9 * Y_t - 0.001 * pow(Y_t_1, 2) + U_t + sin(U_t_1);
		return Y_t1;
	}
};

int main()
{
	First function1;
	function1.Input1();
		function1.Funct1();
		function1.Output();
	Second function2;
	function2.Input2();
	function2.Funct2();
	function2.Output();
    return 0;
}

```
#### Результат С++ ввыполнения программы: <br>
![Result](https://github.com/idzm/mmipu-lab-16-17/blob/master/trunk/as0004405/task_01/cpp_RES.png)
<br>
#### Код в MatLab:
Функция выводящая изменения по линейной модели: 
```matlab
 function itr  = LinUrav(Y_t,U_t)
    for i=1:15 
        y_t_plus_1 = 0.988*Y_t + 0.232*U_t;
        itr(i) = y_t_plus_1;
        Y_t = y_t_plus_1;
    end;
end


```
Функция выводящая изменения по нелинейной модели: 
```matlab
function res = NeLinUrav(Y_t,U_t,Y_t_minus_1,U_t_minus_1)
    for i=1:15
        y_t_plus_1 = 0.9*Y_t - 0.001*(Y_t_minus_1)^2 + U_t + sin(U_t_minus_1);
        res(i) = y_t_plus_1;
        Y_t_minus_1 = Y_t;
        Y_t = y_t_plus_1;
    end;
end

```
Результат выполнения функций: <br>
![Result](https://github.com/idzm/mmipu-lab-16-17/blob/master/trunk/as0004405/task_01/matlab.png)
<br>
#### Графики:
![Линейная модель](https://github.com/idzm/mmipu-lab-16-17/blob/master/trunk/as0004405/task_01/plot_l.png)
![Нелинейная модель](https://github.com/idzm/mmipu-lab-16-17/blob/master/trunk/as0004405/task_01/plot_n.png)
#### Вывод: 
Написал программу по результатам которой построил графики линейный и нелинейный для первого и второго уравнений, соответственно. Из графиков видно что линейная функция возрастает до бесконечности, а нелинейная, достигнув некоторого предела, остается на одном уровне.
