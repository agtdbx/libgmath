#ifndef GMATH_HPP
# define GMATH_HPP

# include <iostream>

namespace gm {
	// Include functions
	# include <gmath/utils.hpp>
	# include <gmath/random.hpp>

	// Include vectors
	# include <gmath/Vec2.hpp>

	// Include matrix

	// Functions
	template <typename T>
	T	lerp(const T &start, const T &end, float range)
	{
		return (start + (end - start) * range);
	}

	template <typename T>
	T	lerp(const T &start, const T &end, double range)
	{
		return (start + (end - start) * range);
	}

}

#endif
