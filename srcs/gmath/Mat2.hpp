#ifndef GM_MAT2_HPP
# define GM_MAT2_HPP

# define GM_MAT2_SIZE 4

# include <gmath/Vec2.hpp>

#include <cmath>
#include <iostream>
#include <stdexcept>

namespace gm {
	//**** STATIC FUNCTIONS DEFINE *********************************************
	//**** CLASS DEFINE ********************************************************

	/**
	 * @brief Class for 2x2 matrix.
	 *
	 * @tparam T Type of value in the matrix.
	 *
	 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
	 */
	template <typename T>
	class Mat2
	{
	public:
		T	values[GM_MAT2_SIZE];

		//**** INITIALISION ****************************************************
		//---- Constructors ----------------------------------------------------

		/**
		 * @brief Default constructor of Mat2 class.
		 *
		 * @return The Mat2 with values at 0.
		 */
		Mat2(void)
		{
			for (int i = 0; i < GM_MAT2_SIZE; i++)
				this->values[i] = T();
		}

		/**
		 * @brief Copy constructor of Mat2 class.
		 *
		 * @param mat2 The Mat2 to copy.
		 *
		 * @return The Mat2 copied from parameter.
		 */
		Mat2(const Mat2 &mat2)
		{
			for (int i = 0; i < GM_MAT2_SIZE; i++)
				this->values[i] = mat2.values[i];
		}

		/**
		 * @brief Constructor of Mat2 class from an array.
		 *
		 * @param values Values in array form.
		 *
		 * @return Mat2 values of the array.
		 */
		Mat2(const T values[GM_MAT2_SIZE])
		{
			for (int i = 0; i < GM_MAT2_SIZE; i++)
				this->values[i] = values[i];
		}

		/**
		 * @brief Constructor of Mat2 class from parameters.
		 *
		 * @param x1 Value at (0,0).
		 * @param x2 Value at (1,0).
		 * @param y1 Value at (0,1).
		 * @param y2 Value at (1,1).
		 *
		 * @return Mat2 values of parameters.
		 */
		Mat2(T x1, T x2, T y1, T y2)
		{
			this->values[0] = x1;
			this->values[1] = x2;
			this->values[2] = y1;
			this->values[3] = y2;
		}

		/**
		 * @brief Constructor of Mat2 class scaling.
		 *
		 * @param scale Values in array form.
		 *
		 * @return Mat2 identity * scale.
		 */
		Mat2(T scale)
		{
			this->values[0] = scale;
			this->values[1] = T();
			this->values[2] = T();
			this->values[3] = scale;
		}

		//---- Destructor ------------------------------------------------------

		~Mat2()
		{
		}

		//**** ACCESSORS *******************************************************
		//---- Getters ---------------------------------------------------------

		/**
		 * @brief Getter of Mat2.
		 *
		 * @param x x index, must in range [0, 1].
		 * @param y y index, must in range [0, 1].
		 *
		 * @return The value at position (x,y).
		 * @exception Throw a runtime_error when x and y isn't in range [0, 1].
		 */
		T	get(unsigned int x, unsigned int y) const
		{
			if (x >= 2 || y >= 2)
				throw std::runtime_error("Index out of mat2 bounds");
			return (this->values[x + y * 2]);
		}

		/**
		 * @brief Accessor of Mat2.
		 *
		 * @warning No check of x and y, will crash if isn't in range [0, 1].
		 *
		 * @param x x index, must in range [0, 1].
		 * @param y y index, must in range [0, 1].
		 *
		 * @return The reference of value at position (x,y).
		 */
		T	&at(unsigned int x, unsigned int y)
		{
			return (this->values[x + y * 2]);
		}

		/**
		 * @brief Const accessor of Mat2.
		 *
		 * @warning No check of x and y, will crash if isn't in range [0, 1].
		 *
		 * @param x x index, must in range [0, 1].
		 * @param y y index, must in range [0, 1].
		 *
		 * @return The const reference of value at position (x,y).
		 */
		const T	&at(unsigned int x, unsigned int y) const
		{
			return (this->values[x + y * 2]);
		}

		/**
		 * @brief Row accessor of Mat2.
		 *
		 * @warning No check of y, will crash if isn't in range [0, 1].
		 *
		 * @param y y index, must in range [0, 1].
		 *
		 * @return The row at row pos y as a Vec2.
		 */
		Vec2<T>	row(unsigned int y) const
		{
			unsigned int	id = y * 2;
			return (Vec2<T>(this->values[id],
							this->values[id + 1]));
		}

		//---- Setters ---------------------------------------------------------

		/**
		 * @brief Setter of Mat2.
		 *
		 * @param x x index, must in range [0, 1].
		 * @param y y index, must in range [0, 1].
		 * @param value The value to set.
		 *
		 * @exception Throw a runtime_error when x and y isn't in range [0, 1].
		 */
		void	set(unsigned int x, unsigned int y, const T &value)
		{
			if (x >= 2 || y >= 2)
				throw std::runtime_error("Index out of mat2 bounds");
			this->values[x + y * 2] = value;
		}

