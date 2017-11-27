####BSTU
####Department of Informatics and Applied Mathematics
####Laboratory work N2
####Theme: PID controllers.
####Studen: Kapura A.V.
####Checked By: Ivanyuk D.S.

#####Goal: 
Create a program using C++ work according to the model of PID controller. Use the mathemetical model from the first laboratory work. Program must has OOP (3 classes: Abstract,  Child Class of Abstract and one more).

Algorithm of PID controller:

- u(k) = u(k-1) + Δu(k)
- Δu(k) = q0*e(k) + q1*e(k-1) + q2*e(k-2)
- q0 = K*(1+(Td/To))
- g1 = -K*(1+2*(Td/To) - (Td/To))
- g2 = K*(Td/To)
- e = u\_in-u\_prev


###Code:

	#include <iostream> 
	using namespace std; 

	class Blueprint { 
	
		protected: 

			virtual double e( int time) = 0; 
			virtual double deltU() = 0; 

		public:
 
			Blueprint(void) {} ; 

			virtual void setVals( double K,  double Td,  double To,  double u_in,  int k) = 0; 

	}; 
	
	class Process :  Blueprint{ 

		private: 

			double u_prev =  0; 
			double u_t_last =  0; 
			double u_curr =  0; 
			double u_in; 
			double k; 
			double g0; 
			double g1; 
			double g2; 

		protected: 

			double deltU()  { 
				 return g0 * e(0)  +  g1 * e(1)  +  g2 * e(2) ; 
			} 

			double e( int time)  override { 
				switch ( time) 
				{ 
					case 0: 
						 return u_in -  u_curr; 
						 break; 
					case 1: 
						 return u_in -  u_prev; 
						 break; 
					case 2: 
						 return u_in -  u_t_last; 
						 break; 
					default: 
						 return u_in -  u_curr; 
						 break; 
				} 
			} 
			
			double calculation( int curr_k)  { 
				if ( u_prev !=  0)
					 u_t_last =  u_prev; 
				if ( u_curr !=  0)
					 u_prev =  u_curr; 
				u_curr =  u_prev +  deltU() ; 
				cout <<  u_curr <<  endl; 
				if(curr_k ==  this->k)
					 return u_curr; 
				else 
					 return calculation( curr_k +  1) ; 
			} 
		
		public: 
			Process()  { } ; 

			void setVals( double K,  double Td,  double To,  double u_in,  int k)  override { 
				this->g0 = K* ( 1 + ( Td / To) );
				this->g1 = - K* ( 1 +  2* ( Td / To) - ( Td / To) );
				this->g2 = K* ( Td / To);
				this-> u_in = u_in; 
				this-> k =  k; 
			}

			void startWork()  { 
				 calculation( 0) ; 
			} 
	
	}; 

	class WorkPlace { 
		private: 

			int type; 

		public:
 
			void setType( int type)  { 
				 this-> type =  type; 
			} 
	
			void startWork()  { 
				Process proc; 
				proc.setVals( 10,  0.1,  50,  50,  1000) ;
				proc.startWork(); 
			} 
	}; 
	
	int main() { 
		WorkPlace work; 
		work. startWork(); 
		return 0; 
	} 

>###Graph
![Alt text](/images/graph.png)

###Result:
Looking on graph, we can see, that if system has correct paramethers (blue curve) it after some time will reach one value and will stay the same, otherwise it could became mad (orange curve) and has a wave-like form, as here is presented. 