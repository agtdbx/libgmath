#ifndef GM_MAT4_HPP
# define GM_MAT4_HPP

# define GM_MAT4_SIZE 16

# include <gmath/Vec3.hpp>
# include <gmath/Mat2.hpp>
# include <gmath/Mat3.hpp>
# include <gmath/utils.hpp>

#include <cmath>
#include <iostream>
#include <stdexcept>

namespace gm {
	//**** STATIC FUNCTIONS DEFINE *********************************************
	//**** CLASS DEFINE ********************************************************

	/**
	 * @brief Class for 4x4 matrix.
	 *
	 * @tparam T Type of value in the matrix.
	 *
	 * The class is design to be used with graphic library like OpenGL or Vulkan.
	 */
	template <typename T>
	class Mat4
	{
	public:
		T	values[GM_MAT4_SIZE];

		//**** INITIALISION ****************************************************
		//---- Constructors ----------------------------------------------------

		/**
		 * @brief Default constructor of Mat4 class.
		 *
		 * @return The Mat4 with values at 0.
		 */
		Mat4(void)
		{
			for (int i = 0; i < GM_MAT4_SIZE; i++)
				this->values[i] = T();
		}

		/**
		 * @brief Copy constructor of Mat4 class.
		 *
		 * @param mat4 The Mat4 to copy.
		 *
		 * @return The Mat4 copied from parameter.
		 */
		Mat4(const Mat4 &mat4)
		{
			for (int i = 0; i < GM_MAT4_SIZE; i++)
				this->values[i] = mat4.values[i];
		}

		/**
		 * @brief Constructor of Mat4 class from an array.
		 *
		 * @param values Values in array form.
		 *
		 * @return Mat4 values of the array.
		 */
		Mat4(const T values[GM_MAT4_SIZE])
		{
			for (int i = 0; i < GM_MAT4_SIZE; i++)
				this->values[i] = values[i];
		}

		/**
		 * @brief Constructor of Mat3 class from parameters.
		 *
		 * @param x1 Value at (0,0).
		 * @param x2 Value at (1,0).
		 * @param x3 Value at (2,0).
		 * @param x4 Value at (3,0).
		 * @param y1 Value at (0,1).
		 * @param y2 Value at (1,1).
		 * @param y3 Value at (2,1).
		 * @param y4 Value at (3,1).
		 * @param z1 Value at (0,2).
		 * @param z2 Value at (1,2).
		 * @param z3 Value at (2,2).
		 * @param z4 Value at (3,2).
		 * @param w1 Value at (0,3).
		 * @param w2 Value at (1,3).
		 * @param w3 Value at (2,3).
		 * @param w4 Value at (3,3).
		 *
		 * @return Mat3 values of parameters.
		 */
		Mat4(T x1, T x2, T x3, T x4,
				T y1, T y2, T y3, T y4,
				T z1, T z2, T z3, T z4,
				T w1, T w2, T w3, T w4)
		{
			this->values[ 0] = x1;
			this->values[ 1] = x2;
			this->values[ 2] = x3;
			this->values[ 3] = x4;

			this->values[ 4] = y1;
			this->values[ 5] = y2;
			this->values[ 6] = y3;
			this->values[ 7] = y4;

			this->values[ 8] = z1;
			this->values[ 9] = z2;
			this->values[10] = z3;
			this->values[11] = z4;

			this->values[12] = w1;
			this->values[13] = w2;
			this->values[14] = w3;
			this->values[15] = w4;
		}

		/**
		 * @brief Constructor of Mat4 class from Mat2.
		 *
		 * @param mat2 Mat2 to base on.
		 *
		 * @return Mat4 with x1, x2, y1 and y2 from mat2, other value to 0.
		 */
		Mat4(const Mat2<T> mat2)
		{
			this->values[ 0] = mat2.values[0];
			this->values[ 1] = mat2.values[1];
			this->values[ 2] = T();
			this->values[ 3] = T();

			this->values[ 4] = mat2.values[2];
			this->values[ 5] = mat2.values[3];
			this->values[ 6] = T();
			this->values[ 7] = T();

			this->values[ 8] = T();
			this->values[ 9] = T();
			this->values[10] = T();
			this->values[11] = T();

			this->values[12] = T();
			this->values[13] = T();
			this->values[14] = T();
			this->values[15] = T();
		}

