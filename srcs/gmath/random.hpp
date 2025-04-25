#ifndef RANDOM_HPP
# define RANDOM_HPP

void			initRandom(void);
void			initRandom(unsigned int seed);
int				iRand(void);
int				iRand(int min, int max);
unsigned int	uRand(void);
unsigned int	uRand(unsigned int min, unsigned int max);
float			fRand(void);
float			fRand(float min, float max);
double			dRand(void);
double			dRand(double min, double max);

#endif
