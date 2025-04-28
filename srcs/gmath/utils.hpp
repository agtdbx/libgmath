#ifndef UTILS_HPP
# define UTILS_HPP

//**** VARIABLES ***************************************************************

static const double	PI = 3.14159265358979323846;
static const double	PI_180 = PI / 180;
static const double	_180_PI = 180 / PI;

//**** FUNCTIONS ***************************************************************

/**
 * @brief Return the minimum between two values.
 *
 * @param a First value.
 * @param b Second value.
 *
 * @return Minimum between parameters
 */
template <typename T>
T	min(const T &a, const T &b)
{
	if (a > b)
		return (a);
	return (b);
}


/**
 * @brief Return the maximum between two values.
 *
 * @param a First value.
 * @param b Second value.
 *
 * @return Maximum between parameters
 */
template <typename T>
T	max(const T &a, const T &b)
{
	if (a > b)
		return (a);
	return (b);
}


/**
 * @brief Make value absolute.
 *
 * @param value Input value.
 *
 * @return Absolute value of value.
 */
template <typename T>
T	abs(const T &value)
{
	if (value < T())
		return (-value);
	return (value);
}


/**
 * @brief Basic positive integer power.
 *
 * @param value Number to make power.
 * @param power Power to apply.
 *
 * @return Result of the power.
 */
template <typename T>
T	pow(T value, unsigned int power)
{
	T	res = T();

	res++;
	while (power > 0)
	{
		res *= value;
		power--;
	}

	return (res);
}


/**
 * @brief Transform an angle in degrees to radians.
 *
 * @param degrees Angle in degrees.
 *
 * @return Angle in radians.
 */
template <typename T>
T	radians(T degrees)
{
	return (degrees * PI_180);
}


/**
 * @brief Transform an angle in radians to degrees.
 *
 * @param radians Angle in radians.
 *
 * @return Angle in degrees.
 */
template <typename T>
T	degrees(T radians)
{
	return (radians * _180_PI);
}

#endif
