#ifndef MAT2_HPP
# define MAT2_HPP

# define MAT2_SIZE 4

# include <gmath/Vec2.hpp>

#include <cmath>
#include <iostream>
#include <stdexcept>

//**** STATIC FUNCTIONS DEFINE *************************************************

//**** CLASS DEFINE ************************************************************
template <typename T>
class Mat2
{
public:
	T	values[MAT2_SIZE];

	//**** INITIALISION ********************************************************
	//---- Constructors --------------------------------------------------------

	Mat2(void)
	{
		for (int i = 0; i < MAT2_SIZE; i++)
			this->values[i] = T();
	}


	Mat2(const Mat2 &mat2)
	{
		for (int i = 0; i < MAT2_SIZE; i++)
			this->values[i] = mat2.values[i];
	}


	Mat2(const T values[MAT2_SIZE])
	{
		for (int i = 0; i < MAT2_SIZE; i++)
			this->values[i] = values[i];
	}


	Mat2(T x1, T x2, T y1, T y2)
	{
		this->values[0] = x1;
		this->values[1] = x2;
		this->values[2] = y1;
		this->values[3] = y2;
	}

	//---- Destructor ----------------------------------------------------------

	~Mat2()
	{
	}

	//**** ACCESSORS ***********************************************************
	//---- Getters -------------------------------------------------------------

	T	get(unsigned int x, unsigned int y) const
	{
		if (x >= 2 || y >= 2)
			throw std::runtime_error("Index out of mat2 bounds");
		return (this->values[x + y * 2]);
	}


	T	&at(unsigned int x, unsigned int y)
	{
		return (this->values[x + y * 2]);
	}

	//---- Setters -------------------------------------------------------------

	void	set(unsigned int x, unsigned int y, const T &value)
	{
		if (x >= 2 || y >= 2)
			throw std::runtime_error("Index out of mat2 bounds");
		this->values[x + y * 2] = value;
	}

	//---- Modify Operators ----------------------------------------------------

	Mat2	&operator=(const Mat2 &mat2)
	{
		if (this == &mat2)
			return (*this);

		for (int i = 0; i < MAT2_SIZE; i++)
			this->values[i] = mat2.values[i];

		return (*this);
	}


	Mat2	&operator+=(const Mat2 &mat2)
	{
		for (int i = 0; i < MAT2_SIZE; i++)
			this->values[i] += mat2.values[i];

		return (*this);
	}


	Mat2	&operator-=(const Mat2 &mat2)
	{
		for (int i = 0; i < MAT2_SIZE; i++)
			this->values[i] -= mat2.values[i];

		return (*this);
	}


	Mat2	&operator*=(const T &value)
	{
		for (int i = 0; i < MAT2_SIZE; i++)
			this->values[i] *= value;

		return (*this);
	}


	Mat2	&operator/=(const T &value)
	{
		for (int i = 0; i < MAT2_SIZE; i++)
			this->values[i] /= value;

		return (*this);
	}

	//---- Compare Operators ---------------------------------------------------

	bool	operator==(const Mat2 &mat2) const
	{
		for (int i = 0; i < MAT2_SIZE; i++)
			if (this->values[i] != mat2.values[i])
				return (false);

		return (true);
	}


	bool	operator!=(const Mat2 &mat2) const
	{
		for (int i = 0; i < MAT2_SIZE; i++)
			if (this->values[i] != mat2.values[i])
				return (true);

		return (false);
	}

	//---- Accessor Operators --------------------------------------------------

	T	&operator[](unsigned int n)
	{
		if (n >= MAT2_SIZE)
			throw std::runtime_error("Index out of mat2 bounds");

		return (this->values[n]);
	}


	T	&operator[](const Vec2u &vec2)
	{
		if (vec2.x >= 2 || vec2.y >= 2)
			throw std::runtime_error("Index out of mat2 bounds");
		return (this->values[vec2.x + vec2.y * 2]);
	}

	//**** PUBLIC METHODS ******************************************************

	//**** STATIC METHODS ******************************************************

	static Mat2<T>	identity(void)
	{
		Mat2<T>	res;

		res.values[0] = static_cast<T>(1);
		res.values[3] = static_cast<T>(1);

		return (res);
	}


	static Mat2<T>	rotation(T radian)
	{
		Mat2<T>	res;
		T		tmpCos = cos(radian);
		T		tmpSin = sin(radian);

		res.values[0] = tmpCos;
		res.values[1] = -tmpSin;
		res.values[2] = tmpSin;
		res.values[3] = tmpCos;

		return (res);
	}

private:

};

//**** EXTERNS OPERATORS *******************************************************
//---- Matrix matrix operator --------------------------------------------------

template <typename T>
Mat2<T>	operator+(const Mat2<T> &m1, const Mat2<T> &m2)
{
	Mat2<T>	res;

	for (int i = 0; i < MAT2_SIZE; i++)
		res.values[i] = m1.values[i] + m2.values[i];

	return (res);
}


template <typename T>
Mat2<T>	operator-(const Mat2<T> &m1, const Mat2<T> &m2)
{
	Mat2<T>	res;

	for (int i = 0; i < MAT2_SIZE; i++)
		res.values[i] = m1.values[i] - m2.values[i];

	return (res);
}


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

//---- Matrix value operator ---------------------------------------------------

template <typename T>
Mat2<T>	operator*(const Mat2<T> &mat2, const T &value)
{
	Mat2<T>	res;

	for (int i = 0; i < MAT2_SIZE; i++)
		res.values[i] = mat2.values[i] * value;

	return (res);
}


template <typename T>
Mat2<T>	operator*(const T &value, const Mat2<T> &mat2)
{
	Mat2<T>	res;

	for (int i = 0; i < MAT2_SIZE; i++)
		res.values[i] = mat2.values[i] * value;

	return (res);
}


template <typename T>
Mat2<T>	operator/(const Mat2<T> &mat2, const T &value)
{
	Mat2<T>	res;

	for (int i = 0; i < MAT2_SIZE; i++)
		res.values[i] = mat2.values[i] / value;

	return (res);
}

//---- Print operator ----------------------------------------------------------

template <typename T>
std::ostream	&operator<<(std::ostream &os, const Mat2<T> &mat2)
{
	os << "|(" << mat2.values[0] << "," << mat2.values[1] << ");(" << mat2.values[2] << "," << mat2.values[3] << ")|";
	return (os);
}

//**** FUNCTIONS ***************************************************************

//**** STATIC FUNCTIONS ********************************************************

//**** USINGS ******************************************************************

// Mat2
using Mat2u = Mat2<unsigned int>;
using Mat2i = Mat2<int>;
using Mat2f = Mat2<float>;
using Mat2d = Mat2<double>;

#endif
