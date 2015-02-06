//ece 358

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <math.h>

#include "Random.h"
#include "Queue.h"

//using namespace std;

Random::Random()
{
    
}

double Random::generateRanNum()
{
	return (double)rand()/((double)RAND_MAX + 1);
}

double Random::generateExponentialRanVar(double lambda)
{
	return ((-1.0)/lambda)*log(1.0-generateRanNum());
}

void Random::variableTest()
{
	double number, total, total2, mean, variance;
	total = 0.0;
	for(int i = 0; i < numbersTotal; i++)
	{
		number = generateExponentialRanVar(75);
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
	std::cout<< "Variance: " << variance<<std::endl;
}

/**
 rho = lambda*L/C
 * 
 */
        
int main()
{
//  For M/M/1: when p = 0.25s, E[N] = 1/3, P_idle = 0.75
	srand(time(NULL));
	Random *random = new Random();
	random->variableTest();
	delete random;
	return 0;
	/*
	for(double ro = 0.25; ro <=0.95; ro+= 0.1)
	{
		Queue *q = new Queue();
		q->setT(10000);
		double C=q->setC(1000000.0);
		double L=q->setL(12000.0);
		q->setLambda(ro/(double)L*C);
		std::cout<<std::endl<<"Rho = "<<ro<<std::endl;
		//std::cout<<"L = "<<L<<std::endl;
		//std::cout<<"C = "<<C<<std::endl;
		std::cout<<"lambda = "<<q->lambda<<std::endl;
		q->simulate();
		delete q;
	}
	*/
	for(double ro = 1.2; ro <=1.2; ro+= 0.1)
	{
		Queue *q = new Queue();
		// Random *random = new Random();
		// std::cout<< random->generateExponentialRanVar(1.0/12000)<< std::endl;
		// random->variableTest();
		// delete random;
		// return 0;
		q->setT(10000);
		double C=q->setC(1000000.0);
		double L=q->setL(12000.0);
		q->setLambda(ro/(double)L*C);
		std::cout<<std::endl<<"Rho = "<<ro<<std::endl;
		//std::cout<<"L = "<<L<<std::endl;
		//std::cout<<"C = "<<C<<std::endl;
		std::cout<<"lambda = "<<q->lambda<<std::endl;
		q->simulate();
		delete q;
	}
	return 0;
}

