#ifndef GM_VEC4_HPP
# define GM_VEC4_HPP

# include <gmath/Vec2.hpp>
# include <gmath/Vec3.hpp>

#include <cmath>
#include <iostream>
#include <stdexcept>

namespace gm {
	//**** STATIC FUNCTIONS DEFINE *********************************************
	//**** CLASS DEFINE ********************************************************

	/**
	 * @brief Class for 4d vector.
	 *
	 * @tparam T Type of value in the vector.
	 *
	 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
	 */
	template <typename T>
	class Vec4
	{
	public:
		T	x;
		T	y;
		T	z;
		T	w;

		//**** INITIALISION ****************************************************
		//---- Constructors ----------------------------------------------------

		/**
		 * @brief Default constructor of Vec4 class.
		 *
		 * @return The Vec4 with values at 0.
		 */
		Vec4(void)
		{
			this->x = T();
			this->y = T();
			this->z = T();
			this->w = T();
		}

		/**
		 * @brief Copy constructor of Vec4 class.
		 *
		 * @param vec4 The Vec4 to copy.
		 *
		 * @return The Vec4 copied from parameter.
		 */
		Vec4(const Vec4 &vec4)
		{
			this->x = vec4.x;
			this->y = vec4.y;
			this->z = vec4.z;
			this->w = vec4.w;
		}

		/**
		 * @brief Constructor of Vec4 class from Vec2.
		 *
		 * @param vec2 The vec2 to based on.
		 *
		 * @return Vec4 with x and y from parameter and z and w at 0.
		 */
		Vec4(const Vec2<T> &vec2)
		{
			this->x = vec2.x;
			this->y = vec2.y;
			this->z = T();
			this->w = T();
		}

		/**
		 * @brief Constructor of Vec4 class from Vec2.
		 *
		 * @param vec2 The Vec2 to based on.
		 * @param z The z of the Vec4.
		 *
		 * @return Vec4 with x and y from vec2, z from z and w at 0.
		 */
		Vec4(const Vec2<T> &vec2, T z)
		{
			this->x = vec2.x;
			this->y = vec2.y;
			this->z = z;
			this->w = T();
		}

		/**
		 * @brief Constructor of Vec4 class from Vec2.
		 *
		 * @param vec2 The Vec2 to based on.
		 * @param z The z of the Vec4.
		 * @param w The w of the Vec4.
		 *
		 * @return Vec4 with x and y from vec2, z and w from parameters.
		 */
		Vec4(const Vec2<T> &vec2, T z, T w)
		{
			this->x = vec2.x;
			this->y = vec2.y;
			this->z = z;
			this->w = w;
		}

		/**
		 * @brief Constructor of Vec4 class from Vec3.
		 *
		 * @param vec3 The Vec3 to based on.
		 *
		 * @return Vec4 with x, y and z from vec3 and w at 0.
		 */
		Vec4(const Vec3<T> &vec3)
		{
			this->x = vec3.x;
			this->y = vec3.y;
			this->z = vec3.z;
			this->w = T();
		}

		/**
		 * @brief Constructor of Vec4 class from Vec3.
		 *
		 * @param vec3 The Vec3 to based on.
		 * @param w The w of the Vec4.
		 *
		 * @return Vec4 with x, y and z from vec3 and w at w.
		 */
		Vec4(const Vec3<T> &vec3, T w)
		{
			this->x = vec3.x;
			this->y = vec3.y;
			this->z = vec3.z;
			this->w = w;
		}

