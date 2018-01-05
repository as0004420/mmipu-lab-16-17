# Лабораторная работа №1
### Тема: «Моделирование объекта управления»
----------
**Выполнил:** <br>                                                                                                                       Студент 3 курса <br> 
Факультета ЭИС <br>                                                                                                                                      Группы АС-44  <br> 
Герасимчук А.А.<br> 
**Проверил:**<br> 
Иванюк Д.С.
 
 ----------
### Задание:<br>
**1: y(t+1)=0.988y(t)+0.232u(t)** <br>
**2: y(t+1)=0.9y(t)-0.001y(t-1)^2+u(t)+sin(u(t-1))**<br>
На языке C++ реализовать программу, моделирующую рассмотренный выше объект управления, используя эти модели.  Использовать ООП, должно быть не менее трех классов (один из них абстрактный) и наследование. Сделать проверку в matlab.

  ### *Код программы, выполняющий поставленную задачу (С++):*
```cpp
#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


class AbstrCl_T{
public:
  AbstrCl_T(double Y_t, double U_t){
    y_t = Y_t;
    u_t = U_t;
  }
  virtual void show_decision() = 0;
protected:
  double y_t;
  double u_t;
  double y_t_plus_1;
};

class LinUrav : public AbstrCl_T {
public:
  LinUrav(double Y_t, double U_t) :AbstrCl_T(Y_t, U_t){
    y_t_plus_1 = 0.988*y_t + 0.232*u_t;
  }
  void show_decision(){
    cout << "y(t+1) = " << "[y(t)=" << setprecision(6) << y_t << ",\tu(t)=" << u_t << "] = " << setprecision(6) << y_t_plus_1 << endl;
  }
  double retrn(){
    return y_t_plus_1;
  }
};

class NeLinUrav : public AbstrCl_T {
public:
  double y_t_minus_1;
  double u_t_minus_1;
  NeLinUrav(double Y_t, double U_t, double Y_t_minus_1, double U_t_minus_1) :AbstrCl_T(Y_t, U_t){
    y_t_minus_1 = Y_t_minus_1;
    u_t_minus_1 = U_t_minus_1;
    y_t_plus_1 = 0.9*y_t - 0.001*pow(y_t_minus_1, 2) + u_t + sin(u_t_minus_1);
  }
  void show_decision(){
    cout << "y(t+1) = [y(t)=" << setprecision(6) << y_t << ",\ty(t-1)=" << setprecision(6) << y_t_minus_1 
       << ",\tu(t)=" << u_t << ", u(t-1)=" << u_t_minus_1 << "] = " << setprecision(6) << y_t_plus_1 << endl;
  }
  double retrn(){
    return y_t_plus_1;
  }
};
int main()
{
  setlocale(LC_CTYPE, "Russian");
  cout << "Нелинейное уравнение:\n";
  double rnd_y_t = 0.0000;
  for (int i = 0; i < 15; i++){
    LinUrav LU(rnd_y_t, 5);
    LU.show_decision();
    rnd_y_t += (double)(rand()) / RAND_MAX*1 + 2;
  }
  cout << "\nЛинейное уравнение:\n";
  double y_t_minus_1 = 0.0000;
  double y_t = 0.0000;
  for (int i = 0; i < 15; i++){
    NeLinUrav NeLU(y_t, 5, y_t_minus_1, 5);
    NeLU.show_decision();
    y_t_minus_1 = y_t;
    y_t = NeLU.retrn();
  }
  return 0;
}

```
### *Результат ввыполнения программы на C++:* <br>
![Result](https://github.com/idzm/mmipu-lab-16-17/blob/master/trunk/as0004407/task_01/1.png) <br>

### *Код матлаб:*
*Функция выводящая изменения по линейной модели:*
```matlab
function itr  = LinUrav(Y_t,U_t)
    for i=1:15 
        y_t_plus_1 = 0.988*Y_t + 0.232*U_t;
        itr(i) = y_t_plus_1;
        Y_t = y_t_plus_1;
    end;
end

```
*Функция выводящая изменения по нелинейной модели:* 
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
*Результат выполнения функций:* <br>
![Result](https://github.com/idzm/mmipu-lab-16-17/blob/master/trunk/as0004407/task_01/2.png) <br>
### *Графики:*
![Линейная модель](https://github.com/idzm/mmipu-lab-16-17/blob/master/trunk/as0004407/task_01/3.png) 
![Нелинейная модель](https://github.com/idzm/mmipu-lab-16-17/blob/master/trunk/as0004407/task_01/4.png)

-------------
### Вывод: 
В результате выполнения данной лабораторной работы, я реализовал программу моделирующую рассмотренный объект управления.