		/**
		 * @brief Constructor of Mat4 class from Mat3.
		 *
		 * @param mat3 Mat3 to base on.
		 *
		 * @return Mat4 with x1, x2, x3, y1, y2, y3, z1, z2 and z3 from mat3, other value to 0.
		 */
		Mat4(const Mat3<T> mat3)
		{
			this->values[ 0] = mat3.values[0];
			this->values[ 1] = mat3.values[1];
			this->values[ 2] = mat3.values[2];
			this->values[ 3] = T();

			this->values[ 4] = mat3.values[3];
			this->values[ 5] = mat3.values[4];
			this->values[ 6] = mat3.values[5];
			this->values[ 7] = T();

			this->values[ 8] = mat3.values[6];
			this->values[ 9] = mat3.values[7];
			this->values[10] = mat3.values[8];
			this->values[11] = T();

			this->values[12] = T();
			this->values[13] = T();
			this->values[14] = T();
			this->values[15] = T();
		}

		/**
		 * @brief Constructor of Mat4 class scaling.
		 *
		 * @param scale Values in array form.
		 *
		 * @return Mat4 identity * scale.
		 */
		 Mat4(T scale)
		 {
			this->values[ 0] = scale;
			this->values[ 1] = T();
			this->values[ 2] = T();
			this->values[ 3] = T();

			this->values[ 4] = T();
			this->values[ 5] = scale;
			this->values[ 6] = T();
			this->values[ 7] = T();

			this->values[ 8] = T();
			this->values[ 9] = T();
			this->values[10] = scale;
			this->values[11] = T();

			this->values[12] = T();
			this->values[13] = T();
			this->values[14] = T();
			this->values[15] = scale;
		 }

		//---- Destructor ------------------------------------------------------

		~Mat4()
		{
		}

		//**** ACCESSORS *******************************************************
		//---- Getters ---------------------------------------------------------

		/**
		 * @brief Getter of Mat4.
		 *
		 * @param x x index, must in range [0, 3].
		 * @param y y index, must in range [0, 3].
		 *
		 * @return The value at position (x,y).
		 * @exception Throw a runtime_error when x and y isn't in range [0, 3].
		 */
		T	get(unsigned int x, unsigned int y) const
		{
			if (x >= 4 || y >= 4)
				throw std::runtime_error("Index out of mat4 bounds");
			return (this->values[x + y * 4]);
		}

		/**
		 * @brief Accessor of Mat4.
		 *
		 * @warning No check of x and y, will crash if isn't in range [0, 3].
		 *
		 * @param x x index, must in range [0, 3].
		 * @param y y index, must in range [0, 3].
		 *
		 * @return The reference of value at position (x,y).
		 */
		T	&at(unsigned int x, unsigned int y)
		{
			return (this->values[x + y * 4]);
		}

		/**
		 * @brief Const accessor of Mat4.
		 *
		 * @warning No check of x and y, will crash if isn't in range [0, 3].
		 *
		 * @param x x index, must in range [0, 3].
		 * @param y y index, must in range [0, 3].
		 *
		 * @return The const reference of value at position (x,y).
		 */
		const T	&at(unsigned int x, unsigned int y) const
		{
			return (this->values[x + y * 4]);
		}

		/**
		 * @brief Row accessor of Mat4.
		 *
		 * @warning No check of y, will crash if isn't in range [0, 3].
		 *
		 * @param y y index, must in range [0, 3].
		 *
		 * @return The row at row pos y as a Vec4.
		 */
		Vec4<T>	row(unsigned int y) const
		{
			unsigned int	id = y * 4;
			return (Vec4<T>(this->values[id],
							this->values[id + 1],
							this->values[id + 2],
							this->values[id + 3]));
		}

		//---- Setters ---------------------------------------------------------

		/**
		 * @brief Setter of Mat4.
		 *
		 * @param x x index, must in range [0, 3].
		 * @param y y index, must in range [0, 3].
		 * @param value The value to set.
		 *
		 * @exception Throw a runtime_error when x and y isn't in range [0, 3].
		 */
		void	set(unsigned int x, unsigned int y, const T &value)
		{
			if (x >= 4 || y >= 4)
				throw std::runtime_error("Index out of mat4 bounds");
			this->values[x + y * 4] = value;
		}

		//---- Modify Operators ------------------------------------------------

		Mat4	&operator=(const Mat4 &mat4)
		{
			if (this == &mat4)
				return (*this);

			for (int i = 0; i < GM_MAT4_SIZE; i++)
				this->values[i] = mat4.values[i];

			return (*this);
		}

