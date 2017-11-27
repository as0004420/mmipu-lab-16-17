#### BSTU
#### Department of Informatics and Applied Mathematics
#### Laboratory work N1
#### Theme: Model a control model.
#### Studen: Kapura A.V.
#### Checked By: Ivanyuk D.S.

##### Goal: 
Create a program using C++ work according to the model presented before. 
Program must has OOP (3 classes: Abstract,  Child Class of Abstract and one more).

Model's equations:
> linear model: y(t+1)=0.988y(t)+0.232u(t);
>
> non linear model: y(t+1)=0.9y(t)-0.001y(t-1)^2+u(t)+sin⁡(u(t-1)).

### Code:

	#include <iostream>
	#include <math.h>
	using namespace std;

	class AbstCalc {
		public:
			AbstCalc(void) {};
			virtual void setLim(int place) = 0;
			virtual double linearSolve(int pos, double y) = 0;
	};
	
	class Calculation : AbstCalc{
		public:
			int lim;
			Calculation() {};
	
			void setLim(int place) override{
				this->lim = place;
			}
	
			double linearSolve(int pos, double y) override {
				if (lim == pos) {
					return y;
				}
				else {
					double yt = 0.988*y + 0.232*ut(y);
					cout << "Linear : " << pos << " - " << yt << endl;
					return linearSolve(pos + 1, yt);
				}
			}
	
			double curvSolve(int pos, double y, double y_prev) {
			
				if (lim == pos) {
					return y;
				}
				else {
					double yt = 0.9*y - 0.001*pow(y_prev, 2) + ut(y) + sin(ut(y_prev));
					cout << "Non Linear : " << pos << " -  " << yt << endl;
					return curvSolve(pos + 1, yt, y);
				}
			}
		private:
			double ut(double y) {
				return y*0.25;
			}
	};
	
	class WorkSpace {	
	public:	
		void startWork() {
			int count;
			double y;
	
			cin >> count;//iterations
			cin >> y; //origin value
	
			Calculation calc;
	
			calc.setLim(count);
			cout << calc.linearSolve(1, y) << endl;
			cout << calc.curvSolve(1, y, 0);
		}
	};

	int main(){
		WorkSpace workSpace;
		workSpace.startWork();
	    return 0;
	}

>### Linear
>![linear](https://github.com/AlexDejss/mmipu-lab-16-17/blob/master/trunk/as0004603/task_01/images/linear.PNG)
>### Nonlinear
>![nonlinear](https://github.com/AlexDejss/mmipu-lab-16-17/blob/master/trunk/as0004603/task_01/images/nonlinear.png)

### Result:
Looking on graphs, we can see, that a linear equation is going to increase infinitely, however a nonlinear after reaching some limit slightly decrease and stay the same.
