#ifndef VEC4_HPP
# define VEC4_HPP

# include <gmath/utils.hpp>
# include <gmath/Vec2.hpp>
# include <gmath/Vec3.hpp>

#include <iostream>
#include <stdexcept>

//**** STATIC FUNCTIONS DEFINE *************************************************

//**** CLASS DEFINE ************************************************************
template <typename T>
class Vec4
{
public:
	T	x;
	T	y;
	T	z;
	T	w;

	//**** INITIALISION ********************************************************
	//---- Constructors --------------------------------------------------------

	Vec4(void)
	{
		this->x = T();
		this->y = T();
		this->z = T();
		this->w = T();
	}


	Vec4(const Vec4 &vec4)
	{
		this->x = vec4.x;
		this->y = vec4.y;
		this->z = vec4.z;
		this->w = vec4.w;
	}


	Vec4(const Vec2<T> &vec2)
	{
		this->x = vec2.x;
		this->y = vec2.y;
		this->z = T();
		this->w = T();
	}


	Vec4(const Vec2<T> &vec2, T z)
	{
		this->x = vec2.x;
		this->y = vec2.y;
		this->z = z;
		this->w = T();
	}


	Vec4(const Vec2<T> &vec2, T z, T w)
	{
		this->x = vec2.x;
		this->y = vec2.y;
		this->z = z;
		this->w = w;
	}


	Vec4(const Vec3<T> &vec3)
	{
		this->x = vec3.x;
		this->y = vec3.y;
		this->z = vec3.z;
		this->w = T();
	}


	Vec4(const Vec3<T> &vec3, T w)
	{
		this->x = vec3.x;
		this->y = vec3.y;
		this->z = vec3.z;
		this->w = w;
	}


	Vec4(T x, T y, T z, T w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	//---- Destructor ----------------------------------------------------------

	~Vec4()
	{
	}

	//**** ACCESSORS ***********************************************************
	//---- Getters -------------------------------------------------------------

	//---- Setters -------------------------------------------------------------

	//---- Modify Operators ----------------------------------------------------

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

	//---- Compare Operators ---------------------------------------------------

	bool	operator==(const Vec4 &vec4) const
	{
		return (this->x == vec4.x && this->y == vec4.y && this->z == vec4.z && this->w == vec4.w);
	}


	bool	operator!=(const Vec4 &vec4) const
	{
		return (this->x != vec4.x || this->y != vec4.y || this->z != vec4.z || this->w != vec4.w);
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
		if (n == 3)
			return (this->w);

		throw std::runtime_error("Index out of vec4 bounds");
	}

	//**** PUBLIC METHODS ******************************************************
	//---- To vec2 -------------------------------------------------------------

	Vec2<T>	xy(void)
	{
		return	(Vec2<T>(this->x, this->y));
	}


	Vec2<T>	yz(void)
	{
		return	(Vec2<T>(this->y, this->z));
	}


	Vec2<T>	zw(void)
	{
		return	(Vec2<T>(this->z, this->w));
	}


	Vec2<T>	xz(void)
	{
		return	(Vec2<T>(this->x, this->z));
	}


	Vec2<T>	xw(void)
	{
		return	(Vec2<T>(this->x, this->w));
	}


	Vec2<T>	yw(void)
	{
		return	(Vec2<T>(this->y, this->w));
	}

	//---- To vec3 -------------------------------------------------------------

	Vec3<T>	xyz(void)
	{
		return	(Vec3<T>(this->x, this->y, this->z));
	}


	Vec3<T>	yzw(void)
	{
		return	(Vec3<T>(this->y, this->z, this->w));
	}


	Vec3<T>	xzw(void)
	{
		return	(Vec3<T>(this->x, this->z, this->w));
	}

private:

};

//**** EXTERNS OPERATORS *******************************************************
//---- Vector vector operator --------------------------------------------------

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

//---- Vector value operator ---------------------------------------------------

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

//---- Print operator ----------------------------------------------------------

template <typename T>
std::ostream	&operator<<(std::ostream &os, const Vec4<T> &vec4)
{
	os << "(" << vec4.x << "," << vec4.y << "," << vec4.z << "," << vec4.w << ")";
	return (os);
}

//**** FUNCTIONS ***************************************************************

template <typename T>
T	norm(const Vec4<T> &vec4)
{
	return (sqrt(vec4.x * vec4.x + vec4.y * vec4.y + vec4.z * vec4.z + vec4.w * vec4.w));
}


template <typename T>
Vec4<T>	normalize(const Vec4<T> &vec4)
{
	T	dst = norm(vec4);

	if (dst == T())
		return (vec4);
	return (vec4 / dst);
}

//**** STATIC FUNCTIONS ********************************************************

//**** USINGS ******************************************************************

// Vec4
using Vec4u = Vec4<unsigned int>;
using Vec4i = Vec4<int>;
using Vec4f = Vec4<float>;
using Vec4d = Vec4<double>;

// Point4
using Point4u = Vec4<unsigned int>;
using Point4i = Vec4<int>;
using Point4f = Vec4<float>;
using Point4d = Vec4<double>;

#endif