		Mat4	&operator+=(const Mat4 &mat4)
		{
			for (int i = 0; i < GM_MAT4_SIZE; i++)
				this->values[i] += mat4.values[i];

			return (*this);
		}

		Mat4	&operator-=(const Mat4 &mat4)
		{
			for (int i = 0; i < GM_MAT4_SIZE; i++)
				this->values[i] -= mat4.values[i];

			return (*this);
		}

		Mat4	&operator*=(const T &value)
		{
			for (int i = 0; i < GM_MAT4_SIZE; i++)
				this->values[i] *= value;

			return (*this);
		}

		Mat4	&operator/=(const T &value)
		{
			for (int i = 0; i < GM_MAT4_SIZE; i++)
				this->values[i] /= value;

			return (*this);
		}

		//---- Compare Operators -----------------------------------------------

		bool	operator==(const Mat4 &mat4) const
		{
			for (int i = 0; i < GM_MAT4_SIZE; i++)
				if (this->values[i] != mat4.values[i])
					return (false);

			return (true);
		}

		bool	operator!=(const Mat4 &mat4) const
		{
			for (int i = 0; i < GM_MAT4_SIZE; i++)
				if (this->values[i] != mat4.values[i])
					return (true);

			return (false);
		}

		//---- Accessor Operators ----------------------------------------------

		/**
		 * @brief Access values by index.
		 *
		 * @param n The id of value in array style. Id is (x + y * 4).
		 *
		 * @return The reference of value at array position n.
		 * @exception Throw a runtime_error if n isn't in range [0, 15].
		 */
		T	&operator[](unsigned int n)
		{
			if (n >= GM_MAT4_SIZE)
				throw std::runtime_error("Index out of mat4 bounds");

			return (this->values[n]);
		}

		/**
		 * @brief Const access values by index.
		 *
		 * @param n The id of value in array style. Id is (x + y * 4).
		 *
		 * @return The const reference of value at array position n.
		 * @exception Throw a runtime_error if n isn't in range [0, 15].
		 */
		const T	&operator[](unsigned int n) const
		{
			if (n >= GM_MAT4_SIZE)
				throw std::runtime_error("Index out of mat4 bounds");

			return (this->values[n]);
		}

		/**
		 * @brief Access values by index.
		 *
		 * @warning No check of x and y, will crash if isn't in range [0, 3].
		 *
		 * @param vec2 The index of value in Vec2u.
		 *
		 * @return The reference of value at position (x,y).
		 */
		T	&operator[](const Vec2u &vec2)
		{
			return (this->values[vec2.x + vec2.y * 4]);
		}

		/**
		 * @brief Const access values by index.
		 *
		 * @warning No check of x and y, will crash if isn't in range [0, 3].
		 *
		 * @param vec2 The index of value in Vec2u.
		 *
		 * @return The const reference of value at position (x,y).
		 */
		const T	&operator[](const Vec2u &vec2) const
		{
			return (this->values[vec2.x + vec2.y * 4]);
		}

		//**** PUBLIC METHODS **************************************************
		/**
		 * @brief Get the determinant of the matrix.
		 *
		 * @return The determinant of the matrix.
		 */
		T	determinant(void) const
		{
			// Det a
			T	numA0 = this->values[5];
			T	detA0 = (this->values[10] * this->values[15]) -
						(this->values[11] * this->values[14]);
			T	numA1 = this->values[6];
			T	detA1 = (this->values[ 9] * this->values[15]) -
						(this->values[11] * this->values[13]);
			T	numA2 = this->values[7];
			T	detA2 = (this->values[ 9] * this->values[14]) -
						(this->values[10] * this->values[13]);
			T	numA = this->values[0];
			T	detA = (numA0 * detA0) - (numA1 * detA1) + (numA2 * detA2);

			// Det b
			T	numB0 = this->values[4];
			T	detB0 = detA0;
			T	numB1 = this->values[6];
			T	detB1 = (this->values[ 8] * this->values[15]) -
						(this->values[11] * this->values[12]);
			T	numB2 = this->values[7];
			T	detB2 = (this->values[ 8] * this->values[14]) -
						(this->values[10] * this->values[12]);
			T	numB = this->values[1];
			T	detB = (numB0 * detB0) - (numB1 * detB1) + (numB2 * detB2);

			// Det c
			T	numC0 = this->values[4];
			T	detC0 = detA1;
			T	numC1 = this->values[5];
			T	detC1 = detB1;
			T	numC2 = this->values[7];
			T	detC2 = (this->values[ 8] * this->values[13]) -
						(this->values[ 9] * this->values[12]);
			T	numC = this->values[2];
			T	detC = (numC0 * detC0) - (numC1 * detC1) + (numC2 * detC2);

			// Det d
			T	numD0 = this->values[4];
			T	detD0 = detA2;
			T	numD1 = this->values[5];
			T	detD1 = detB2;
			T	numD2 = this->values[6];
			T	detD2 = detC2;
			T	numD = this->values[3];
			T	detD = (numD0 * detD0) - (numD1 * detD1) + (numD2 * detD2);

			// Det mat
			return ((numA * detA) - (numB * detB) + (numC * detC) - (numD * detD));
		}

