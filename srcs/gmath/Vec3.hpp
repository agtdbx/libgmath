#ifndef VEC3_HPP
# define VEC3_HPP

# include <gmath/utils.hpp>
# include <gmath/Vec2.hpp>

#include <iostream>
#include <stdexcept>

//**** STATIC FUNCTIONS DEFINE *************************************************

//**** CLASS DEFINE ************************************************************
template <typename T>
class Vec3
{
public:
	T	x;
	T	y;
	T	z;

	//**** INITIALISION ********************************************************
	//---- Constructors --------------------------------------------------------

	Vec3(void)
	{
		this->x = T();
		this->y = T();
		this->z = T();
	}


	Vec3(const Vec3 &vec3)
	{
		this->x = vec3.x;
		this->y = vec3.y;
		this->z = vec3.z;
	}


	Vec3(const Vec2<T> &vec2)
	{
		this->x = vec2.x;
		this->y = vec2.y;
		this->z = T();
	}


	Vec3(const Vec2<T> &vec2, T z)
	{
		this->x = vec2.x;
		this->y = vec2.y;
		this->z = z;
	}


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

	T	&operator[](unsigned int n)
	{
		if (n == 0)
			return (this->x);
		if (n == 1)
			return (this->y);
		if (n == 2)
			return (this->z);

		throw std::runtime_error("Out of vec3 bounds index");
	}

	//**** PUBLIC METHODS ******************************************************

	Vec2<T>	xy(void)
	{
		return	(Vec2<T>(this->x, this->y));
	}


	Vec2<T>	yz(void)
	{
		return	(Vec2<T>(this->y, this->z));
	}


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

template <typename T>
T	norm(const Vec3<T> &vec3)
{
	return (sqrt(vec3.x * vec3.x + vec3.y * vec3.y + vec3.z * vec3.z));
}


template <typename T>
Vec3<T>	normalize(const Vec3<T> &vec3)
{
	T	dst = norm(vec3);

	if (dst == T())
		return (vec3);
	return (vec3 / dst);
}

//**** STATIC FUNCTIONS ********************************************************

//**** USINGS ******************************************************************

// Vec3
using Vec3u = Vec3<unsigned int>;
using Vec3i = Vec3<int>;
using Vec3f = Vec3<float>;
using Vec3d = Vec3<double>;

// Point3
using Point3u = Vec3<unsigned int>;
using Point3i = Vec3<int>;
using Point3f = Vec3<float>;
using Point3d = Vec3<double>;

#endif
