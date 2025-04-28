#ifndef GMATH_HPP
# define GMATH_HPP

# include <cmath>
# include <iostream>

namespace gm {
	// Include functions
	# include <gmath/utils.hpp>
	# include <gmath/random.hpp>

	// Include vectors
	# include <gmath/Vec2.hpp>
	# include <gmath/Vec3.hpp>
	# include <gmath/Vec4.hpp>

	// Include matrix
	# include <gmath/Mat2.hpp>
	# include <gmath/Mat3.hpp>
	# include <gmath/Mat4.hpp>

	// Vector matrix operations
	# include <gmath/VecMat.hpp>

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