		/**
		 * @brief Create a Mat2 from a subpart of the Mat4.
		 *
		 * @return A Mat2 with x1, x2, y1 and y2 as values.
		 */
		Mat2<T>	asMat2(void) const
		{
			Mat2<T>	res;

			res.values[0] = this->values[0];
			res.values[1] = this->values[1];
			res.values[2] = this->values[4];
			res.values[3] = this->values[5];

			return (res);
		}

		/**
		 * @brief Create a Mat3 from a subpart of the Mat4.
		 *
		 * @return A Mat3 with x1, x2, x3, y1, y2, y3, z1, z2 and z3 as values.
		 */
		Mat3<T>	asMat3(void) const
		{
			Mat3<T>	res;

			res.values[0] = this->values[0];
			res.values[1] = this->values[1];
			res.values[2] = this->values[2];
			res.values[3] = this->values[4];
			res.values[4] = this->values[5];
			res.values[5] = this->values[6];
			res.values[6] = this->values[8];
			res.values[7] = this->values[9];
			res.values[8] = this->values[10];

			return (res);
		}

		//**** STATIC METHODS **************************************************

		/**
		 * @brief Create the 4x4 identity matrix.
		 *
		 * @return 4x4 identity matrix.
		 */
		static Mat4<T>	identity(void)
		{
			Mat4<T>	res;

			res.values[0] = static_cast<T>(1);
			res.values[5] = static_cast<T>(1);
			res.values[10] = static_cast<T>(1);
			res.values[15] = static_cast<T>(1);

			return (res);
		}

		/**
		 * @brief Create 4x4 rotation matrix for 3D rotation (w values are 0).
		 *
		 * @param axis Vec3 to tell on wich axis the rotation will be done. It must be normalized.
		 * @param radians The angle in radians.
		 *
		 * @return 4x4 rotation matrix of parameter.
		 */
		static Mat4<T>	rotation3D(const Vec3<T> &axis, T radians)
		{
			Mat4<T>	res;
			T		tmpCos = static_cast<T>(cos(static_cast<double>(-radians)));
			T		tmpSin = static_cast<T>(sin(static_cast<double>(-radians)));
			T		invTmpCos = static_cast<T>(1) - tmpCos;
			T		tmpSinAx = tmpSin * axis.x;
			T		tmpSinAy = tmpSin * axis.y;
			T		tmpSinAz = tmpSin * axis.z;

			// Line 1
			res.values[ 0] = (axis.x * axis.x) * invTmpCos + tmpCos;
			res.values[ 1] = (axis.x * axis.y) * invTmpCos - tmpSinAz;
			res.values[ 2] = (axis.x * axis.z) * invTmpCos + tmpSinAy;
			res.values[ 3] = T();
			// Line 2
			res.values[ 4] = (axis.y * axis.x) * invTmpCos + tmpSinAz;
			res.values[ 5] = (axis.y * axis.y) * invTmpCos + tmpCos;
			res.values[ 6] = (axis.y * axis.z) * invTmpCos - tmpSinAx;
			res.values[ 7] = T();
			// Line 3
			res.values[ 8] = (axis.z * axis.x) * invTmpCos - tmpSinAy;
			res.values[ 9] = (axis.z * axis.y) * invTmpCos + tmpSinAx;
			res.values[10] = (axis.z * axis.z) * invTmpCos + tmpCos;
			res.values[11] = T();
			// Line 4
			res.values[12] = T();
			res.values[13] = T();
			res.values[14] = T();
			res.values[15] = static_cast<T>(1);

			return (res);
		}

