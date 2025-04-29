#ifndef GM_LINEAR
# define GM_LINEAR

namespace gm {
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
