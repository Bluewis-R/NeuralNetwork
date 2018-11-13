#include <iostream>
#include <Windows.h>
#include <vector>
#include <cmath>

int signFunction(int x, float _theta, float _delta);
int stepFunction(float x, float _theta, float _delta);
void neuronOne();
void multiNeuron();
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
	//neuronOne();
	multiNeuron();

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


float SigmoidFunction(float _x, float _theta)
{
	return (1 / (1 + pow(exp(1), -(_x - _theta))));
}



void multiNeuron()
{
	//	initiating variables
	int itterations = 100000;
	//	This is wastfull but easy to do for now,
	//	in future this can be replaced with something more efficient
	float weights[4][5];
	float weightsCurrent[5][6];

	weights[1][3] = 0.5f;
	weights[1][4] = 0.9f;
	weights[3][5] = -1.2f;
	weights[2][3] = 0.4f;
	weights[2][4] = 1.0f;
	weights[4][5] = 1.1f;
	

	float theta[6];
	theta[3] = 0.8f;
	theta[4] = -0.1f;
	theta[5] = 0.3f;
	float alpha = 0.1f;

	int x[3][4];
	int Yd5[5];
	float X[6];
	float Y[6];
	float error[6];
	float delta[6];
	float te5;

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

	float tX[6];
	float tY[6];

	//code
	int p = 0;
	while(p <= (itterations - 4))
	{
		float EpocSumError = 0;
		for (int i = (p % 4)+1; i < 5; i++)
		{
			std::cout <<"p : " << p << std::endl;
			//neuron 3
			X[3] = (x[1][i] * weights[1][3]) + (x[2][i] * weights[2][3]);
			Y[3] = 1 / ( 1 + pow(exp(1), -(X[3] - theta[3]) ));

			//neuron 4
			X[4] = (x[1][i] * weights[1][4]) + (x[2][i] * weights[2][4]);
			Y[4] = 1 / (1 + pow(exp(1), -(X[4] - theta[4])));

			//neuron 5
			X[5] = (x[1][i] * weights[3][5]) + (x[2][i] * weights[4][5]);
			Y[5] = 1 / (1 + pow(exp(1), -(X[5] - theta[5])));


			//	Back propergating the error
			// N5 error
			error[5] = Yd5[i] - Y[5];
			delta[5] = Y[5] * (1 - Y[5])*error[5];
			weightsCurrent[3][5] = weights[3][5];
			weightsCurrent[4][5] = weights[4][5];
			weights[3][5] += alpha * Y[3] * delta[5];
			weights[4][5] += alpha * Y[4] * delta[5];
			theta[5] += alpha * (-1)*delta[5];

			// N3 error
			error[3] = weightsCurrent[3][5] * error[5];
			delta[3] = Y[3] * (1 - Y[3])*delta[5]*weightsCurrent[3][5];
			weights[1][3] += alpha * Y[i] * delta[3];
			weights[2][3] += alpha * Y[i] * delta[3];
			theta[3] += alpha * (-1)*delta[3];

			// N4 error
			error[4] = weightsCurrent[4][5] * error[5];
			delta[4] = Y[4] * (1 - Y[4])*delta[5] * weightsCurrent[4][5];
			weights[1][4] += alpha * Y[i] * delta[4];
			weights[2][4] += alpha * Y[i] * delta[4];
			theta[4] += alpha * (-1)*delta[4];

			//	summing errors
			tX[3] = (x[1][i] * weights[1][3]) + (x[2][i] * weights[2][3]);
			tY[3] = SigmoidFunction(tX[3], theta[3]);
			tX[4] = (x[1][i] * weights[1][4]) + (x[2][i] * weights[2][4]);
			tY[4] = SigmoidFunction(tX[4], theta[4]);
			tX[5] = (tY[3] * weights[3][5]) + (tY[4] * weights[4][5]);
			tY[5] = SigmoidFunction(tX[5], theta[5]);
			te5 = Yd5[i] - tY[5];
			//Squared error
			EpocSumError += pow(te5, 2);
			p += 1;

			std::cout << "epoch Error : " << EpocSumError << std::endl;
		}
		//training end goes here
				
	}
		

}