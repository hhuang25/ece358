#ifndef RANDOM_H
#define RANDOM_H

class Random
{
	public:
		const static int numbersTotal = 1000;
                
		double generatedNumbers[numbersTotal];
                Random();
		double generateRanNum();
		double generateExponentialRanVar();
		double generateExponentialRanVar(int lambda);
                double generateExponentialRanVar(double lambda);
                
		void variableTest();
		
};
#endif

