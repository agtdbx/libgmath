#ifndef RANDOM_HPP
# define RANDOM_HPP

/**
 * @brief Init random with random seed (based on time).
 *
 * @return The random seed used.
 */
unsigned int	initRandom(void);

/**
 * @brief Init random with random seed (based on time).
 *
 * @param seed The seed used for random.
 */
void	initRandom(unsigned int seed);

/**
 * @brief Random for int.
 *
 * @return Random integer in range [0, RAND_MAX].
 */
int	iRand(void);

/**
 * @brief Random for int between min and max.
 *
 * @param min Lower bound of random range.
 * @param max Upper bound of random range.
 *
 * @return Random integer in range [min, max].
 */
int	iRand(int min, int max);

/**
 * @brief Random for unsigned int.
 *
 * @return Random unsigned integer in range [0, RAND_MAX].
 */
unsigned int	uRand(void);

/**
 * @brief Random for unsigned int between min and max.
 *
 * @param min Lower bound of random range.
 * @param max Upper bound of random range.
 *
 * @return Random unsigned integer in range [min, max].
 */
unsigned int	uRand(unsigned int min, unsigned int max);

/**
 * @brief Random for float.
 *
 * @return Random float in range [0, 1].
 */
float	fRand(void);

/**
 * @brief Random for float int between min and max.
 *
 * @param min Lower bound of random range.
 * @param max Upper bound of random range.
 *
 * @return Random float in range [min, max].
 */
float	fRand(float min, float max);

/**
 * @brief Random for double.
 *
 * @return Random double in range [0, 1].
 */
double	dRand(void);

/**
 * @brief Random for double int between min and max.
 *
 * @param min Lower bound of random range.
 * @param max Upper bound of random range.
 *
 * @return Random double in range [min, max].
 */
double	dRand(double min, double max);

#endif