		//---- Modify Operators ------------------------------------------------

		Mat2	&operator=(const Mat2 &mat2)
		{
			if (this == &mat2)
				return (*this);

			for (int i = 0; i < GM_MAT2_SIZE; i++)
				this->values[i] = mat2.values[i];

			return (*this);
		}

		Mat2	&operator+=(const Mat2 &mat2)
		{
			for (int i = 0; i < GM_MAT2_SIZE; i++)
				this->values[i] += mat2.values[i];

			return (*this);
		}

		Mat2	&operator-=(const Mat2 &mat2)
		{
			for (int i = 0; i < GM_MAT2_SIZE; i++)
				this->values[i] -= mat2.values[i];

			return (*this);
		}

		Mat2	&operator*=(const T &value)
		{
			for (int i = 0; i < GM_MAT2_SIZE; i++)
				this->values[i] *= value;

			return (*this);
		}

		Mat2	&operator/=(const T &value)
		{
			for (int i = 0; i < GM_MAT2_SIZE; i++)
				this->values[i] /= value;

			return (*this);
		}

		//---- Compare Operators -----------------------------------------------

		bool	operator==(const Mat2 &mat2) const
		{
			for (int i = 0; i < GM_MAT2_SIZE; i++)
				if (this->values[i] != mat2.values[i])
					return (false);

			return (true);
		}

		bool	operator!=(const Mat2 &mat2) const
		{
			for (int i = 0; i < GM_MAT2_SIZE; i++)
				if (this->values[i] != mat2.values[i])
					return (true);

			return (false);
		}

		//---- Accessor Operators ----------------------------------------------

		/**
		 * @brief Access values by index.
		 *
		 * @param n The id of value in array style. Id is (x + y * 2).
		 *
		 * @return The reference of value at array position n.
		 * @exception Throw a runtime_error if n isn't in range [0, 3].
		 */
		T	&operator[](unsigned int n)
		{
			if (n >= GM_MAT2_SIZE)
				throw std::runtime_error("Index out of mat2 bounds");

			return (this->values[n]);
		}

		/**
		 * @brief Const access values by index.
		 *
		 * @param n The id of value in array style. Id is (x + y * 2).
		 *
		 * @return The const reference of value at array position n.
		 * @exception Throw a runtime_error if n isn't in range [0, 3].
		 */
		const T	&operator[](unsigned int n) const
		{
			if (n >= GM_MAT2_SIZE)
				throw std::runtime_error("Index out of mat2 bounds");

			return (this->values[n]);
		}

		/**
		 * @brief Access values by index.
		 *
		 * @warning No check of x and y, will crash if isn't in range [0, 1].
		 *
		 * @param vec2 The index of value in Vec2u.
		 *
		 * @return The reference of value at position (x,y).
		 */
		T	&operator[](const Vec2u &vec2)
		{
			return (this->values[vec2.x + vec2.y * 2]);
		}

		/**
		 * @brief Const Access values by index.
		 *
		 * @warning No check of x and y, will crash if isn't in range [0, 1].
		 *
		 * @param vec2 The index of value in Vec2u.
		 *
		 * @return The const reference of value at position (x,y).
		 */
		const T	&operator[](const Vec2u &vec2) const
		{
			return (this->values[vec2.x + vec2.y * 2]);
		}

		//**** PUBLIC METHODS **************************************************
		/**
		 * @brief Get the determinant of the matrix.
		 *
		 * @return The determinant of the matrix.
		 */
		T	determinant(void) const
		{
			return ((this->values[0] * this->values[3])
					- (this->values[1] * this->values[2]));
		}

		//**** STATIC METHODS **************************************************

		/**
		 * @brief Create the 2x2 identity matrix.
		 *
		 * @return 2x2 identity matrix.
		 */
		static Mat2<T>	identity(void)
		{
			Mat2<T>	res;

			res.values[0] = static_cast<T>(1);
			res.values[3] = static_cast<T>(1);

			return (res);
		}

		/**
		 * @brief Create 2x2 rotation matrix.
		 *
		 * @param radians The angle in radians.
		 *
		 * @return 2x2 rotation matrix of parameter.
		 */
		static Mat2<T>	rotation(T radians)
		{
			Mat2<T>	res;
			T		tmpCos = static_cast<T>(cos(static_cast<double>(radians)));
			T		tmpSin = static_cast<T>(sin(static_cast<double>(radians)));

			res.values[0] = tmpCos;
			res.values[1] = -tmpSin;
			res.values[2] = tmpSin;
			res.values[3] = tmpCos;

			return (res);
		}

	private:

	};

	//**** EXTERNS OPERATORS ***************************************************
	//---- Matrix matrix operator ----------------------------------------------

	template <typename T>
	Mat2<T>	operator+(const Mat2<T> &m1, const Mat2<T> &m2)
	{
		Mat2<T>	res;

		for (int i = 0; i < GM_MAT2_SIZE; i++)
			res.values[i] = m1.values[i] + m2.values[i];

		return (res);
	}

