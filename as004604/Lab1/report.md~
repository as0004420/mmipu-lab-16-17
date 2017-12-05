#### BSTU
#### Department of Informatics and Applied Mathematics
#### Laboratory work N1
#### Theme: Model a control model.
#### Studen: Kovalevich T.A.
#### Checked By: Ivaniuk D.S.

##### Goal: 
Realize on C++ program, which modulate manager object, using two models:

> linear model: y(t+1)=0.988y(t)+0.232u(t);
>
> non linear model: y(t+1)=0.9y(t)-0.001y(t-1)^2+u(t)+sin⁡(u(t-1)).

Use OOP, create not less then 3 classes (one is the abstract) and incheritance.
Create graphs of changing of object’s temperature.

### Code:

#include <iostream>
#include <cmath>
using namespace std;

class Calcul
{
public:
    Calcul(){}
 
     virtual void calclulate() {};
};
 
class LinearCalcul : public Calcul
{
public:
    LinearCalcul() : Calcul ()   
    {}
 
    void calculate() //override
    {
    	cout << "Result from linear method: " << endl;
    	float Y = 0.75, U = 0.75*Y;
       	cout << Y;
    	for (int i=0;i<50;i++)
    	{
			float resultY;			
			resultY = 0.998*Y + 0.232*U;
        	cout << resultY << ", ";
        	Y = resultY;
        	U = 0.75*Y;
        }
        cout << endl;
    }
    	
};

class NonLinearCalcul : public Calcul
{
public:
    NonLinearCalcul() : Calcul ()   
    {}
    void calculate() //override
    {
        cout << "Result from non-linear method: " << endl;
    	float Y = 0.75, U = 0.75*Y;
       	cout << Y;
    	for (int i=0;i<50;i++)
    	{
			float resultY;	
    		resultY = 0.9*Y - 0.001*Y*Y + U + sin(U);
    		cout << resultY << ", ";
    		Y = resultY;
    		U = 0.75*Y;
        }
        cout << endl;
    }
};

int main()
{
    LinearCalcul *lc = new LinearCalcul();
    NonLinearCalcul *nlc = new NonLinearCalcul();
    lc->calculate();
    nlc->calculate();
    return 0;
}

### Result of the 50 iterations:
Result from linear method: 
0.750.879, 1.03019, 1.20738, 1.41505, 1.65844, 1.94369, 2.278, 2.66982, 3.12903, 3.66722, 4.29799, 5.03724, 5.90364, 6.91907, 8.10915, 9.50393, 11.1386, 13.0544, 15.2998, 17.9314, 21.0156, 24.6302, 28.8666, 33.8317, 39.6508, 46.4707, 54.4636, 63.8314, 74.8104, 87.6778, 102.758, 120.433, 141.147, 165.425, 193.878, 227.225, 266.307, 312.112, 365.795, 428.712, 502.45, 588.872, 690.158, 808.865, 947.99, 1111.04, 1302.14, 1526.11, 1788.6, 2096.24.

Result from non-linear method: 
0.751.77024, 3.88836, 6.62409, 9.91838, 17.182, 28.3697, 46.66, 74.3882, 116.52, 178.137, 263.19, 365.498, 468.762, 553.437, 607.256, 633.301, 643.316, 646.647, 649.74, 649.558, 649.625, 649.6, 649.609, 649.606, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607.

### Graphs:

Code In Matlab:
L = [0.750.879, 1.03019, 1.20738, 1.41505, 1.65844, 1.94369, 2.278, 2.66982, 3.12903, 3.66722, 4.29799, 5.03724, 5.90364, 6.91907, 8.10915, 9.50393, 11.1386, 13.0544, 15.2998, 17.9314, 21.0156, 24.6302, 28.8666, 33.8317, 39.6508, 46.4707, 54.4636, 63.8314, 74.8104, 87.6778, 102.758, 120.433, 141.147, 165.425, 193.878, 227.225, 266.307, 312.112, 365.795, 428.712, 502.45, 588.872, 690.158, 808.865, 947.99, 1111.04, 1302.14, 1526.11, 1788.6, 2096.24];

NL = [0.751.77024, 3.88836, 6.62409, 9.91838, 17.182, 28.3697, 46.66, 74.3882, 116.52, 178.137, 263.19, 365.498, 468.762, 553.437, 607.256, 633.301, 643.316, 646.647, 649.74, 649.558, 649.625, 649.6, 649.609, 649.606, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607, 649.607];
plot (L)

![linear](https://github.com/KovalevichTimofei/mmipu-lab-16-17/tree/master/as004604/Lab1/images/Linear.png)

plot(NL)

![linear](https://github.com/KovalevichTimofei/mmipu-lab-16-17/tree/master/as004604/Lab1/images/Nonlinear.png)

### Conclusion:

In this lab I study making the models of manager of room temperature object. For this I used 2 models: linear and non-linear. Temperature in a linear method increases endless. Temperature in a non-linear method rich some limit and stop on it. Realization of the non-linear is the more complex then linear.
