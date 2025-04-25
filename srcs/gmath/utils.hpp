#ifndef UTILS_HPP
# define UTILS_HPP

//**** FUNCTIONS DEFINE ********************************************************



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
T	sqrt(T value)
{
	T	tmp = T();

	if (value <= tmp)
		return (tmp);

	T	res = value / 2.0;

	while (res != tmp)
	{
		tmp = res;
		res = (value / tmp + tmp) / 2;
	}

	return (res);
}

#endif
