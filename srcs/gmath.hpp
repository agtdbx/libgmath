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
	/**
	 * @brief Linear interpolation between start and end.
	 *
	 * @param start Start of the linear interpolation.
	 * @param end End of the linear interpolation.
	 * @param range Factor of the linear interpolation. Must be between 0 and 1 for coherent result.
	 *
	 * @return Result of the linear interpolation.
	 */
	template <typename T>
	T	lerp(const T &start, const T &end, float range)
	{
		return (start + (end - start) * range);
	}

	/**
	 * @brief Linear interpolation between start and end.
	 *
	 * @param start Start of the linear interpolation.
	 * @param end End of the linear interpolation.
	 * @param range Factor of the linear interpolation. Must be between 0 and 1 for coherent result.
	 *
	 * @return Result of the linear interpolation.
	 */
	template <typename T>
	T	lerp(const T &start, const T &end, double range)
	{
		return (start + (end - start) * range);
	}
}

#endif
