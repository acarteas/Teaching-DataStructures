#ifndef RANDOM_NUMBER_GENERATOR_H
#define RANDOM_NUMBER_GENERATOR_H
#include <cstdlib>
#include <ctime>
using namespace std;
class RandomNumberGenerator
{
public:
	RandomNumberGenerator(int seed = NULL)
	{
		//use time to randomize seed
		if (seed == NULL)
		{
			srand(time(NULL));
		}
		else
		{
			//else, use the supplied seed
			srand(seed);
		}
	}
	int getRandomNumber(int min_value = 0, int max_value = RAND_MAX) const
	{
		int next_number = (rand() % max_value) + min_value;
		return next_number;
	}
};

#endif