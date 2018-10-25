#include <iostream>
#include <Windows.h>

int signFunction(int x, float _theta, float _delta);
int stepFunction(float x, float _theta, float _delta);
void neuronOne();
/*
class stepType {
public:
float Theta;
float x;
int y;
float x[3] = { 0.1f, 0.5f, 0.8f };
float w[3] = { 0.7f, 0.2f, 0.6f };
};
*/
// i was in the proccess of makeing the sigma function into a function and changing the variables


int main()
{
	neuronOne();


	system("PAUSE");
	return 0;
}


void neuronOne()
{
	float w1, w2;
	float x1[4] = { 0,0,1,1 };
	float x2[4] = { 0,1,0,1 };
	int Y[4] = { 0,0,0,1 };
	w1 = 0.3f;
	w2 = -0.1f;
	float X;




	int maxItteration = 20;
	float alpha = 0.1f;
	int error;
	int tempY;
	int p = 0;

	//std::cout << "Epoch\tx1\tx2\tYd\tw1\tw2\tY\te\tw1\tw2";

	for (int i = 0; i < maxItteration; i++)
	{
		p = i % 4;
		//	the step fucntion
		X = (x1[p] * w1) + (x2[p] * w2);
		tempY = stepFunction(X, 0.2f, 0.000001f);

		//calculating error
		error = Y[p] - tempY;

		//debugging
		/*
		std::cout << p << "\t";
		std::cout << x1[p] << "\t";
		std::cout << x2[p] << "\t";
		std::cout << Y[p] << "\t";
		std::cout << w1 << "\t";
		std::cout << w2 << "\t";
		std::cout << error << "\t";
		*/
		//	the learning rule
		w1 += alpha * x1[p] * error;
		w2 += alpha * x2[p] * error;

		//	debugging
		//std::cout << w1 << "\t";
		//std::cout << w2 << "\t";

	}
	std::cout << "w1: " << w1 << std::endl;
	std::cout << "w2: " << w2 << std::endl;










	/*
	for (int i = 0; i < 3; i++)
	{
	X = (x1[i] * w1) + (x2[i] * w2);
	Y[i] = stepFunction(X, 0.2, 0.000001);
	}

	std::cout << "Weak : Weak " << Y[0] << std::endl;
	std::cout << "Weak : Strong " << Y[0] << std::endl;
	std::cout << "Strong : Weak " << Y[2] << std::endl;
	std::cout << "Strong : Strong " << Y[3] << std::endl;

	std::cout << stepFunction(-1, 0.2, 0.000001) << std::endl;
	std::cout << stepFunction(0, 0.2, 0.000001) << std::endl;
	std::cout << stepFunction(1, 0.2, 0.000001) << std::endl;
	*/
}












int stepFunction(float x, float _theta, float _delta)
{
	if (x >= _theta - _delta)
	{
		return 1;
	}
	else //if (x <= _theta + _delta)
	{
		return 0;
	}

	std::cout << "MEGA-ERROR";
}






















int signFunction(int x, float _theta, float _delta)
{
	if (((float)x <= _theta - _delta))
	{
		return 1;
	}
	else if (x >= -_theta + _delta)
	{
		return -1;
	}
}

/*
float SigmoidFunction(float _x, float _theta)
{
return (1 / (1 + pow(e, -(_x - _theta))));
}

*/