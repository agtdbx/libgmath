#ifndef VEC3_HPP
# define VEC3_HPP

# include <gmath/Vec2.hpp>

#include <cmath>
#include <iostream>
#include <stdexcept>

//**** STATIC FUNCTIONS DEFINE *************************************************
//**** CLASS DEFINE ************************************************************

/**
 * @brief Class for 3d vector.
 *
 * @tparam T Type of value in the vector.
 *
 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
 */
template <typename T>
class Vec3
{
public:
	T	x;
	T	y;
	T	z;

	//**** INITIALISION ********************************************************
	//---- Constructors --------------------------------------------------------

	/**
	 * @brief Default constructor of Vec3 class.
	 *
	 * @return The Vec3 with values at 0.
	 */
	Vec3(void)
	{
		this->x = T();
		this->y = T();
		this->z = T();
	}

	/**
	 * @brief Copy constructor of Vec3 class.
	 *
	 * @param vec3 The Vec3 to copy.
	 *
	 * @return The Vec3 copied from parameter.
	 */
	Vec3(const Vec3 &vec3)
	{
		this->x = vec3.x;
		this->y = vec3.y;
		this->z = vec3.z;
	}

	/**
	 * @brief Constructor of Vec3 class from Vec2.
	 *
	 * @param vec2 The Vec2 to based on.
	 *
	 * @return Vec3 with x and y from parameter and z at 0.
	 */
	Vec3(const Vec2<T> &vec2)
	{
		this->x = vec2.x;
		this->y = vec2.y;
		this->z = T();
	}

	/**
	 * @brief Constructor of Vec3 class from Vec2.
	 *
	 * @param vec2 The Vec2 to based on.
	 * @param z The z of the Vec3.
	 *
	 * @return Vec3 with x and y from vec2 and z from z.
	 */
	Vec3(const Vec2<T> &vec2, T z)
	{
		this->x = vec2.x;
		this->y = vec2.y;
		this->z = z;
	}

