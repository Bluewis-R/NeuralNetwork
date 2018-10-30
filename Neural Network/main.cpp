#include <iostream>
#include <Windows.h>
#include <vector>
#include <cmath>

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
	//multiNeuron();

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


void multiNeuron()
{
	//initiating variables
	int itterations = 100000;
	
	float weight1_3 = 0.5f;
	float weight1_4 = 0.9f;
	float weight3_5 = -1.2f;
	float weight2_3 = 0.4f;
	float weight2_4 = 1.0f;
	float weight4_5 = 1.1f;

	float theta3 = 0.8f;
	float theta4 = 0.4f;
	float theta5 = 0.3f;
	float alpha = 0.1f;

	int x[3][4];
	int Yd5[4];
	float X[5];
	float Y[5];
	float e[5];

	x[1][1] = 1;
	x[1][2] = 0;
	x[1][3] = 1;
	x[1][4] = 0;
	x[2][1] = 1;
	x[2][2] = 1;
	x[2][3] = 0;
	x[2][4] = 0;
	Yd5[1] = 0;
	Yd5[2] = 1;
	Yd5[3] = 1;
	Yd5[4] = 0;


	//code
	int p = 0;
	while(p <= itterations - 4)
	{
		float EpochSumError = 0;
		for (int i = p % 4; i < 3; i++)
		{
			std::cout << p << std::endl;
			//neuron 3
			X[3] = (x[1][i] * weight1_3) + (x[2][i] * weight2_3);
			Y[3] = 1 / ( 1 + pow(exp(1), -(X[3] - theta3) ));

			//neuron 4
			X[4] = (x[1][i] * weight1_4) + (x[2][i] * weight2_4);
			Y[4] = 1 / (1 + pow(exp(1), -(X[4] - theta4)));

			//neuron 5
			X[5] = (x[1][i] * weight3_5) + (x[2][i] * weight4_5);
			Y[5] = 1 / (1 + pow(exp(1), -(X[5] - theta5)));


			//	Back propergating the error
			// N5 error
			e[5] = Yd5[i] - Y[i];
			Delta = 
		}
	}
		

}