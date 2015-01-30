#ifndef RANDOM_H
#define RANDOM_H

class Random
{
	public:
		static const int numbersTotal = 1000;
                static const int lambda = 75;
                
		double generatedNumbers[numbersTotal];

		double generateRanNum();
		double generateExponentialRanVar();
		double generateExponentialRanVar(int lambda);
                double generateExponentialRanVar(double lambda);
		void variableTest();
		
};
#endif

