#include <gmath/random.hpp>

#include <cstdlib>
#include <ctime>

//**** STATIC VARIABLES ********************************************************

static const float	RAND_MAX_F = static_cast<float>(RAND_MAX);
static const double	RAND_MAX_D = static_cast<double>(RAND_MAX);

//**** FUNCTIONS ***************************************************************

unsigned int	initRandom(void)
{
	unsigned int	seed = time(NULL);

	srand(seed);

	return (seed);
}


void	initRandom(unsigned int seed)
{
	srand(seed);
}


int	iRand(void)
{
	return (rand());
}


int	iRand(int min, int max)
{
	return (rand() % (max - min) + min);
}


unsigned int	uRand(void)
{
	return (static_cast<unsigned int>(rand()));
}


unsigned int	uRand(unsigned int min, unsigned int max)
{
	return (uRand() % (max - min) + min);
}


float	fRand(void)
{
	return (static_cast<float>(rand()) / RAND_MAX_F);
}


float	fRand(float min, float max)
{
	return (min + fRand() * (max - min));
}


double	dRand(void)
{
	return (static_cast<double>(rand()) / RAND_MAX_D);
}


double	dRand(double min, double max)
{
	return (min + dRand() * (max - min));
}
