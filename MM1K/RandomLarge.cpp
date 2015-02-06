//ece 358

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <math.h>
#include <iomanip>

#include "Random.h"
#include "Queue.h"

//using namespace std;

Random::Random()
{
    
}

double Random::generateRanNum()
{
	return (rand() / (double)(RAND_MAX));
}

double Random::generateExponentialRanVar(double lambda)
{
	return ((double)(-1.0)/lambda)*log(1.0-generateRanNum());
}

void Random::variableTest()
{
	double number, total, total2, mean, variance;
	total = 0;
	for(int i = 0; i < numbersTotal; i++)
	{
		number = generateExponentialRanVar(75.0);
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

/**
 rho = lambda*L/C
 * 
 */
        
int main()
{
//  For M/M/1/K:?
	std::cout<<"M/M/1/K"<<std::endl;
	srand(time(0));
	int k[3] = {5,10,40};
	std::cout<<std::setw(8)<<std::endl<<"Rho";
	std::cout<<std::setw(8)<<", K= 5";
	std::cout<<std::setw(8)<<", K=10";
	std::cout<<std::setw(8)<<", K=40"<<std::endl;
	/*
	for(double ro = 0.50; ro <=1.51; ro+= 0.1)
	{
		std::cout<<std::setw(8)<<std::endl<<ro << ",";
		for(int i = 0; i < (sizeof k / sizeof *k); i++)
		{
			Queue *q = new Queue();
			q->setT(10000);
			double C=q->setC(1000000.0);
			double L=q->setL(12000.0);
			q->setLambda(ro/(double)L*C);
			q->setK(k[i]);
			//std::cout<<std::endl<<"Rho = "<<ro<<std::endl;
			//std::cout<<"K = "<<q->k_size<<std::endl;
			//std::cout<<"L = "<<L<<std::endl;
			//std::cout<<"C = "<<C<<std::endl;
			//std::cout<<"lambda = "<<q->lambda<<std::endl;
			q->simulate();
			std::cout<<",";
			delete q;		
		}
	}
	std::cout<<std::endl;
	//return 0;
	*/
	/*
	for(double ro = 0.4; ro <1.99; ro+= 0.1)
	{
		std::cout<<std::setw(8)<<std::endl<<ro << ",";
		for(int i = 0; i < (sizeof k / sizeof *k); i++)
		{
			Queue *q = new Queue();
			q->setT(10000);
			double C=q->setC(1000000.0);
			double L=q->setL(12000.0);
			q->setLambda(ro/(double)L*C);
			q->setK(k[i]);
			//std::cout<<std::endl<<"Rho = "<<ro<<std::endl;
			//std::cout<<"K = "<<q->k_size<<std::endl;
			//std::cout<<"L = "<<L<<std::endl;
			//std::cout<<"C = "<<C<<std::endl;
			//std::cout<<"lambda = "<<q->lambda<<std::endl;
			q->simulate();
			std::cout<<",";
			delete q;		
		}
	}
	for(double ro = 2.0; ro <4.9; ro+= 0.2)
	{
		std::cout<<std::setw(8)<<std::endl<<ro << ",";
		for(int i = 0; i < (sizeof k / sizeof *k); i++)
		{
			Queue *q = new Queue();
			q->setT(10000);
			double C=q->setC(1000000.0);
			double L=q->setL(12000.0);
			q->setLambda(ro/(double)L*C);
			q->setK(k[i]);
			//std::cout<<std::endl<<"Rho = "<<ro<<std::endl;
			//std::cout<<"K = "<<q->k_size<<std::endl;
			//std::cout<<"L = "<<L<<std::endl;
			//std::cout<<"C = "<<C<<std::endl;
			//std::cout<<"lambda = "<<q->lambda<<std::endl;
			q->simulate();
			std::cout<<",";
			delete q;		
		}
	}
	*/
	for(double ro = 5.0; ro <=10.0; ro+= 0.4)
	{
		std::cout<<std::setw(8)<<std::endl<<ro << ",";
		for(int i = 0; i < (sizeof k / sizeof *k); i++)
		{
			Queue *q = new Queue();
			q->setT(10000);
			double C=q->setC(1000000.0);
			double L=q->setL(12000.0);
			q->setLambda(ro/(double)L*C);
			q->setK(k[i]);
			//std::cout<<std::endl<<"Rho = "<<ro<<std::endl;
			//std::cout<<"K = "<<q->k_size<<std::endl;
			//std::cout<<"L = "<<L<<std::endl;
			//std::cout<<"C = "<<C<<std::endl;
			//std::cout<<"lambda = "<<q->lambda<<std::endl;
			q->simulate();
			std::cout<<",";
			delete q;		
		}
	}
	std::cout<<std::endl;
	return 0;
}

