#ifndef RANDOM_H
#define RANDOM_H
#endif
class Random
{
	public:
		static const int numbersTotal = 1000;
		double generatedNumbers[numbersTotal];

		double generateRanNum();
		double generateExponentialRanVar();
		double generateExponentialRanVar(int lambda);
		void variableTest();
		
};