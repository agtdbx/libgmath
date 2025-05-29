#ifndef GM_INVERSE_HPP
# define GM_INVERSE_HPP

# include <gmath/Mat2.hpp>
# include <gmath/Mat3.hpp>
# include <gmath/Mat4.hpp>

# include <cmath>

//**** VARIABLES ***************************************************************

//**** FUNCTIONS ***************************************************************

namespace gm {
//**** MATX ********************************************************************
//---- Utils -------------------------------------------------------------------
	/**
	 * @brief Internal function for inverse. Multiply matrix line by a value.
	 *
	 * @tparam MAT The matrix class.
	 * @tparam T The value into matrix class.
	 * @param size Size of matrix.
	 * @param mat1 The matrix to change.
	 * @param mat2 The second matrix to change.
	 * @param y The line y coordonates.
	 * @param mult The value to multiply.
	 */
	template <template<class> class MAT, typename T>
	void	__mutiply_line(
				int size, MAT<T> &mat1, MAT<T> &mat2,
				int y, const T &mult)
	{
		const int	ly = y * size;
		for (int i = 0; i < size; i++)
		{
			mat1.values[ly + i] *= mult;
			mat2.values[ly + i] *= mult;
		}
	}
	/**
	 * @brief Internal function for inverse. Add matrix line with an other.
	 *
	 * @tparam MAT The matrix class.
	 * @tparam T The value into matrix class.
	 * @param size Size of matrix.
	 * @param mat1 The matrix to change.
	 * @param mat2 The second matrix to change.
	 * @param l1 The line id to modify.
	 * @param l2 The line id to add.
	 * @param l2Mult The value to multiply l2 before add it to l1.
	 */
	template <template<class> class MAT, typename T>
	void	__add_line(
				int size, MAT<T> &mat1, MAT<T> &mat2,
				int l1, int l2, const T &l2Mult)
	{
		const int	l1y = l1 * size;
		const int	l2y = l2 * size;
		for (int i = 0 * size; i < size; i++)
		{
			mat1.values[l1y + i] += mat1.values[l2y + i] * l2Mult;
			mat2.values[l1y + i] += mat2.values[l2y + i] * l2Mult;
		}
	}
	/**
	 * @brief Internal function for inverse. Swap 2 matrix line.
	 *
	 * @tparam MAT The matrix class.
	 * @tparam T The value into matrix class.
	 * @param size Size of matrix.
	 * @param mat1 The matrix to change.
	 * @param mat2 The second matrix to change.
	 * @param l1 The line id to swap.
	 * @param l2 The line id to swap with.
	 */
	template <template<class> class MAT, typename T>
	void	__swap_line(
				int size, MAT<T> &mat1, MAT<T> &mat2,
				int l1, int l2)
	{
		const int	l1y = l1 * size;
		const int	l2y = l2 * size;
		int	tmp;
		for (int i = 0 * size; i < size; i++)
		{
			tmp = mat1.values[l1y + i];
			mat1.values[l1y + i] = mat1.values[l2y + i];
			mat1.values[l2y + i] = tmp;

			tmp = mat2.values[l1y + i];
			mat2.values[l1y + i] = mat2.values[l2y + i];
			mat2.values[l2y + i] = tmp;
		}
	}

//---- Function ----------------------------------------------------------------
	/**
	 * @brief Internal function for inverse. Inverse the matrix.
	 *
	 * @tparam MAT The matrix class.
	 * @tparam T The value into matrix class.
	 * @param size Size of matrix.
	 * @param mat The matrix to inverse.
	 *
	 * @exception Throw an runtime_error if the matrix isn't inversable.
	 * @return The inverse matrix.
	 */
	template <template<class> class MAT, typename T>
	MAT<T>	__inverse(int size, const MAT<T> &mat)
	{
		if (mat.determinant() == static_cast<T>(0))
			throw std::runtime_error("Matrix cannot be inverse");

		MAT<T>	copy = mat;
		MAT<T>	res = MAT<T>::identity();
		const	T	zero = static_cast<T>(0);
		const	T	one = static_cast<T>(1);

		int		diag = 0;
		T		diagVal;
		int		y;
		T		tmp;

		while (diag < size)
		{
			// Check which line take
			diagVal = copy.values[diag * size + diag];
			if (diagVal == zero)
			{
				y = diag + 1;

				while (y < size)
				{
					diagVal = copy.values[y * size + diag];
					if (diagVal != zero)
						break;
					y++;
				}

				if (y == size)
					throw std::runtime_error("Matrix inverse error");

				__swap_line(size, copy, res, diag, y);
			}

			// Put diagonal number to 1
			if (diagVal != one)
			{
				T	inv = one / diagVal;
				__mutiply_line(size, copy, res, diag, inv);
			}

			// Put 0 above diagonal number
			y = diag - 1;
			while (y >= 0)
			{
				tmp = copy.values[y * size + diag];
				if (tmp != zero)
					__add_line(size, copy, res, y, diag, -tmp);
				y--;
			}

			// Put 0 bellow diagonal number
			y = diag + 1;
			while (y < size)
			{
				tmp = copy.values[y * size + diag];
				if (tmp != zero)
					__add_line(size, copy, res, y, diag, -tmp);
				y++;
			}

			diag++;
		}

		return (res);
	}


//**** Typed function **********************************************************
//---- Mat2 --------------------------------------------------------------------
	/**
	 * @brief Inverse the 2x2 matrix.
	 *
	 * @tparam T The value into matrix class.
	 * @param mat The matrix to inverse.
	 *
	 * @exception Throw an runtime_error if the matrix cannot be inverse.
	 * @return The inverse matrix.
	 */
	template <typename T>
	Mat2<T>	inverse(const Mat2<T> &mat)
	{
		return	(__inverse(2, mat));
	}

//---- Mat3 --------------------------------------------------------------------
	/**
	 * @brief Inverse the 3x3 matrix.
	 *
	 * @tparam T The value into matrix class.
	 * @param mat The matrix to inverse.
	 *
	 * @exception Throw an runtime_error if the matrix cannot be inverse.
	 * @return The inverse matrix.
	 */
	template <typename T>
	Mat3<T>	inverse(const Mat3<T> &mat)
	{
		return	(__inverse(3, mat));
	}

//---- Mat4 --------------------------------------------------------------------
	/**
	 * @brief Inverse the 4x4 matrix.
	 *
	 * @tparam T The value into matrix class.
	 * @param mat The matrix to inverse.
	 *
	 * @exception Throw an runtime_error if the matrix cannot be inverse.
	 * @return The inverse matrix.
	 */
	template <typename T>
	Mat4<T>	inverse(const Mat4<T> &mat)
	{
		return	(__inverse(4, mat));
	}
}

#endif