	/**
	 * @brief Constructor of Vec3 class.
	 *
	 * @param x x value of the Vec3.
	 * @param y y value of the Vec3.
	 * @param z z value of the Vec3.
	 *
	 * @return The Vec3 with parameter values.
	 */
	Vec3(T x, T y, T z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	//---- Destructor ----------------------------------------------------------

	~Vec3()
	{
	}

	//**** ACCESSORS ***********************************************************
	//---- Getters -------------------------------------------------------------
	//---- Setters -------------------------------------------------------------
	//---- Modify Operators ----------------------------------------------------

	Vec3	&operator=(const Vec3 &vec3)
	{
		if (this == &vec3)
			return (*this);

		this->x = vec3.x;
		this->y = vec3.y;
		this->z = vec3.z;

		return (*this);
	}

	Vec3	&operator+=(const Vec3 &vec3)
	{
		this->x += vec3.x;
		this->y += vec3.y;
		this->z += vec3.z;

		return (*this);
	}

	Vec3	&operator-=(const Vec3 &vec3)
	{
		this->x -= vec3.x;
		this->y -= vec3.y;
		this->z -= vec3.z;

		return (*this);
	}

	Vec3	&operator*=(const T &value)
	{
		this->x *= value;
		this->y *= value;
		this->z *= value;

		return (*this);
	}

	Vec3	&operator/=(const T &value)
	{
		this->x /= value;
		this->y /= value;
		this->z /= value;

		return (*this);
	}

	//---- Compare Operators ---------------------------------------------------

	bool	operator==(const Vec3 &vec3) const
	{
		return (this->x == vec3.x && this->y == vec3.y && this->z == vec3.z);
	}

	bool	operator!=(const Vec3 &vec3) const
	{
		return (this->x != vec3.x || this->y != vec3.y || this->z != vec3.z);
	}

	//---- Accessor Operators --------------------------------------------------

	/**
	 * @brief Access values by index.
	 *
	 * Index 0 is for x.
	 * Index 1 is for y.
	 * Index 2 is for z.
	 * Other index will return an exception.
	 *
	 * @param n Index of the value wanted.
	 *
	 * @return The value at the index.
	 * @exception Throw runtime_error when index is greater than 2.
	 */
	T	&operator[](unsigned int n)
	{
		if (n == 0)
			return (this->x);
		if (n == 1)
			return (this->y);
		if (n == 2)
			return (this->z);

		throw std::runtime_error("Index out of vec3 bounds");
	}

	//**** PUBLIC METHODS ******************************************************

	/**
	 * @brief Create a Vec2 from a subpart of the Vec3.
	 *
	 * @return A Vec2 with x and y as value.
	 */
	Vec2<T>	xy(void)
	{
		return	(Vec2<T>(this->x, this->y));
	}

	/**
	 * @brief Create a Vec2 from a subpart of the Vec3.
	 *
	 * @return A Vec2 with y and z as value.
	 */
	Vec2<T>	yz(void)
	{
		return	(Vec2<T>(this->y, this->z));
	}

	/**
	 * @brief Create a Vec2 from a subpart of the Vec3.
	 *
	 * @return A Vec2 with x and z as value.
	 */
	Vec2<T>	xz(void)
	{
		return	(Vec2<T>(this->x, this->z));
	}

private:

};

//**** EXTERNS OPERATORS *******************************************************
//---- Vector vector operator --------------------------------------------------

template <typename T>
Vec3<T>	operator+(const Vec3<T> &v1, const Vec3<T> &v2)
{
	return (Vec3<T>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

template <typename T>
Vec3<T>	operator-(const Vec3<T> &v1, const Vec3<T> &v2)
{
	return (Vec3<T>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

//---- Vector value operator ---------------------------------------------------

template <typename T>
Vec3<T>	operator*(const Vec3<T> &vec3, const T &value)
{
	return (Vec3<T>(vec3.x * value, vec3.y * value, vec3.z * value));
}

template <typename T>
Vec3<T>	operator*(const T &value, const Vec3<T> &vec3)
{
	return (Vec3<T>(vec3.x * value, vec3.y * value, vec3.z * value));
}

template <typename T>
Vec3<T>	operator/(const Vec3<T> &vec3, const T &value)
{
	return (Vec3<T>(vec3.x / value, vec3.y / value, vec3.z / value));
}

//---- Print operator ----------------------------------------------------------

template <typename T>
std::ostream	&operator<<(std::ostream &os, const Vec3<T> &vec3)
{
	os << "(" << vec3.x << "," << vec3.y << "," << vec3.z << ")";
	return (os);
}

//**** FUNCTIONS ***************************************************************

/**
 * @brief Get Vec3 norm.
 *
 * @param vec3 Vec3 to get the norm.
 *
 * @return Norm of vec3.
 */
template <typename T>
T	norm(const Vec3<T> &vec3)
{
	return (static_cast<T>(sqrt(static_cast<double>(vec3.x * vec3.x
													+ vec3.y * vec3.y
													+ vec3.z * vec3.z))));
}

/**
 * @brief Get Vec3 norm squared.
 *
 * @param vec3 Vec3 to get the norm squared.
 *
 * @return Norm squared of vec3.
 */
template <typename T>
T	norm2(const Vec3<T> &vec3)
{
	return (vec3.x * vec3.x + vec3.y * vec3.y + vec3.z * vec3.z);
}

/**
 * @brief Normalize a Vec3.
 *
 * @param vec3 Vec3 to normalize.
 *
 * @return Normalised vec3, or vec3 if it's norm is 0.
 */
template <typename T>
Vec3<T>	normalize(const Vec3<T> &vec3)
{
	T	dst = norm2(vec3);

	if (dst == static_cast<T>(0) || dst == static_cast<T>(1))
		return (vec3);
	return (vec3 / static_cast<T>(sqrt(static_cast<double>(dst))));
}

/**
 * @brief Dot product between two Vec3.
 *
 * @param v1 First Vec3.
 * @param v2 Second Vec3.
 *
 * @return Dot product of v1 with v2.
 */
template <typename T>
T	dot(const Vec3<T> &v1, const Vec3<T> &v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

/**
 * @brief Cross product between two Vec2.
 *
 * @param v1 First Vec2.
 * @param v2 Second Vec2.
 *
 * @return Crpss product of v1 with v2.
 */
template <typename T>
Vec3<T>	cross(const Vec3<T> &v1, const Vec3<T> &v2)
{
	T	x = (v1.y * v2.z) - (v1.z * v2.y);
	T	y = (v1.z * v2.x) - (v1.x * v2.z);
	T	z = (v1.x * v2.y) - (v1.y * v2.z);

	return (Vec3<T>(x, y, z));
}

//**** STATIC FUNCTIONS ********************************************************
//**** USINGS ******************************************************************
//---- VEC3 --------------------------------------------------------------------

/**
 * @brief Class for 3d unsigned int vector.
 *
 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
 */
using Vec3u = Vec3<unsigned int>;
/**
 * @brief Class for 3d int vector.
 *
 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
 */
using Vec3i = Vec3<int>;
/**
 * @brief Class for 3d float vector.
 *
 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
 */
using Vec3f = Vec3<float>;
/**
 * @brief Class for 3d double vector.
 *
 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
 */
using Vec3d = Vec3<double>;

//---- POINT3 ------------------------------------------------------------------

/**
 * @brief Class for 3d unsigned int vector.
 *
 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
 */
using Point3u = Vec3<unsigned int>;
/**
 * @brief Class for 3d int vector.
 *
 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
 */
using Point3i = Vec3<int>;
/**
 * @brief Class for 3d float vector.
 *
 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
 */
using Point3f = Vec3<float>;
/**
 * @brief Class for 3d double vector.
 *
 * The class is design to be used with graphic librairy like OpenGL or Vulkan.
 */
using Point3d = Vec3<double>;

#endif
