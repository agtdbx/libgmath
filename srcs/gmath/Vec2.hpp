#ifndef GM_VEC2_HPP
# define GM_VEC2_HPP

# include <gmath/random.hpp>

# include <cmath>
# include <iostream>
# include <stdexcept>

namespace gm {
	//**** STATIC FUNCTIONS DEFINE *********************************************
	//**** CLASS DEFINE ********************************************************

	/**
	 * @brief Class for 2d vector.
	 *
	 * @tparam T Type of value in the vector.
	 *
	 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
	 */
	template <typename T>
	class Vec2
	{
	public:
		T	x;
		T	y;

		//**** INITIALISION ****************************************************
		//---- Constructors ----------------------------------------------------

		/**
		 * @brief Default constructor of Vec2 class.
		 *
		 * @return The Vec2 with values at 0.
		 */
		Vec2(void)
		{
			this->x = T();
			this->y = T();
		}

		/**
		 * @brief Copy constructor of Vec2 class.
		 *
		 * @param vec2 The Vec2 to copy.
		 *
		 * @return The Vec2 copied from parameter.
		 */
		Vec2(const Vec2 &vec2)
		{
			this->x = vec2.x;
			this->y = vec2.y;
		}

		/**
		 * @brief Constructor of Vec2 class.
		 *
		 * @param x x value of the Vec2.
		 * @param y y value of the Vec2.
		 *
		 * @return The Vec2 with parameter values.
		 */
		Vec2(T x, T y)
		{
			this->x = x;
			this->y = y;
		}

		/**
		 * @brief Constructor of Vec2 class.
		 *
		 * @param value x and y values of Vec2.
		 *
		 * @return The Vec2 with parameter value.
		 */
		Vec2(T value)
		{
			this->x = value;
			this->y = value;
		}

		//---- Destructor ------------------------------------------------------

		~Vec2()
		{
		}

		//**** ACCESSORS *******************************************************
		//---- Getters ---------------------------------------------------------
		//---- Setters ---------------------------------------------------------
		//---- Modify Operators ------------------------------------------------

		Vec2	&operator=(const Vec2 &vec2)
		{
			if (this == &vec2)
				return (*this);

			this->x = vec2.x;
			this->y = vec2.y;

			return (*this);
		}

		Vec2	&operator+=(const Vec2 &vec2)
		{
			this->x += vec2.x;
			this->y += vec2.y;

			return (*this);
		}

		Vec2	&operator-=(const Vec2 &vec2)
		{
			this->x -= vec2.x;
			this->y -= vec2.y;

			return (*this);
		}

		Vec2	&operator*=(const T &value)
		{
			this->x *= value;
			this->y *= value;

			return (*this);
		}

		Vec2	&operator/=(const T &value)
		{
			this->x /= value;
			this->y /= value;

			return (*this);
		}

		//---- Compare Operators -----------------------------------------------

		bool	operator==(const Vec2 &vec2) const
		{
			return (this->x == vec2.x && this->y == vec2.y);
		}

		bool	operator!=(const Vec2 &vec2) const
		{
			return (this->x != vec2.x || this->y != vec2.y);
		}

		//---- Unary Operators -------------------------------------------------

		Vec2	operator-(void) const
		{
			return (Vec2(-this->x, -this->y));
		}

		//---- Accessor Operators ----------------------------------------------

		/**
		 * @brief Access values by index.
		 *
		 * Index 0 is for x.
		 * Index 1 is for y.
		 * Other index will return an exception.
		 *
		 * @param n Index of the value wanted.
		 *
		 * @return The reference to value at the index.
		 * @exception Throw runtime_error when index is greater than 1.
		 */
		T	&operator[](unsigned int n)
		{
			if (n == 0)
				return (this->x);
			if (n == 1)
				return (this->y);

			throw std::runtime_error("Index out of vec2 bounds");
		}

		/**
		 * @brief Const access values by index.
		 *
		 * Index 0 is for x.
		 * Index 1 is for y.
		 * Other index will return an exception.
		 *
		 * @param n Index of the value wanted.
		 *
		 * @return The const reference to value at the index.
		 * @exception Throw runtime_error when index is greater than 1.
		 */
		const T	&operator[](unsigned int n) const
		{
			if (n == 0)
				return (this->x);
			if (n == 1)
				return (this->y);

			throw std::runtime_error("Index out of vec2 bounds");
		}

		//**** PUBLIC METHODS **************************************************
		//**** STATIC METHODS **************************************************

		/**
		 * @brief Create a random 2d normal.
		 *
		 * @return A random Vec2 normalized.
		 */
		static Vec2<T>	randomNormal(void)
		{
			double	angle = dRand() * M_PI;

			return (Vec2<T>(static_cast<T>(cos(angle)),
							static_cast<T>(sin(angle))));
		}

	private:

	};

	//**** EXTERNS OPERATORS ***************************************************
	//---- Vector vector operator ----------------------------------------------

