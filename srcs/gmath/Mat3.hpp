#ifndef GM_MAT3_HPP
# define GM_MAT3_HPP

# define GM_MAT3_SIZE 9

# include <gmath/Vec3.hpp>
# include <gmath/Mat2.hpp>

#include <cmath>
#include <iostream>
#include <stdexcept>

namespace gm {
	//**** STATIC FUNCTIONS DEFINE *********************************************
	//**** CLASS DEFINE ********************************************************

	/**
	 * @brief Class for 3x3 matrix.
	 *
	 * @tparam T Type of value in the matrix.
	 *
	 * The class is design to be used with graphic library like OpenGL or Vulkan.
	 */
	template <typename T>
	class Mat3
	{
	public:
		T	values[GM_MAT3_SIZE];

		//**** INITIALISION ****************************************************
		//---- Constructors ----------------------------------------------------

		/**
		 * @brief Default constructor of Mat3 class.
		 *
		 * @return The Mat3 with values at 0.
		 */
		Mat3(void)
		{
			for (int i = 0; i < GM_MAT3_SIZE; i++)
				this->values[i] = T();
		}

		/**
		 * @brief Copy constructor of Mat3 class.
		 *
		 * @param mat3 The Mat3 to copy.
		 *
		 * @return The Mat3 copied from parameter.
		 */
		Mat3(const Mat3 &mat3)
		{
			for (int i = 0; i < GM_MAT3_SIZE; i++)
				this->values[i] = mat3.values[i];
		}

		/**
		 * @brief Constructor of Mat3 class from an array.
		 *
		 * @param values Values in array form.
		 *
		 * @return Mat3 values of the array.
		 */
		Mat3(const T values[GM_MAT3_SIZE])
		{
			for (int i = 0; i < GM_MAT3_SIZE; i++)
				this->values[i] = values[i];
		}

		/**
		 * @brief Constructor of Mat3 class from parameters.
		 *
		 * @param x1 Value at (0,0).
		 * @param x2 Value at (1,0).
		 * @param x3 Value at (2,0).
		 * @param y1 Value at (0,1).
		 * @param y2 Value at (1,1).
		 * @param y3 Value at (2,1).
		 * @param z1 Value at (0,2).
		 * @param z2 Value at (1,2).
		 * @param z3 Value at (2,2).
		 *
		 * @return Mat3 values of parameters.
		 */
		Mat3(T x1, T x2, T x3, T y1, T y2, T y3, T z1, T z2, T z3)
		{
			this->values[0] = x1;
			this->values[1] = x2;
			this->values[2] = x3;
			this->values[3] = y1;
			this->values[4] = y2;
			this->values[5] = y3;
			this->values[6] = z1;
			this->values[7] = z2;
			this->values[8] = z3;
		}

		/**
		 * @brief Constructor of Mat3 class from Mat2.
		 *
		 * @param mat2 Mat2 to base on.
		 *
		 * @return Mat3 with x1, x2, y1 and y2 from mat2, other value to 0.
		 */
		Mat3(const Mat2<T> &mat2)
		{
			this->values[0] = mat2.values[0];
			this->values[1] = mat2.values[1];
			this->values[2] = T();
			this->values[3] = mat2.values[2];
			this->values[4] = mat2.values[3];
			this->values[5] = T();
			this->values[6] = T();
			this->values[7] = T();
			this->values[8] = T();
		}

		/**
		 * @brief Constructor of Mat3 class scaling.
		 *
		 * @param scale Values in array form.
		 *
		 * @return Mat3 identity * scale.
		 */
		Mat3(T scale)
		{
			this->values[0] = scale;
			this->values[1] = T();
			this->values[2] = T();
			this->values[3] = T();
			this->values[4] = scale;
			this->values[5] = T();
			this->values[6] = T();
			this->values[7] = T();
			this->values[8] = scale;
		}

		//---- Destructor ------------------------------------------------------

		~Mat3()
		{
		}

		//**** ACCESSORS *******************************************************
		//---- Getters ---------------------------------------------------------

		/**
		 * @brief Getter of Mat3.
		 *
		 * @param x x index, must in range [0, 2].
		 * @param y y index, must in range [0, 2].
		 *
		 * @return The value at position (x,y).
		 * @exception Throw a runtime_error when x and y isn't in range [0, 2].
		 */
		T	get(unsigned int x, unsigned int y) const
		{
			if (x >= 3 || y >= 3)
				throw std::runtime_error("Index out of mat3 bounds");
			return (this->values[x + y * 3]);
		}

