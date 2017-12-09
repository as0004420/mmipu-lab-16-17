#### Лабораторная работа №1
#### Тема: Моделирование объекта управления
 Выполнил:<br>
 Студент ФЭИС<br>
 3 курса<br>
 Группы АС-44<br>
 Демчик А.И.<br>
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
#include <iomanip>
#include <cmath>
using namespace std;
class T { //абстрактный класс от которого наследуются другие
	protected: 
		double Yt;
		double Ut;
		double Ytplus1;
	public:
		virtual double getResult() = 0;
		virtual void output(int) = 0;
		T(double _Yt, double _Ut) { //конструктор базового класса
			Yt = _Yt;
			Ut = _Ut;
		}
};
class linearT :public T {//производный класс линейной модели
	public:
		
		linearT(double _Yt, double _Ut):T(_Yt, _Ut){ //конструктор 
			
		}
		
		double getResult() {//вычисляет следующее значение температуры
			return  Ytplus1 = 0.988*Yt + 0.232*Ut;
		}
	
		void output(int i) {//выводит изменение температуры за i кол-во шагов
			
			cout << "linear change:" << endl;
			cout << left << setw(8) << "Yt" << "|" << setw(4) << "Ut" << "|" << setw(8) << "Yt+1" << "|" << setw(4) <<"step" << endl;
			cout << setfill('-') << setw(8) << "" <<"+" << setw(4) << "" <<"+" << setw(8) <<""<<"+" << setw(4) << ""<< setfill(' ') <<endl;
			for (int j = 0; j < i; j++) {
				getResult();
                          cout << left << setw(8)  << Yt << "|" << setw(4) << Ut << "|"  << setw(8) << Ytplus1 <<"|"<< setw(4) << j << endl;
				Yt = Ytplus1;
			}
		}

};
class noLinearT : public T { //производный класс нелинейной модели
	public:
		double getResult() { //вычисляет следующее значение температуры
			return Ytplus1 = 0.9*Yt - 0.001*pow(Ytminus1, 2) + Ut + sin(Ut);
		}
		noLinearT(double _Yt, double _Ut, double _Ytmin1) :T(_Yt, 
             _Ut),Ytminus1(_Ytmin1){//конструктор

		}
		void output(int i) {//выводит изменение температуры за i кол-во шагов

			cout << "nolinear change:" << endl;
			cout << left << setw(8) << "Yt" << "|" << setw(8) << "Yt-1" << "|" <<  setw(4) << "Ut" << "|" << setw(8) << "Yt+1" << "|" << setw(4) <<    "step" << endl;
			cout << setfill('-') << setw(8) << "" << "+" << setw(8) << "" << "+"  << setw(4) << "" << "+" << setw(8) << "" << "+" << setw(4) << "" << setfill(' ') << endl;
			for (int j = 0; j < i; j++) {
				getResult();
				cout << left << setw(8) << Yt << "|" << setw(8) << Ytminus1 << "|" << setw(4) << Ut << "|" << setw(8) << Ytplus1 << "|" << 
                           setw(4) << j << endl;
				Ytminus1 = Yt;
				Yt = Ytplus1;
			}
		}
	private:
		double Ytminus1;
};
int main() { 
	linearT *line = new linearT(0, 10); //создание объекта линейной модели
	line->output(15);
	noLinearT *noline = new noLinearT(0, 10, 0); //создание объекта нелинейной модели
	noline->output(15);
	return 0;
}
```
#### Результат: <br>
![Result](https://github.com/as0004410/mmipu-lab-16-17/raw/master/trunk/as0004410/task_01/cppRes.png)
<br>
#### Код матлаб:
Функция выводящая изменения по линейной модели: 
```matlab
 function res  = OutputLinear(Yt,Ut)
    for i=1:15 
        Ytplus1 = 0.988*Yt + 0.232*Ut;
        res(i) = Ytplus1;
        Yt = Ytplus1;
    end;
 
end
```
Функция выводящая изменения по нелинейной модели: 
```matlab
function res = OutputNoLinear(Yt,Ytminus1,Ut)
    for i=1:15
        Ytplus1 = 0.9*Yt - 0.001*(Ytminus1)^2 + Ut + sin(Ut);
        res(i) = Ytplus1;
        Ytminus1 = Yt;
        Yt = Ytplus1;
    end;
    
end
```
Результат выполнения функций: <br>
![Result](https://github.com/as0004410/mmipu-lab-16-17/raw/master/trunk/as0004410/task_01/matlabRes.png)
<br>
#### Графики:
![Линейная модель](https://github.com/as0004410/mmipu-lab-16-17/raw/master/trunk/as0004410/task_01/linear.png)
![Нелинейная модель](https://github.com/as0004410/mmipu-lab-16-17/raw/master/trunk/as0004410/task_01/nolinear.png)
#### Вывод: 
Из графиков видно что линейная функция возрастает до бесконечности, а нелинейная, достигнув некоторого предела, остается на одном уровне.