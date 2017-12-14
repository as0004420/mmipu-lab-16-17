#### BSTU
#### Department of Informatics and Applied Mathematics
#### Laboratory work N1
#### Theme: Model a control model.
#### Student: Borisiuk E.R.
#### Checked By: Ivaniuk D.S.

##### Goal: 
Create a program using C++ work according to the model presented before. 
Program must has OOP (3 classes: Abstract,  Child Class of Abstract and one more).

Model's equations:
> linear model: y(t+1)=0.988y(t)+0.232u(t);
>
> non linear model: y(t+1)=0.9y(t)-0.001y(t-1)+u(t)+sin⁡(u).

### Code:
		#include <iostream>
		#include <math.h>
		using namespace std;

		double abstrcalc::calc()
		{
			 return 0;
		}

		double nonlin::calc(double y, double y1, double u)
		{

			y = 0.9*y -0.001*y1 + u + sin(u);
			return y;
		}
		double lincalc::calc(double y,double u)
		{
			y = 0.988*y + 0.232*u;
			return y;
		}
		using namespace std;
		int main()
		{
			int n;
			double y, u;
			vector<double> linear;
			vector<double> nonlinear;
			cin >> y >> u>>n;
			lincalc a;
			nonlin b;
			linear.push_back(y);
			nonlinear.push_back(0);
			nonlinear.push_back(y);
			for (int i = 0; i < n; i++)
			{
				linear.push_back(a.calc(linear.back(), u));
			}
			for (int i = 0; i < linear.size();i++)
			{
				cout<<linear[i]<<'\n';
			}
			while(b.calc(nonlinear.back(), nonlinear[nonlinear.size() - 2], u)!=nonlinear.back())
			{
				nonlinear.push_back(b.calc(nonlinear.back(),nonlinear[nonlinear.size()-2], u));
			}
			for (int i = 0; i < nonlinear.size(); i++)
			{
				cout << nonlinear[i] << '\n';
			}
		    return 0;
		}
	
>### Linear
>![linear]
>### Nonlinear
>![nonlinear]

### Result:
According to the graphs, we can see, that the linear equation will increase infinitely, but the nonlinear after reaching some limit stays the same.