		/**
		 * @brief Create 4x4 translation matrix.
		 *
		 * @param movement Vec3 for the translation to apply.
		 *
		 * @return 4x4 translation matrix of parameter.
		 */
		static Mat4<T>	translation(const Vec3<T> &movement)
		{
			Mat4<T>	res(static_cast<T>(1));

			res.values[3] = movement.x;
			res.values[7] = movement.y;
			res.values[11] = movement.z;

			return (res);
		}

		/**
		 * @brief Create 4x4 perspective matrix.
		 *
		 * @param fovY The fov for camera height in radians.
		 * @param ratio The ratio of the screen (width / height).
		 * @param near The closest distance in camera vison.
		 * @param far The farest distance in camera vison.
		 *
		 * @return The perspective matrix.
		 */
		static Mat4<T>	perspective(T fovY, T ratio, T near, T far)
		{
			Mat4<T>	res;

			// Compute fov
			T	tanFov = tan(fovY / static_cast<T>(2));

			// Scaling factor x * ratio because fov is for y
			res.values[0] = static_cast<T>(1) / (tanFov * ratio);
			// Scaling factor y
			res.values[5] = static_cast<T>(1) / tanFov;

			// Remap z in range [0, 1]
			res.values[10] = - (far / (far - near));
			res.values[11] = - static_cast<T>(1);
			res.values[14] = - ((far * near) / (far - near));

			return (res);
		}

		/**
		 * @brief Create a 4x4 view matrix.
		 *
		 * @param eye Position of the camera.
		 * @param center Position where the camera look at.
		 * @param up Camera up direction normalize. Typically (0, 0, 1).
		 *
		 * @return The view matrix.
		 */
		static Mat4<T>	lookAt(const Vec3<T> &eye, const Vec3<T> &center, const Vec3<T> &up)
		{
			const Vec3<T>	f(normalize(center - eye));
			const Vec3<T>	s(normalize(cross(f, up)));
			const Vec3<T>	u(cross(s, f));

			Mat4<T>	res(static_cast<T>(1));

			res.values[ 0] = s.x;
			res.values[ 4] = s.y;
			res.values[ 8] = s.z;
			res.values[12] = -dot(s, eye);

			res.values[ 1] = u.x;
			res.values[ 5] = u.y;
			res.values[ 9] = u.z;
			res.values[13] = -dot(u, eye);

			res.values[ 2] = -f.x;
			res.values[ 6] = -f.y;
			res.values[10] = -f.z;
			res.values[14] = dot(f, eye);

			return (res);
		}

	private:

	};

	//**** EXTERNS OPERATORS ***************************************************
	//---- Matrix matrix operator ----------------------------------------------

	template <typename T>
	Mat4<T>	operator+(const Mat4<T> &m1, const Mat4<T> &m2)
	{
		Mat4<T>	res;

		for (int i = 0; i < GM_MAT4_SIZE; i++)
			res.values[i] = m1.values[i] + m2.values[i];

		return (res);
	}

	template <typename T>
	Mat4<T>	operator-(const Mat4<T> &m1, const Mat4<T> &m2)
	{
		Mat4<T>	res;

		for (int i = 0; i < GM_MAT4_SIZE; i++)
			res.values[i] = m1.values[i] - m2.values[i];

		return (res);
	}