		/**
		 * @brief Accessor of Mat3.
		 *
		 * @warning No check of x and y, will crash if isn't in range [0, 2].
		 *
		 * @param x x index, must in range [0, 2].
		 * @param y y index, must in range [0, 2].
		 *
		 * @return The reference of value at position (x,y).
		 */
		T	&at(unsigned int x, unsigned int y)
		{
			return (this->values[x + y * 3]);
		}

		/**
		 * @brief Const accessor of Mat3.
		 *
		 * @warning No check of x and y, will crash if isn't in range [0, 2].
		 *
		 * @param x x index, must in range [0, 2].
		 * @param y y index, must in range [0, 2].
		 *
		 * @return The const reference of value at position (x,y).
		 */
		const T	&at(unsigned int x, unsigned int y) const
		{
			return (this->values[x + y * 3]);
		}

		//---- Setters ---------------------------------------------------------

		/**
		 * @brief Setter of Mat3.
		 *
		 * @param x x index, must in range [0, 2].
		 * @param y y index, must in range [0, 2].
		 * @param value The value to set.
		 *
		 * @exception Throw a runtime_error when x and y isn't in range [0, 2].
		 */
		void	set(unsigned int x, unsigned int y, const T &value)
		{
			if (x >= 3 || y >= 3)
				throw std::runtime_error("Index out of mat3 bounds");
			this->values[x + y * 3] = value;
		}

		//---- Modify Operators ------------------------------------------------

		Mat3	&operator=(const Mat3 &mat3)
		{
			if (this == &mat3)
				return (*this);

			for (int i = 0; i < GM_MAT3_SIZE; i++)
				this->values[i] = mat3.values[i];

			return (*this);
		}

		Mat3	&operator+=(const Mat3 &mat3)
		{
			for (int i = 0; i < GM_MAT3_SIZE; i++)
				this->values[i] += mat3.values[i];

			return (*this);
		}

		Mat3	&operator-=(const Mat3 &mat3)
		{
			for (int i = 0; i < GM_MAT3_SIZE; i++)
				this->values[i] -= mat3.values[i];

			return (*this);
		}

		Mat3	&operator*=(const T &value)
		{
			for (int i = 0; i < GM_MAT3_SIZE; i++)
				this->values[i] *= value;

			return (*this);
		}

		Mat3	&operator/=(const T &value)
		{
			for (int i = 0; i < GM_MAT3_SIZE; i++)
				this->values[i] /= value;

			return (*this);
		}

		//---- Compare Operators -----------------------------------------------

		bool	operator==(const Mat3 &mat3) const
		{
			for (int i = 0; i < GM_MAT3_SIZE; i++)
				if (this->values[i] != mat3.values[i])
					return (false);

			return (true);
		}

		bool	operator!=(const Mat3 &mat3) const
		{
			for (int i = 0; i < GM_MAT3_SIZE; i++)
				if (this->values[i] != mat3.values[i])
					return (true);

			return (false);
		}

		//---- Accessor Operators ----------------------------------------------

		/**
		 * @brief Access values by index.
		 *
		 * @param n The id of value in array style. Id is (x + y * 3).
		 *
		 * @return The reference of value at array position n.
		 * @exception Throw a runtime_error if n isn't in range [0, 8].
		 */
		T	&operator[](unsigned int n)
		{
			if (n >= GM_MAT3_SIZE)
				throw std::runtime_error("Index out of mat3 bounds");

			return (this->values[n]);
		}

		/**
		 * @brief Const access values by index.
		 *
		 * @param n The id of value in array style. Id is (x + y * 3).
		 *
		 * @return The const reference of value at array position n.
		 * @exception Throw a runtime_error if n isn't in range [0, 8].
		 */
		const T	&operator[](unsigned int n) const
		{
			if (n >= GM_MAT3_SIZE)
				throw std::runtime_error("Index out of mat3 bounds");

			return (this->values[n]);
		}

