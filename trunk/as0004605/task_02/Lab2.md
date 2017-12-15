#### BSTU
#### Department of Informatics and Applied Mathematics
#### Laboratory work N2
#### Theme: PID controllers.
#### Studen: Tikhonov D. N.
#### Checked By: Ivaniuk D.S.

### Goal: 
Create a program using C++  according to the model of PID controller. Use the mathemetical model from the first laboratory work. Program must be written according to the OOP and it must to contain 3 classes(abstract and its child).

PID controller variables:

- u(k) = u(k-1) + Δu(k)
- Δu(k) = q0*e(k) + q1*e(k-1) + q2*e(k-2)
- q0 = K*(1+(Td/To))
- g1 = -K*(1+2*(Td/To) - (Td/To))
- g2 = K*(Td/To)
- e = u\_in-u\_prev


###Graph:
[!Graph](img/Lab2Graph.png)

###Code:

	#include <iostream>
	using namespace std; 
	class Virt { 	
		protected: 
			virtual double e( int time) = 0; 
			virtual double deltU() = 0; 
		public:
			Virt(void) {} ; 
			virtual void setVals( double K,  double Td,  double To,  double inputU,  int k) = 0; 
	}; 	
	class Regulator :  Virt{ 
		private: 
			double previousU =  0; 
			double lastU =  0; 
			double currentU =  0; 
			double inputU; 
			double k; 
			double q0; 
			double q1; 
			double q2; 
		protected: 
			double deltU()  { 
				 return q0 * e(0)  +  q1 * e(1)  +  q2 * e(2) ; 
			} 
			double e(int time)  override { 
				switch (time) 
				{ 
					case 0: 
						 return inputU -  currentU; 
						 break; 
					case 1: 
						 return inputU -  previousU; 
						 break; 
					case 2: 
						 return inputU -  lastU; 
						 break; 
					default: 
						 return inputU -  currentU; 
						 break; 
				} 
			} 
			
		
		public: 
			Regulator()  { } ; 
			void setVals( double K,  double Td,  double To,  double inputU,  int k)  override { 
				this->q0 = K * ( 1 + ( Td / To) );
				this->q1 = - K * ( 1 +  2 * ( Td / To) - ( Td / To) );
				this->q2 = K * ( Td / To);
				this-> inputU = inputU; 
				this-> k = k; 
			}
			double calculation( int currentK)  { 
				if ( previousU !=  0)
					 lastU =  previousU; 
				if ( currentU !=  0)
					 previousU =  currentU; 
				currentU =  previousU +  deltU() ; 
				cout <<  currentU <<  endl; 
				if(currentK ==  this->k)
					 return currentU; 
				else 
					 return calculation(currentK +  1) ; 
			} 	
	}; 
	class WorkingClass { 
		private: 
			int type; 
		public:
			void setType( int type)  { 
				 this-> type =  type; 
			} 
			void start()  { 
				Regulator proc; 
				proc.setVals( 10,  0.1,  50,  50,  200) ;
				proc.calculation(0); 
			} 
	}; 
	int main() { 
		WorkingClass doit; 
		doit.start(); 
		system("pause");
		return 0; 
	} 


###Conclusion:
I understood how the PID regulator works and observed how the values of its output changes with different parameters.