	/**
	 * @brief Matrix multiplication between 2 Mat4.
	 *
	 * @param m1 First matrix.
	 * @param m2 Second matrix.
	 *
	 * @return Result of m1 * m2.
	 */
	template <typename T>
	Mat4<T>	operator*(const Mat4<T> &m1, const Mat4<T> &m2)
	{
		Mat4<T>	res;

		res.values[ 0] = m1.values[ 0] * m2.values[ 0] + m1.values[ 1] * m2.values[ 4] + m1.values[ 2] * m2.values[ 8] + m1.values[ 3] * m2.values[12];
		res.values[ 1] = m1.values[ 0] * m2.values[ 1] + m1.values[ 1] * m2.values[ 5] + m1.values[ 2] * m2.values[ 9] + m1.values[ 3] * m2.values[13];
		res.values[ 2] = m1.values[ 0] * m2.values[ 2] + m1.values[ 1] * m2.values[ 6] + m1.values[ 2] * m2.values[10] + m1.values[ 3] * m2.values[14];
		res.values[ 3] = m1.values[ 0] * m2.values[ 3] + m1.values[ 1] * m2.values[ 7] + m1.values[ 2] * m2.values[11] + m1.values[ 3] * m2.values[15];
		res.values[ 4] = m1.values[ 4] * m2.values[ 0] + m1.values[ 5] * m2.values[ 4] + m1.values[ 6] * m2.values[ 8] + m1.values[ 7] * m2.values[12];
		res.values[ 5] = m1.values[ 4] * m2.values[ 1] + m1.values[ 5] * m2.values[ 5] + m1.values[ 6] * m2.values[ 9] + m1.values[ 7] * m2.values[13];
		res.values[ 6] = m1.values[ 4] * m2.values[ 2] + m1.values[ 5] * m2.values[ 6] + m1.values[ 6] * m2.values[10] + m1.values[ 7] * m2.values[14];
		res.values[ 7] = m1.values[ 4] * m2.values[ 3] + m1.values[ 5] * m2.values[ 7] + m1.values[ 6] * m2.values[11] + m1.values[ 7] * m2.values[15];
		res.values[ 8] = m1.values[ 8] * m2.values[ 0] + m1.values[ 9] * m2.values[ 4] + m1.values[10] * m2.values[ 8] + m1.values[11] * m2.values[12];
		res.values[ 9] = m1.values[ 8] * m2.values[ 1] + m1.values[ 9] * m2.values[ 5] + m1.values[10] * m2.values[ 9] + m1.values[11] * m2.values[13];
		res.values[10] = m1.values[ 8] * m2.values[ 2] + m1.values[ 9] * m2.values[ 6] + m1.values[10] * m2.values[10] + m1.values[11] * m2.values[14];
		res.values[11] = m1.values[ 8] * m2.values[ 3] + m1.values[ 9] * m2.values[ 7] + m1.values[10] * m2.values[11] + m1.values[11] * m2.values[15];
		res.values[12] = m1.values[12] * m2.values[ 0] + m1.values[13] * m2.values[ 4] + m1.values[14] * m2.values[ 8] + m1.values[15] * m2.values[12];
		res.values[13] = m1.values[12] * m2.values[ 1] + m1.values[13] * m2.values[ 5] + m1.values[14] * m2.values[ 9] + m1.values[15] * m2.values[13];
		res.values[14] = m1.values[12] * m2.values[ 2] + m1.values[13] * m2.values[ 6] + m1.values[14] * m2.values[10] + m1.values[15] * m2.values[14];
		res.values[15] = m1.values[12] * m2.values[ 3] + m1.values[13] * m2.values[ 7] + m1.values[14] * m2.values[11] + m1.values[15] * m2.values[15];

		return (res);
	}

	//---- Matrix value operator -----------------------------------------------

	template <typename T>
	Mat4<T>	operator*(const Mat4<T> &mat4, const T &value)
	{
		Mat4<T>	res;

		for (int i = 0; i < GM_MAT4_SIZE; i++)
			res.values[i] = mat4.values[i] * value;

		return (res);
	}

	template <typename T>
	Mat4<T>	operator*(const T &value, const Mat4<T> &mat4)
	{
		Mat4<T>	res;

		for (int i = 0; i < GM_MAT4_SIZE; i++)
			res.values[i] = mat4.values[i] * value;

		return (res);
	}

	template <typename T>
	Mat4<T>	operator/(const Mat4<T> &mat4, const T &value)
	{
		Mat4<T>	res;

		for (int i = 0; i < GM_MAT4_SIZE; i++)
			res.values[i] = mat4.values[i] / value;

		return (res);
	}

	//---- Print operator ------------------------------------------------------

	template <typename T>
	std::ostream	&operator<<(std::ostream &os, const Mat4<T> &mat4)
	{
		os << "|(" << mat4.values[0] << "," << mat4.values[1] << "," << mat4.values[2] << "," << mat4.values[3]
			<< ");(" << mat4.values[4] << "," << mat4.values[5] << "," << mat4.values[6] << "," << mat4.values[7]
			<< ");(" << mat4.values[8] << "," << mat4.values[9] << "," << mat4.values[10] << "," << mat4.values[11]
			<< ");(" << mat4.values[12] << "," << mat4.values[13] << "," << mat4.values[14] << "," << mat4.values[15] << ")|";
		return (os);
	}

	//**** FUNCTIONS ***********************************************************

