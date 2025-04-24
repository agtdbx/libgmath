#ifndef VEC2_HPP
# define VEC2_HPP

# include <iostream>

template <typename T>
class Vec2
{
public:
	//**** PUBLIC ATTRIBUTS ***************************************************
	T	x;
	T	y;

	//**** CONSTRUCTORS AND DESTRUCTOR ****************************************
	//---- Default contructors ------------------------------------------------

	Vec2(void)
	{
	};

	Vec2(const Vec2& vec2)
	{
		this->x = vec2.x;
		this->y = vec2.y;
	}

	//---- Customs contructors ------------------------------------------------

	Vec2(const T& x, const T& y)
	{
		this->x = x;
		this->y = y;
	}

	//---- Destructor ---------------------------------------------------------

	~Vec2()
	{
	};

	//**** OPERATORS **********************************************************
	//---- Copy ----------------------------------------------------------

	Vec2	&operator=(const Vec2& vec2)
	{
		if (this == &vec2)
			return (*this);

		this->x = vec2.x;
		this->y = vec2.y;

		return (*this);
	}
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vec2<T>& vec2)
{
	os << "(" << vec2.x << "," << vec2.y << ")";
	return (os);
}

#endif
