#### BSTU
#### Department of Informatics and Applied Mathematics
#### Laboratory work N2
#### Topic: PID controllers.
#### Student: Borisiuk E.R.
#### Checked By: Ivaniuk D.S.

##### Goal: 
Create a program using C++ according to the model of PID controller. Use the mathemetical model from the first laboratory work. Program must has OOP (3 classes: Abstract,  Child and one more).

>PID controller formulas:
>
> u(k) = u(k-1) + Δu(k)
>
> Δu(k) = q0*e(k) + q1*e(k-1) + q2*e(k-2)
>
> q0 = K*(1+(Td/To))
>
> g1 = -K*(1+2*(Td/To) - (Td/To))
>
> g2 = K*(Td/To)
>
>! e = u\_in-u\_prev

### Code:
		//lab2.cpp: определяет точку входа для консольного приложения.
		//
	#include "stdafx.h"
	#include <iostream> 
	using namespace std; 
	class Abstr { 
	protected: 
		virtual double e(int time) { return 0; };
		virtual double uk() { return 0; };
	public:
		virtual void setngo( double K,  double Td,  double To,  double u_in,  int k) = 0; 
	}; 
	class pid : Abstr {
	private: 
		double u_curr =  0; 
		double u_prev1 =  0; 
		double u_prev2 =  0; 
		double q0;
		double q1;
		double q2;
		double u_in; 
		double k; 
	protected: 
		double e( int time)  override { 
			switch ( time) 
			{ 
				case 0: 
					 return u_in -  u_curr; 
					 break; 
				case 1: 
					 return u_in -  u_prev1; 
					 break; 
				case 2: 
					 return u_in -  u_prev2; 
					 break; 
			} 
		} 
		double uk() {
			return q0 * e(0) + q1 * e(1) + q2 * e(2);
		}
		
		double calc( int curr_k)  { 
			if ( u_prev1 !=  0)
				 u_prev2 =  u_prev1; 
			if ( u_curr !=  0)
				 u_prev1 =  u_curr; 
			u_curr =  u_prev1 +  uk() ; 
			cout <<  u_curr <<  endl; 
			if(curr_k ==  this->k)return u_curr;
			else return calc( curr_k +  1) ;
				 
		} 
		
	public: 
		void setngo( double K,  double Td,  double To,  double u_in,  int k)  override { 
			this->q0 = K* ( 1 + ( Td / To) );
			this->q1 = - K* ( 1 +  2* ( Td / To) - ( Td / To) );
			this->q2 = K* ( Td / To);
			this->u_in = u_in; 
			this->k =  k; 
			calc(0);
		}
	}; 
	class Calc { 
		public:
			void start()  { 
				pid p; 
				p.setngo( 10,  0.1,  50,  100,  1000) ;
			} 
	}; 
	int main() { 
		Calc c;
		c.start();
		return 0; 
	} 

>### Graph
>![Correct parameters](https://github.com/Blckwtrs/mmipu-lab-16-17/blob/master/trunk/AS0004601/lab2/img/img.PNG)
>
>![Wrong parameters](https://github.com/Blckwtrs/mmipu-lab-16-17/blob/master/trunk/AS0004601/lab2/img/wrong.PNG)
### Conclusion:
According to  graphs, we can see the difference between system with correct  parameters and system with wrong values. Correct one goes to the neccessary valye and keeps and incorrect system has 