	/**
	 * @brief Print a Mat4 in a beatiful format with cout.
	 *
	 * @param mat4 The Mat4 to print.
	 */
	template <typename T>
	void	print(const Mat4<T> &mat4)
	{
		Mat4<T>	res;

		std::cout	<< "|" << mat4.values[ 0] << ", " << mat4.values[ 1] << ", " << mat4.values[ 2] << ", " << mat4.values[ 3] << "|\n"
					<< "|" << mat4.values[ 4] << ", " << mat4.values[ 5] << ", " << mat4.values[ 6] << ", " << mat4.values[ 7] << "|\n"
					<< "|" << mat4.values[ 8] << ", " << mat4.values[ 9] << ", " << mat4.values[10] << ", " << mat4.values[11] << "|\n"
					<< "|" << mat4.values[12] << ", " << mat4.values[13] << ", " << mat4.values[14] << ", " << mat4.values[15] << "|" << std::endl;
	}

	/**
	 * @brief Transpose a Mat4.
	 *
	 * @param mat4 The Mat4 to transpose.
	 *
	 * @return Mat4 transposed.
	 */
	template <typename T>
	Mat4<T>	transpose(const Mat4<T> &mat4)
	{
		Mat4<T>	res;

		res.values[ 0] = mat4.values[ 0];
		res.values[ 1] = mat4.values[ 4];
		res.values[ 2] = mat4.values[ 8];
		res.values[ 3] = mat4.values[12];
		res.values[ 4] = mat4.values[ 1];
		res.values[ 5] = mat4.values[ 5];
		res.values[ 6] = mat4.values[ 9];
		res.values[ 7] = mat4.values[13];
		res.values[ 8] = mat4.values[ 2];
		res.values[ 9] = mat4.values[ 6];
		res.values[10] = mat4.values[10];
		res.values[11] = mat4.values[14];
		res.values[12] = mat4.values[ 3];
		res.values[13] = mat4.values[ 7];
		res.values[14] = mat4.values[11];
		res.values[15] = mat4.values[15];

		return (res);
	}

	/**
	 * @brief Rotate a Mat4 in 3D.
	 *
	 * @param mat4 The Mat4 to rotate.
	 * @param axis Vec3 to tell on wich axis the rotation will be done. It must be normalized.
	 * @param radians The angle in radians.
	 *
	 * @return Mat4 rotate by axis and angle in radians in 3D.
	 */
	template <typename T>
	Mat4<T>	rotate(const Mat4<T> &mat4, const Vec3<T> &axis, T radians)
	{
		const Mat4<T>	matRot = Mat4<T>::rotation3D(axis, radians);

		return (mat4 * matRot);
	}

	/**
	 * @brief Translate a Mat4.
	 *
	 * @param mat4 The Mat4 to translate.
	 * @param movement Vec3 for the translation to apply.
	 *
	 * @return Mat4 translate by movement vector.
	 */
	template <typename T>
	Mat4<T>	translate(const Mat4<T> &mat4, const Vec3<T> &movement)
	{
		const Mat4<T>	matTranslate = Mat4<T>::translation(movement);

		return (mat4 * matTranslate);
	}

	/**
	 * @brief Get the hash of a Mat4.
	 *
	 * @param mat4 Mat4 to hash.
	 *
	 * @return Hash of Mat4.
	 */
	template <typename T>
	std::size_t	hash(const Mat4<T> &mat4)
	{
		std::size_t	hash = 0;

		for (int i = 0; i < GM_MAT4_SIZE; i++)
			hash = std::hash<T>{}(mat4.values[i]) + 0x9e3779b9 + (hash<<6) + (hash>>2);

		return (hash);
	}

	//**** STATIC FUNCTIONS ****************************************************
	//**** USINGS **************************************************************

	/**
	 * @brief Class for 4x4 unsigned int matrix.
	 *
	 * The class is design to be used with graphic library like OpenGL or Vulkan.
	 */
	using Mat4u = Mat4<unsigned int>;
	/**
	 * @brief Class for 4x4 int matrix.
	 *
	 * The class is design to be used with graphic library like OpenGL or Vulkan.
	 */
	using Mat4i = Mat4<int>;
	/**
	 * @brief Class for 4x4 float matrix.
	 *
	 * The class is design to be used with graphic library like OpenGL or Vulkan.
	 */
	using Mat4f = Mat4<float>;
	/**
	 * @brief Class for 4x4 double matrix.
	 *
	 * The class is design to be used with graphic library like OpenGL or Vulkan.
	 */
	using Mat4d = Mat4<double>;
}

#endif
