#ifndef GM_UTILS_HPP
# define GM_UTILS_HPP

# include <cmath>

//**** VARIABLES ***************************************************************

static const double	GM_PI_180 = M_PI / 180;
static const double	GM_180_PI = 180 / M_PI;

//**** FUNCTIONS ***************************************************************

namespace gm {
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
		if (a < b)
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
		if (value < static_cast<T>(0))
			return (-value);
		return (value);
	}

	/**
	 * @brief Get sign of value.
	 *
	 * @param value Input value.
	 *
	 * @return Sign of value (-1, 1 or 0).
	 */
	template <typename T>
	T	sign(const T &value)
	{
		T	zero = static_cast<T>(0);

		if (value < zero)
			return (static_cast<T>(-1));
		else if (value > zero)
			return (static_cast<T>(1));
		return (zero);
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
		return (degrees * GM_PI_180);
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
		return (radians * GM_180_PI);
	}
}

#endif
