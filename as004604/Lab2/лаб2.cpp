#include <iostream>
#include <cmath>
using namespace std;

class CalculQParameters
{
public:

	float k = 0.1, t = 100, td = 0, t0 = 1, q0, q1, q2, du, uk1 = 10;
	
    CalculQParameters(){}
    
    void calclulateQs() {
    	q0 = k * (1 + td / t0);
    	q1 = (-1) * k * (1 + 2 * td / t0 - t0 / t);
    	q2 = k * td / t0;
    };
    
    void calculDU(float ek, float ek1, float ek2)
    {
    	du = q0 * ek + q1 * ek1 + q2 * ek2;
    	//cout << "q0: " << q0 << " ek: " << ek;
    	//cout << " q1: " << q1 << " ek1: " << ek1;
    	//cout << " q2: " << q2 << " ek2: " << ek2 << endl;
    	//cout << "du: " << du << endl;
    }
    
    float calculU()//float prevU)
    {
    	uk1 += du;
    	//cout << "uk1: " << uk1 << endl;
    	return uk1;
    }
};

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
    	CalculQParameters *cqp = new CalculQParameters();
    	cqp->calclulateQs();
    	cqp->calculDU(0, 0, 0);
    	cout << "Result from linear method: " << endl;
    	float Y = 0, U = cqp->calculU(), ek = 0, ek1 = 0, ek2 = 0, w = 100;
       	cout << Y;
    	for (int i=0;i<1000;i++)
    	{
			float resultY;			
			resultY = 0.998*Y + 0.232*U;
        	cout << resultY << " ";// << endl;
        	Y = resultY;
        	ek2 = ek1;
        	ek1 = ek;
        	ek = w - Y;
        	cqp->calculDU(ek, ek1, ek2);
        	U = cqp->calculU();
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
    	CalculQParameters *cqp = new CalculQParameters();
    	cqp->calclulateQs();
    	cqp->calculDU(0, 0, 0);
        cout << "Result from non-linear method: " << endl;
        float Y = 0, U = cqp->calculU(), ek = 0, ek1 = 0, ek2 = 0, w = 10;
    	//float Y = 0.75, U = 0.75*Y;
       	cout << Y;
    	for (int i=0;i<1000;i++)
    	{
			float resultY;	
    		resultY = 0.9*Y - 0.001*Y*Y + U + sin(U);
    		cout << resultY << " ";
    		Y = resultY;
    		U = 0.75*Y;
        	ek2 = ek1;
        	ek1 = ek;
        	ek = w - Y;
        	cqp->calculDU(ek, ek1, ek2);
        	U = cqp->calculU();
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
// новая температура без учёта нынешней
// 94-38-02
