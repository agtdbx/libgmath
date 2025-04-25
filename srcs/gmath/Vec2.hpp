#ifndef VEC2_HPP
# define VEC2_HPP

# include <gmath/utils.hpp>

#include <iostream>
#include <stdexcept>

//**** STATIC FUNCTIONS DEFINE *************************************************

//**** CLASS DEFINE ************************************************************
template <typename T>
class Vec2
{
public:
	T	x;
	T	y;
	T	&r;
	T	&g;

	//**** INITIALISION ********************************************************
	//---- Constructors --------------------------------------------------------

	Vec2(void)
	: x(), y(), r(this->x), g(this->y)
	{
	}


	Vec2(const Vec2 &vec2)
	: x(), y(), r(this->x), g(this->y)
	{
		this->x = vec2.x;
		this->y = vec2.y;
	}


	Vec2(T x, T y)
	: x(), y(), r(this->x), g(this->y)
	{
		this->x = x;
		this->y = y;
	}

	//---- Destructor ----------------------------------------------------------

	~Vec2()
	{

	}

	//**** ACCESSORS ***********************************************************
	//---- Getters -------------------------------------------------------------

	//---- Setters -------------------------------------------------------------

	//---- Modify Operators ----------------------------------------------------

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

	//---- Compare Operators ---------------------------------------------------

	bool	operator==(const Vec2 &vec2) const
	{
		return (this->x == vec2.x && this->y == vec2.y);
	}


	bool	operator!=(const Vec2 &vec2) const
	{
		return (this->x != vec2.x || this->y != vec2.y);
	}

	//---- Accessor Operators --------------------------------------------------

	T	&operator[](unsigned int n)
	{
		if (n == 0)
			return (this->x);
		if (n == 1)
			return (this->y);

		throw std::runtime_error("Out of vec2 bounds index");
	}

private:

};

//**** EXTERNS OPERATORS *******************************************************
//---- Vector vector operator --------------------------------------------------

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

//---- Vector value operator ---------------------------------------------------

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

//---- Print operator ----------------------------------------------------------

template <typename T>
std::ostream	&operator<<(std::ostream &os, const Vec2<T> &vec2)
{
	os << "(" << vec2.x << "," << vec2.y << ")";
	return (os);
}

//**** FUNCTIONS ***************************************************************

template <typename T>
T	norm(const Vec2<T> &vec2)
{
	return (sqrt(vec2.x * vec2.x + vec2.y * vec2.y));
}


template <typename T>
Vec2<T>	normalize(const Vec2<T> &vec2)
{
	T	dst = norm(vec2);

	if (dst == 0)
		return (vec2);
	return (vec2 / dst);
}

//**** STATIC FUNCTIONS ********************************************************

//**** USINGS ******************************************************************

// Vec2
using Vec2u = Vec2<unsigned int>;
using Vec2i = Vec2<int>;
using Vec2f = Vec2<float>;
using Vec2d = Vec2<double>;

// Point2
using Point2u = Vec2<unsigned int>;
using Point2i = Vec2<int>;
using Point2f = Vec2<float>;
using Point2d = Vec2<double>;

#endif
