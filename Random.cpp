//ece 358

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <math.h>

#include "Random.h"
#include "Queue.h"

//using namespace std;

double Random::generateRanNum()
{
	return (rand() / (double)(RAND_MAX+1));
}

double Random::generateExponentialRanVar()
{
	//expected mean = 1/ lambda = 1/75 = 0.013333
	//expected variance = 1/lambda^2 = 1/5625 = 0.000177778
	return generateExponentialRanVar(75);
}

double Random::generateExponentialRanVar(int lambda)
{
	return ((double)(-1)/(double)lambda)*log(1-generateRanNum());
}

void Random::variableTest()
{
	double number, total, total2, mean, variance;
	total = 0;
	for(int i = 0; i < numbersTotal; i++)
	{
		number = generateExponentialRanVar();
		total += number;
		generatedNumbers[i] = number;
	}
	mean = total / numbersTotal;
	for(int i = 0; i < numbersTotal; i++)
	{
		total2 += (generatedNumbers[i] - mean) * (generatedNumbers[i] - mean);
	}
	variance = total2 / numbersTotal;
	//variance = ((pow((total-(total-numbersTotal)),2))/numbersTotal);
	
	std::cout<< "Numbers:" << std::endl;
	for(int i = 0; i < numbersTotal; i++)
	{
		std::cout<< generatedNumbers[i] << "\n";
	}
	std::cout<< "Mean: " << mean << "\n";
	std::cout<< "Variance: " << variance;
}

int main()
{
	srand(time(0));
	Random *random = new Random();
	//random->generateExponentialRanVar();
	delete random;
	Queue *q = new Queue();
	q->simulate();
	delete q;
	return 0;
}


