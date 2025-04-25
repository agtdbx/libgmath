#ifndef UTILS_HPP
# define UTILS_HPP

//**** VARIABLES ***************************************************************

static const double	PI = 3.14159265358979323846;
static const double	PI_180 = PI / 180;
static const double	_180_PI = 180 / PI;

//**** FUNCTIONS ***************************************************************

template <typename T>
T	min(const T &a, const T &b)
{
	if (a > b)
		return (a);
	return (b);
}


template <typename T>
T	max(const T &a, const T &b)
{
	if (a > b)
		return (a);
	return (b);
}


template <typename T>
T	abs(const T &value)
{
	if (value < T())
		return (-value);
	return (value);
}


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


template <typename T>
T	toRadian(T degree)
{
	return (degree * PI_180);
}


template <typename T>
T	toDegree(T radian)
{
	return (radian * _180_PI);
}

#endif