		/**
		 * @brief Constructor of Vec4 class.
		 *
		 * @param x x value of the Vec4.
		 * @param y y value of the Vec4.
		 * @param z z value of the Vec4.
		 * @param w w value of the Vec4.
		 *
		 * @return The Vec4 with parameter values.
		 */
		Vec4(T x, T y, T z, T w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		/**
		 * @brief Constructor of Vec4 class.
		 *
		 * @param value x, y, z and w values of Vec4.
		 *
		 * @return The Vec4 with parameter value.
		 */
		Vec4(T value)
		{
			this->x = value;
			this->y = value;
			this->z = value;
			this->w = value;
		}

		//---- Destructor ------------------------------------------------------

		~Vec4()
		{
		}

		//**** ACCESSORS *******************************************************
		//---- Getters ---------------------------------------------------------
		//---- Setters ---------------------------------------------------------
		//---- Modify Operators ------------------------------------------------

		Vec4	&operator=(const Vec4 &vec4)
		{
			if (this == &vec4)
				return (*this);

			this->x = vec4.x;
			this->y = vec4.y;
			this->z = vec4.z;
			this->w = vec4.w;

			return (*this);
		}

		Vec4	&operator+=(const Vec4 &vec4)
		{
			this->x += vec4.x;
			this->y += vec4.y;
			this->z += vec4.z;
			this->w += vec4.w;

			return (*this);
		}

		Vec4	&operator-=(const Vec4 &vec4)
		{
			this->x -= vec4.x;
			this->y -= vec4.y;
			this->z -= vec4.z;
			this->w -= vec4.w;

			return (*this);
		}

		Vec4	&operator*=(const T &value)
		{
			this->x *= value;
			this->y *= value;
			this->z *= value;
			this->w *= value;

			return (*this);
		}

		Vec4	&operator/=(const T &value)
		{
			this->x /= value;
			this->y /= value;
			this->z /= value;
			this->w /= value;

			return (*this);
		}

		//---- Compare Operators -----------------------------------------------

		bool	operator==(const Vec4 &vec4) const
		{
			return (this->x == vec4.x && this->y == vec4.y && this->z == vec4.z && this->w == vec4.w);
		}

		bool	operator!=(const Vec4 &vec4) const
		{
			return (this->x != vec4.x || this->y != vec4.y || this->z != vec4.z || this->w != vec4.w);
		}

		//---- Accessor Operators ----------------------------------------------

		/**
		 * @brief Access values by index.
		 *
		 * Index 0 is for x.
		 * Index 1 is for y.
		 * Index 2 is for z.
		 * Index 3 is for w.
		 * Other index will return an exception.
		 *
		 * @param n Index of the value wanted.
		 *
		 * @return The reference to value at the index.
		 * @exception Throw runtime_error when index is greater than 3.
		 */
		T	&operator[](unsigned int n)
		{
			if (n == 0)
				return (this->x);
			if (n == 1)
				return (this->y);
			if (n == 2)
				return (this->z);
			if (n == 3)
				return (this->w);

			throw std::runtime_error("Index out of vec4 bounds");
		}

		/**
		 * @brief Const access values by index.
		 *
		 * Index 0 is for x.
		 * Index 1 is for y.
		 * Index 2 is for z.
		 * Index 3 is for w.
		 * Other index will return an exception.
		 *
		 * @param n Index of the value wanted.
		 *
		 * @return The const reference to value at the index.
		 * @exception Throw runtime_error when index is greater than 3.
		 */
		const T	&operator[](unsigned int n) const
		{
			if (n == 0)
				return (this->x);
			if (n == 1)
				return (this->y);
			if (n == 2)
				return (this->z);
			if (n == 3)
				return (this->w);

			throw std::runtime_error("Index out of vec4 bounds");
		}

		//**** PUBLIC METHODS **************************************************
		//---- To vec2 ---------------------------------------------------------

		/**
		 * @brief Create a Vec2 from a subpart of the Vec4.
		 *
		 * @return A Vec2 with x and y as value.
		 */
		Vec2<T>	xy(void)
		{
			return	(Vec2<T>(this->x, this->y));
		}

		/**
		 * @brief Create a Vec2 from a subpart of the Vec4.
		 *
		 * @return A Vec2 with y and z as value.
		 */
		Vec2<T>	yz(void)
		{
			return	(Vec2<T>(this->y, this->z));
		}

		/**
		 * @brief Create a Vec2 from a subpart of the Vec4.
		 *
		 * @return A Vec2 with z and w as value.
		 */
		Vec2<T>	zw(void)
		{
			return	(Vec2<T>(this->z, this->w));
		}

		/**
		 * @brief Create a Vec2 from a subpart of the Vec4.
		 *
		 * @return A Vec2 with x and z as value.
		 */
		Vec2<T>	xz(void)
		{
			return	(Vec2<T>(this->x, this->z));
		}

		/**
		 * @brief Create a Vec2 from a subpart of the Vec4.
		 *
		 * @return A Vec2 with x and w as value.
		 */
		Vec2<T>	xw(void)
		{
			return	(Vec2<T>(this->x, this->w));
		}

		/**
		 * @brief Create a Vec2 from a subpart of the Vec4.
		 *
		 * @return A Vec2 with y and w as value.
		 */
		Vec2<T>	yw(void)
		{
			return	(Vec2<T>(this->y, this->w));
		}

		//---- To vec3 ---------------------------------------------------------

		/**
		 * @brief Create a Vec3 from a subpart of the Vec4.
		 *
		 * @return A Vec3 with x, y and z as value.
		 */
		Vec3<T>	xyz(void)
		{
			return	(Vec3<T>(this->x, this->y, this->z));
		}

		/**
		 * @brief Create a Vec3 from a subpart of the Vec4.
		 *
		 * @return A Vec3 with y, z and w as value.
		 */
		Vec3<T>	yzw(void)
		{
			return	(Vec3<T>(this->y, this->z, this->w));
		}

		/**
		 * @brief Create a Vec3 from a subpart of the Vec4.
		 *
		 * @return A Vec3 with x, z and w as value.
		 */
		Vec3<T>	xzw(void)
		{
			return	(Vec3<T>(this->x, this->z, this->w));
		}

	private:

	};

	//**** EXTERNS OPERATORS ***************************************************
	//---- Vector vector operator ----------------------------------------------

	template <typename T>
	Vec4<T>	operator+(const Vec4<T> &v1, const Vec4<T> &v2)
	{
		return (Vec4<T>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w));
	}