		/**
		 * @brief Const access values by index.
		 *
		 * @warning No check of x and y, will crash if isn't in range [0, 2].
		 *
		 * @param vec2 The index of value in Vec2u.
		 *
		 * @return The const reference of value at position (x,y).
		 */
		const T	&operator[](const Vec2u &vec2) const
		{
			return (this->values[vec2.x + vec2.y * 3]);
		}

		/**
		 * @brief Access values by index.
		 *
		 * @warning No check of x and y, will crash if isn't in range [0, 2].
		 *
		 * @param vec2 The index of value in Vec2u.
		 *
		 * @return The reference of value at position (x,y).
		 */
		T	&operator[](const Vec2u &vec2)
		{
			return (this->values[vec2.x + vec2.y * 3]);
		}

		//**** PUBLIC METHODS **************************************************

		/**
		 * @brief Create a Mat2 from a subpart of the Mat3.
		 *
		 * @return A Mat2 with x1, x2, y1 and y2 as values.
		 */
		Mat2<T>	asMat2(void) const
		{
			Mat2<T>	res;

			res.values[0] = this->values[0];
			res.values[1] = this->values[1];
			res.values[2] = this->values[3];
			res.values[3] = this->values[4];

			return (res);
		}

		//**** STATIC METHODS **************************************************

		/**
		 * @brief Create the 3x3 identity matrix.
		 *
		 * @return 3x3 identity matrix.
		 */
		static Mat3<T>	identity(void)
		{
			Mat3<T>	res;

			res.values[0] = static_cast<T>(1);
			res.values[4] = static_cast<T>(1);
			res.values[8] = static_cast<T>(1);

			return (res);
		}

		/**
		 * @brief Create 3x3 rotation matrix.
		 *
		 * @param axis Vec3 to tell on wich axis the rotation will be done. It must be normalized.
		 * @param radians The angle in radians.
		 *
		 * @return 3x3 rotation matrix of parameter.
		 */
		static Mat3<T>	rotation(const Vec3<T> &axis, T radians)
		{
			Mat3<T>	res;
			T		tmpCos = static_cast<T>(cos(static_cast<double>(-radians)));
			T		tmpSin = static_cast<T>(sin(static_cast<double>(-radians)));
			T		invTmpCos = static_cast<T>(1) - tmpCos;
			T		tmpSinAx = tmpSin * axis.x;
			T		tmpSinAy = tmpSin * axis.y;
			T		tmpSinAz = tmpSin * axis.z;

			// Line 1
			res.values[0] = (axis.x * axis.x) * invTmpCos + tmpCos;
			res.values[1] = (axis.x * axis.y) * invTmpCos - tmpSinAz;
			res.values[2] = (axis.x * axis.z) * invTmpCos + tmpSinAy;
			// Line 2
			res.values[3] = (axis.y * axis.x) * invTmpCos + tmpSinAz;
			res.values[4] = (axis.y * axis.y) * invTmpCos + tmpCos;
			res.values[5] = (axis.y * axis.z) * invTmpCos - tmpSinAx;
			// Line 3
			res.values[6] = (axis.z * axis.x) * invTmpCos - tmpSinAy;
			res.values[7] = (axis.z * axis.y) * invTmpCos + tmpSinAx;
			res.values[8] = (axis.z * axis.z) * invTmpCos + tmpCos;

			return (res);
		}

	private:

	};

	//**** EXTERNS OPERATORS ***************************************************
	//---- Matrix matrix operator ----------------------------------------------

	template <typename T>
	Mat3<T>	operator+(const Mat3<T> &m1, const Mat3<T> &m2)
	{
		Mat3<T>	res;

		for (int i = 0; i < GM_MAT3_SIZE; i++)
			res.values[i] = m1.values[i] + m2.values[i];

		return (res);
	}

	template <typename T>
	Mat3<T>	operator-(const Mat3<T> &m1, const Mat3<T> &m2)
	{
		Mat3<T>	res;

		for (int i = 0; i < GM_MAT3_SIZE; i++)
			res.values[i] = m1.values[i] - m2.values[i];

		return (res);
	}

