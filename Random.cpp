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
	return (rand() / (double)(RAND_MAX+1));
}

double Random::generateExponentialRanVar()
{
    int m_lambda = 75;
    //expected mean = 1/ lambda = 1/75 = 0.013333
    //expected variance = 1/lambda^2 = 1/5625 = 0.000177778
    return generateExponentialRanVar(m_lambda);
}

double Random::generateExponentialRanVar(int lambda)
{
	return ((double)(-1)/(double)lambda)*log(1-generateRanNum());
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

/**
 rho = lambda*L/C
 * 
 */
int main()
{
	srand(time(NULL));
//	Random *random = new Random();
//	std::cout<< random->generateExponentialRanVar(1.0/12000)<< std::endl;
//	delete random;
        
            Queue *q = new Queue();
        for(double ro = 0.25; ro <=0.25; ro+= 0.1)
        {
            q->setT(10000);
            int C=q->setC(1000000);
            int L=q->setL(12000);
            q->setLambda(ro/(double)L*C);
            std::cout<<std::endl<<"Rho = "<<ro<<std::endl;
            std::cout<<"L = "<<L<<std::endl;
            std::cout<<"C = "<<C<<std::endl;
            std::cout<<"lambda = "<<q->lambda<<std::endl;
            q->simulate();
        }
            delete q;
	return 0;
}