	template <typename T>
	Vec4<T>	operator-(const Vec4<T> &v1, const Vec4<T> &v2)
	{
		return (Vec4<T>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w));
	}

	//---- Vector value operator -----------------------------------------------

	template <typename T>
	Vec4<T>	operator*(const Vec4<T> &vec4, const T &value)
	{
		return (Vec4<T>(vec4.x * value, vec4.y * value, vec4.z * value, vec4.w * value));
	}

	template <typename T>
	Vec4<T>	operator*(const T &value, const Vec4<T> &vec4)
	{
		return (Vec4<T>(vec4.x * value, vec4.y * value, vec4.z * value, vec4.w * value));
	}

	template <typename T>
	Vec4<T>	operator/(const Vec4<T> &vec4, const T &value)
	{
		return (Vec4<T>(vec4.x / value, vec4.y / value, vec4.z / value, vec4.w / value));
	}

	//---- Print operator ------------------------------------------------------

	template <typename T>
	std::ostream	&operator<<(std::ostream &os, const Vec4<T> &vec4)
	{
		os << "(" << vec4.x << "," << vec4.y << "," << vec4.z << "," << vec4.w << ")";
		return (os);
	}

	//**** FUNCTIONS ***********************************************************

	/**
	 * @brief Get Vec4 norm.
	 *
	 * @param vec4 Vec4 to get the norm.
	 *
	 * @return Norm of vec4.
	 */
	template <typename T>
	T	norm(const Vec4<T> &vec4)
	{
		return (static_cast<T>(sqrt(static_cast<double>(vec4.x * vec4.x
														+ vec4.y * vec4.y
														+ vec4.z * vec4.z
														+ vec4.w * vec4.w))));
	}

	/**
	 * @brief Get Vec4 norm squared.
	 *
	 * @param vec4 Vec4 to get the norm squared.
	 *
	 * @return Norm squared of vec4.
	 */
	template <typename T>
	T	norm2(const Vec4<T> &vec4)
	{
		return (vec4.x * vec4.x + vec4.y * vec4.y + vec4.z * vec4.z + vec4.w * vec4.w);
	}

	/**
	 * @brief Normalize a Vec4.
	 *
	 * @param vec4 Vec4 to normalize.
	 *
	 * @return Normalised vec4, or vec4 if it's norm is 0.
	 */
	template <typename T>
	Vec4<T>	normalize(const Vec4<T> &vec4)
	{
		T	dst = norm2(vec4);

		if (dst == static_cast<T>(0) || dst == static_cast<T>(1))
			return (vec4);

		T	toDiv = static_cast<T>(1) / static_cast<T>(sqrt(static_cast<double>(dst)));
		return (vec4 * toDiv);
	}

	/**
	 * @brief Dot product between two Vec4.
	 *
	 * @param v1 First Vec4.
	 * @param v2 Second Vec4.
	 *
	 * @return Dot product of v1 with v2.
	 */
	template <typename T>
	T	dot(const Vec4<T> &v1, const Vec4<T> &v2)
	{
		return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w);
	}

	/**
	 * @brief Get the hash of a Vec4.
	 *
	 * @param vec4 Vec4 to hash.
	 *
	 * @return Hash of Vec4.
	 */
	template <typename T>
	std::size_t	hash(const Vec4<T> &vec4)
	{
		std::size_t	hash = 0;

		hash = std::hash<T>{}(vec4.x) + 0x9e3779b9 + (hash<<6) + (hash>>2);
		hash = std::hash<T>{}(vec4.y) + 0x9e3779b9 + (hash<<6) + (hash>>2);
		hash = std::hash<T>{}(vec4.z) + 0x9e3779b9 + (hash<<6) + (hash>>2);
		hash = std::hash<T>{}(vec4.w) + 0x9e3779b9 + (hash<<6) + (hash>>2);

		return (hash);
	}

	//**** STATIC FUNCTIONS ****************************************************
	//**** USINGS **************************************************************
	//---- VEC4 ----------------------------------------------------------------

	/**
	 * @brief Class for 4d unsigned int vector.
	 *
	 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
	 */
	using Vec4u = Vec4<unsigned int>;
	/**
	 * @brief Class for 4d int vector.
	 *
	 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
	 */
	using Vec4i = Vec4<int>;
	/**
	 * @brief Class for 4d float vector.
	 *
	 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
	 */
	using Vec4f = Vec4<float>;
	/**
	 * @brief Class for 4d double vector.
	 *
	 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
	 */
	using Vec4d = Vec4<double>;

	//---- POINT4 --------------------------------------------------------------

	/**
	 * @brief Class for 4d unsigned int vector.
	 *
	 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
	 */
	using Point4u = Vec4<unsigned int>;
	/**
	 * @brief Class for 4d int vector.
	 *
	 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
	 */
	using Point4i = Vec4<int>;
	/**
	 * @brief Class for 4d float vector.
	 *
	 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
	 */
	using Point4f = Vec4<float>;
	/**
	 * @brief Class for 4d double vector.
	 *
	 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
	 */
	using Point4d = Vec4<double>;
}

#endif