	template <typename T>
	Mat2<T>	operator-(const Mat2<T> &m1, const Mat2<T> &m2)
	{
		Mat2<T>	res;

		for (int i = 0; i < GM_MAT2_SIZE; i++)
			res.values[i] = m1.values[i] - m2.values[i];

		return (res);
	}

	/**
	 * @brief Matrix multiplication between 2 Mat2.
	 *
	 * @param m1 First matrix.
	 * @param m2 Second matrix.
	 *
	 * @return Result of m1 * m2.
	 */
	template <typename T>
	Mat2<T>	operator*(const Mat2<T> &m1, const Mat2<T> &m2)
	{
		Mat2<T>	res;

		res.values[0] = m1.values[0] * m2.values[0] + m1.values[1] * m2.values[2];
		res.values[1] = m1.values[0] * m2.values[1] + m1.values[1] * m2.values[3];
		res.values[2] = m1.values[2] * m2.values[0] + m1.values[3] * m2.values[2];
		res.values[3] = m1.values[2] * m2.values[1] + m1.values[3] * m2.values[3];

		return (res);
	}

	//---- Matrix value operator -----------------------------------------------

	template <typename T>
	Mat2<T>	operator*(const Mat2<T> &mat2, const T &value)
	{
		Mat2<T>	res;

		for (int i = 0; i < GM_MAT2_SIZE; i++)
			res.values[i] = mat2.values[i] * value;

		return (res);
	}

	template <typename T>
	Mat2<T>	operator*(const T &value, const Mat2<T> &mat2)
	{
		Mat2<T>	res;

		for (int i = 0; i < GM_MAT2_SIZE; i++)
			res.values[i] = mat2.values[i] * value;

		return (res);
	}

	template <typename T>
	Mat2<T>	operator/(const Mat2<T> &mat2, const T &value)
	{
		Mat2<T>	res;

		for (int i = 0; i < GM_MAT2_SIZE; i++)
			res.values[i] = mat2.values[i] / value;

		return (res);
	}

	//---- Print operator ------------------------------------------------------

	template <typename T>
	std::ostream	&operator<<(std::ostream &os, const Mat2<T> &mat2)
	{
		os << "|(" << mat2.values[0] << "," << mat2.values[1] << ");(" << mat2.values[2] << "," << mat2.values[3] << ")|";
		return (os);
	}

	//**** FUNCTIONS ***********************************************************

	/**
	 * @brief Print a Mat2 in a beatiful format with cout.
	 *
	 * @param mat2 The Mat2 to print.
	 */
	template <typename T>
	void	print(const Mat2<T> &mat2)
	{
		Mat2<T>	res;

		std::cout	<< "|" << mat2.values[0] << ", " << mat2.values[1] << "|\n"
					<< "|" << mat2.values[2] << ", " << mat2.values[3] << "|" << std::endl;
	}

	/**
	 * @brief Transpose a Mat2.
	 *
	 * @param mat2 The Mat2 to transpose.
	 *
	 * @return Mat2 transposed.
	 */
	template <typename T>
	Mat2<T>	transpose(const Mat2<T> &mat2)
	{
		Mat2<T>	res;

		res.values[0] = mat2.values[0];
		res.values[1] = mat2.values[2];
		res.values[2] = mat2.values[1];
		res.values[3] = mat2.values[3];

		return (res);
	}

	/**
	 * @brief Rotate a Mat2.
	 *
	 * @param mat2 The Mat2 to rotate.
	 * @param radians The angle in radians.
	 *
	 * @return Mat2 rotate by angle in radians.
	 */
	template <typename T>
	Mat2<T>	rotate(const Mat2<T> &mat2, T radians)
	{
		const Mat2<T>	matRot = Mat2<T>::rotation(radians);

		return (mat2 * matRot);
	}

	/**
	 * @brief Get the hash of a Mat2.
	 *
	 * @param mat2 Mat2 to hash.
	 *
	 * @return Hash of Mat2.
	 */
	template <typename T>
	std::size_t	hash(const Mat2<T> &mat2)
	{
		std::size_t	hash = 0;

		for (int i = 0; i < GM_MAT2_SIZE; i++)
			hash = std::hash<T>{}(mat2.values[i]) + 0x9e3779b9 + (hash<<6) + (hash>>2);

		return (hash);
	}

	//**** STATIC FUNCTIONS ****************************************************
	//**** USINGS **************************************************************

	/**
	 * @brief Class for 2x2 unsigned int matrix.
	 *
	 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
	 */
	using Mat2u = Mat2<unsigned int>;
	/**
	 * @brief Class for 2x2 int matrix.
	 *
	 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
	 */
	using Mat2i = Mat2<int>;
	/**
	 * @brief Class for 2x2 float matrix.
	 *
	 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
	 */
	using Mat2f = Mat2<float>;
	/**
	 * @brief Class for 2x2 double matrix.
	 *
	 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
	 */
	using Mat2d = Mat2<double>;
}

#endif