	/**
	 * @brief Matrix multiplication between 2 Mat3.
	 *
	 * @param m1 First matrix.
	 * @param m2 Second matrix.
	 *
	 * @return Result of m1 * m2.
	 */
	template <typename T>
	Mat3<T>	operator*(const Mat3<T> &m1, const Mat3<T> &m2)
	{
		Mat3<T>	res;

		res.values[0] = m1.values[0] * m2.values[0] + m1.values[1] * m2.values[3] + m1.values[2] * m2.values[6];
		res.values[1] = m1.values[0] * m2.values[1] + m1.values[1] * m2.values[4] + m1.values[2] * m2.values[7];
		res.values[2] = m1.values[0] * m2.values[2] + m1.values[1] * m2.values[5] + m1.values[2] * m2.values[8];
		res.values[3] = m1.values[3] * m2.values[0] + m1.values[4] * m2.values[3] + m1.values[5] * m2.values[6];
		res.values[4] = m1.values[3] * m2.values[1] + m1.values[4] * m2.values[4] + m1.values[5] * m2.values[7];
		res.values[5] = m1.values[3] * m2.values[2] + m1.values[4] * m2.values[5] + m1.values[5] * m2.values[8];
		res.values[6] = m1.values[6] * m2.values[0] + m1.values[7] * m2.values[3] + m1.values[8] * m2.values[6];
		res.values[7] = m1.values[6] * m2.values[1] + m1.values[7] * m2.values[4] + m1.values[8] * m2.values[7];
		res.values[8] = m1.values[6] * m2.values[2] + m1.values[7] * m2.values[5] + m1.values[8] * m2.values[8];

		return (res);
	}

	//---- Matrix value operator -----------------------------------------------

	template <typename T>
	Mat3<T>	operator*(const Mat3<T> &mat3, const T &value)
	{
		Mat3<T>	res;

		for (int i = 0; i < GM_MAT3_SIZE; i++)
			res.values[i] = mat3.values[i] * value;

		return (res);
	}

	template <typename T>
	Mat3<T>	operator*(const T &value, const Mat3<T> &mat3)
	{
		Mat3<T>	res;

		for (int i = 0; i < GM_MAT3_SIZE; i++)
			res.values[i] = mat3.values[i] * value;

		return (res);
	}

	template <typename T>
	Mat3<T>	operator/(const Mat3<T> &mat3, const T &value)
	{
		Mat3<T>	res;

		for (int i = 0; i < GM_MAT3_SIZE; i++)
			res.values[i] = mat3.values[i] / value;

		return (res);
	}

	//---- Print operator ------------------------------------------------------

	template <typename T>
	std::ostream	&operator<<(std::ostream &os, const Mat3<T> &mat3)
	{
		os << "|(" << mat3.values[0] << "," << mat3.values[1] << "," << mat3.values[2]
			<< ");(" << mat3.values[3] << "," << mat3.values[4] << "," << mat3.values[5]
			<< ");(" << mat3.values[6] << "," << mat3.values[7] << "," << mat3.values[8] << ")|";
		return (os);
	}

	//**** FUNCTIONS ***********************************************************

	/**
	 * @brief Rotate a Mat3.
	 *
	 * @param mat3 The Mat3 to rotate.
	 * @param axis Vec3 to tell on wich axis the rotation will be done. It must be normalized.
	 * @param radians The angle in radians.
	 *
	 * @return Mat3 rotate by axis and angle in radians.
	 */
	template <typename T>
	Mat3<T>	rotate(const Mat3<T> &mat3, const Vec3<T> &axis, T radians)
	{
		const Mat3<T>	matRot = Mat3<T>::rotation(axis, radians);

		return (mat3 * matRot);
	}

	//**** STATIC FUNCTIONS ****************************************************
	//**** USINGS **************************************************************

	/**
	 * @brief Class for 3x3 unsigned int matrix.
	 *
	 * The class is design to be used with graphic library like OpenGL or Vulkan.
	 */
	using Mat3u = Mat3<unsigned int>;
	/**
	 * @brief Class for 3x3 int matrix.
	 *
	 * The class is design to be used with graphic library like OpenGL or Vulkan.
	 */
	using Mat3i = Mat3<int>;
	/**
	 * @brief Class for 3x3 float matrix.
	 *
	 * The class is design to be used with graphic library like OpenGL or Vulkan.
	 */
	using Mat3f = Mat3<float>;
	/**
	 * @brief Class for 3x3 double matrix.
	 *
	 * The class is design to be used with graphic library like OpenGL or Vulkan.
	 */
	using Mat3d = Mat3<double>;
}

#endif
