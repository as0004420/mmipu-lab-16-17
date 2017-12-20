# Лабораторная работа №1 
----------
## Тема: Моделирование объекта управления
----------
 **Выполнил:<br>**
 **Студент ФЭИС<br>**
 **3 курса<br>**
 **Группы АС-44<br>**
 **Шадрин Р.А.<br>**
 **Проверил:<br>**
 **Пролиско Е.Е.<br>**
----------
 **Цель работы:**
 Нaучиться моделировать объекты управления в Matlab.
----------
 **Ход работы:**
 1.	Моделирование объекта управления.
Рассмотрим моделирование объекта, температура которого описывается следующим дифференциальным уравнением:<br>
**(dy(τ))/dτ=(f(τ))/C+(Y_0-y(τ))/RC<br>**
где τ – время; y(τ) – выходная температура; f(τ)–тепло, поступающее в систему;Y_0 – комнатная температура (для простоты, 
будем считать ее постоянной); C – теплоемкость системы; RC – тепловое сопротивление между границами системы и окружающей средой. Считая величины R и C постоянными, по реакции на единичное ступенчатое воздействие получаем следующее уравнение:<br>
**y(τ+1)=a(T)y(τ)+b(T)u(τ)<br>**
где τ – дискретное целочисленное время; T – интервал квантования; y(τ)  и u(τ) –вход и выход системы соответственно (выходная температураитепло, поступающее в систему, соответственно).
Получим две модели: линейную (1) и нелинейную(2):<br>
**1:y_(t+1)=0.988y_t+0.232u_t<br>**
**2:y_(t+1)=0.9y_t-0.001y_(t-1)^2+u_t+sin⁡(u_(t-1))<br>**

Функция выводящая изменения по линейной модели:<br>
Результат выполнения функций:<br>

# 1:Линейная<br>
![](s1.png)<br>
![](s2.png)<br>
Константа: <br>
![](s3.png)<br>
Скачок: <br>
![](s4.png)<br>
Синусоида:<br>
![](s5.png)<br>
# 2:Нелинейная<br>
![](s6.png)<br>
![](s7.png)<br>
Константа: <br>
![](s8.png)<br>
Скачок: <br>
![](s9.png)<br>
Синусоида:<br>
![](s10.png)<br>

**Вывод:** реализовала программу в MATLAB, моделирующую рассмотренный выше объект управления,<br>
 используя эти модели.<br>