	template <typename T>
	Vec2<T>	operator+(const Vec2<T> &v1, const Vec2<T> &v2)
	{
		return (Vec2<T>(v1.x + v2.x, v1.y + v2.y));
	}

	template <typename T>
	Vec2<T>	operator-(const Vec2<T> &v1, const Vec2<T> &v2)
	{
		return (Vec2<T>(v1.x - v2.x, v1.y - v2.y));
	}

	//---- Vector value operator -----------------------------------------------

	template <typename T>
	Vec2<T>	operator*(const Vec2<T> &vec2, const T &value)
	{
		return (Vec2<T>(vec2.x * value, vec2.y * value));
	}

	template <typename T>
	Vec2<T>	operator*(const T &value, const Vec2<T> &vec2)
	{
		return (Vec2<T>(vec2.x * value, vec2.y * value));
	}

	template <typename T>
	Vec2<T>	operator/(const Vec2<T> &vec2, const T &value)
	{
		return (Vec2<T>(vec2.x / value, vec2.y / value));
	}

	//---- Print operator ------------------------------------------------------

	template <typename T>
	std::ostream	&operator<<(std::ostream &os, const Vec2<T> &vec2)
	{
		os << "(" << vec2.x << "," << vec2.y << ")";
		return (os);
	}

	//**** FUNCTIONS ***********************************************************

	/**
	 * @brief Get Vec2 norm.
	 *
	 * @param vec2 Vec2 to get the norm.
	 *
	 * @return Norm of vec2.
	 */
	template <typename T>
	T	norm(const Vec2<T> &vec2)
	{
		return (static_cast<T>(sqrt(static_cast<double>(vec2.x * vec2.x
														+ vec2.y * vec2.y))));
	}

	/**
	 * @brief Get Vec2 norm squared.
	 *
	 * @param vec2 Vec2 to get the norm squared.
	 *
	 * @return Norm squared of vec2.
	 */
	template <typename T>
	T	norm2(const Vec2<T> &vec2)
	{
		return (vec2.x * vec2.x + vec2.y * vec2.y);
	}

	/**
	 * @brief Normalize a Vec2.
	 *
	 * @param vec2 Vec2 to normalize.
	 *
	 * @return Normalised vec2, or vec2 if it's norm is 0.
	 */
	template <typename T>
	Vec2<T>	normalize(const Vec2<T> &vec2)
	{
		T	dst = norm2(vec2);

		if (dst == static_cast<T>(0) || dst == static_cast<T>(1))
			return (vec2);

		T	toDiv = static_cast<T>(1) / static_cast<T>(sqrt(static_cast<double>(dst)));
		return (vec2 * toDiv);
	}

	/**
	 * @brief Dot product between two Vec2.
	 *
	 * @param v1 First Vec2.
	 * @param v2 Second Vec2.
	 *
	 * @return Dot product of v1 with v2.
	 */
	template <typename T>
	T	dot(const Vec2<T> &v1, const Vec2<T> &v2)
	{
		return (v1.x * v2.x + v1.y * v2.y);
	}

	/**
	 * @brief Get the hash of a Vec2.
	 *
	 * @param vec2 Vec2 to hash.
	 *
	 * @return Hash of Vec2.
	 */
	template <typename T>
	std::size_t	hash(const Vec2<T> &vec2)
	{
		std::size_t	hash = 0;

		hash = std::hash<T>{}(vec2.x) + 0x9e3779b9 + (hash<<6) + (hash>>2);
		hash = std::hash<T>{}(vec2.y) + 0x9e3779b9 + (hash<<6) + (hash>>2);

		return (hash);
	}

	//**** STATIC FUNCTIONS ****************************************************
	//**** USINGS **************************************************************
	//---- VEC2 ----------------------------------------------------------------

	/**
	 * @brief Class for 2d unsigned int vector.
	 *
	 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
	 */
	using Vec2u = Vec2<unsigned int>;
	/**
	 * @brief Class for 2d int vector.
	 *
	 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
	 */
	using Vec2i = Vec2<int>;
	/**
	 * @brief Class for 2d float vector.
	 *
	 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
	 */
	using Vec2f = Vec2<float>;
	/**
	 * @brief Class for 2d double vector.
	 *
	 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
	 */
	using Vec2d = Vec2<double>;

	//---- POINT2 --------------------------------------------------------------

	/**
	 * @brief Class for 2d unsigned int vector.
	 *
	 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
	 */
	using Point2u = Vec2<unsigned int>;
	/**
	 * @brief Class for 2d int vector.
	 *
	 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
	 */
	using Point2i = Vec2<int>;
	/**
	 * @brief Class for 2d float vector.
	 *
	 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
	 */
	using Point2f = Vec2<float>;
	/**
	 * @brief Class for 2d double vector.
	 *
	 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
	 */
	using Point2d = Vec2<double>;
}

#endif
