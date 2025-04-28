#ifndef MAT3_HPP
# define MAT3_HPP

# define MAT3_SIZE 9

# include <gmath/Vec3.hpp>
# include <gmath/Mat2.hpp>

#include <cmath>
#include <iostream>
#include <stdexcept>

//**** STATIC FUNCTIONS DEFINE *************************************************

//**** CLASS DEFINE ************************************************************
template <typename T>
class Mat3
{
public:
	T	values[MAT3_SIZE];

	//**** INITIALISION ********************************************************
	//---- Constructors --------------------------------------------------------

	Mat3(void)
	{
		for (int i = 0; i < MAT3_SIZE; i++)
			this->values[i] = T();
	}


	Mat3(const Mat3 &mat3)
	{
		for (int i = 0; i < MAT3_SIZE; i++)
			this->values[i] = mat3.values[i];
	}


	Mat3(const T values[MAT3_SIZE])
	{
		for (int i = 0; i < MAT3_SIZE; i++)
			this->values[i] = values[i];
	}


	Mat3(T x1, T x2, T x3, T y1, T y2, T y3, T z1, T z2, T z3)
	{
		this->values[0] = x1;
		this->values[1] = x2;
		this->values[2] = x3;
		this->values[3] = y1;
		this->values[4] = y2;
		this->values[5] = y3;
		this->values[6] = z1;
		this->values[7] = z2;
		this->values[8] = z3;
	}


	Mat3(const Mat2<T> &mat2)
	{
		this->values[0] = mat2.values[0];
		this->values[1] = mat2.values[1];
		this->values[2] = T();
		this->values[3] = mat2.values[2];
		this->values[4] = mat2.values[3];
		this->values[5] = T();
		this->values[6] = T();
		this->values[7] = T();
		this->values[8] = T();
	}

	//---- Destructor ----------------------------------------------------------

	~Mat3()
	{
	}

	//**** ACCESSORS ***********************************************************
	//---- Getters -------------------------------------------------------------

	//---- Setters -------------------------------------------------------------

	//---- Modify Operators ----------------------------------------------------

	Mat3	&operator=(const Mat3 &mat3)
	{
		if (this == &mat3)
			return (*this);

		for (int i = 0; i < MAT3_SIZE; i++)
			this->values[i] = mat3.values[i];

		return (*this);
	}


	Mat3	&operator+=(const Mat3 &mat3)
	{
		for (int i = 0; i < MAT3_SIZE; i++)
			this->values[i] += mat3.values[i];

		return (*this);
	}


	Mat3	&operator-=(const Mat3 &mat3)
	{
		for (int i = 0; i < MAT3_SIZE; i++)
			this->values[i] -= mat3.values[i];

		return (*this);
	}


	Mat3	&operator*=(const T &value)
	{
		for (int i = 0; i < MAT3_SIZE; i++)
			this->values[i] *= value;

		return (*this);
	}


	Mat3	&operator/=(const T &value)
	{
		for (int i = 0; i < MAT3_SIZE; i++)
			this->values[i] /= value;

		return (*this);
	}

	//---- Compare Operators ---------------------------------------------------

	bool	operator==(const Mat3 &mat3) const
	{
		for (int i = 0; i < MAT3_SIZE; i++)
			if (this->values[i] != mat3.values[i])
				return (false);

		return (true);
	}


	bool	operator!=(const Mat3 &mat3) const
	{
		for (int i = 0; i < MAT3_SIZE; i++)
			if (this->values[i] != mat3.values[i])
				return (true);

		return (false);
	}

	//---- Accessor Operators --------------------------------------------------

	T	&operator[](unsigned int n)
	{
		if (n >= MAT3_SIZE)
			throw std::runtime_error("Index out of mat3 bounds");

		return (this->values[n]);
	}

	//**** PUBLIC METHODS ******************************************************

	Mat2<T>	asMat2(void) const
	{
		Mat2<T>	res;

		res.values[0] = this->values[0];
		res.values[1] = this->values[1];
		res.values[2] = this->values[3];
		res.values[3] = this->values[4];

		return (res);
	}

	//**** STATIC METHODS ******************************************************

	static Mat3<T>	identity(void)
	{
		Mat3<T>	res;

		res.values[0] = T(1);
		res.values[4] = T(1);
		res.values[8] = T(1);

		return (res);
	}


	static Mat3<T>	rotation(const Vec3<T> &axis, T radian)
	{
		Mat3<T>	res;
		T		tmpCos = cos(radian);
		T		tmpSin = sin(radian);
		T		invTmpCos = T(1) - tmpCos;
		T		tmpSinAx = tmpSin * axis.x;
		T		tmpSinAy = tmpSin * axis.y;
		T		tmpSinAz = tmpSin * axis.z;

		// Line 1
		res.values[0] = (axis.x * axis.x) * invTmpCos + tmpCos;
		res.values[1] = (axis.x * axis.y) * invTmpCos - tmpSinAz;
		res.values[2] = (axis.x * axis.z) * invTmpCos + tmpSinAy;
		// Line 2
		res.values[3] = (axis.y * axis.x) * invTmpCos + tmpSinAz;
		res.values[4] = (axis.y * axis.y) * invTmpCos + tmpCos;
		res.values[5] = (axis.y * axis.z) * invTmpCos - tmpSinAx;
		// Line 3
		res.values[6] = (axis.z * axis.x) * invTmpCos - tmpSinAy;
		res.values[7] = (axis.z * axis.y) * invTmpCos + tmpSinAx;
		res.values[8] = (axis.z * axis.z) * invTmpCos + tmpCos;

		return (res);
	}

private:

};

//**** EXTERNS OPERATORS *******************************************************
//---- Matrix matrix operator --------------------------------------------------

template <typename T>
Mat3<T>	operator+(const Mat3<T> &m1, const Mat3<T> &m2)
{
	Mat3<T>	res;

	for (int i = 0; i < MAT3_SIZE; i++)
		res.values[i] = m1.values[i] + m2.values[i];

	return (res);
}


template <typename T>
Mat3<T>	operator-(const Mat3<T> &m1, const Mat3<T> &m2)
{
	Mat3<T>	res;

	for (int i = 0; i < MAT3_SIZE; i++)
		res.values[i] = m1.values[i] - m2.values[i];

	return (res);
}


template <typename T>
Mat3<T>	operator*(const Mat3<T> &m1, const Mat3<T> &m2)
{
	Mat3<T>	res;

	res.values[0] = m1.values[0] * m2.values[0] + m1.values[1] * m2.values[3] + m1.values[2] * m2.values[6];
	res.values[1] = m1.values[0] * m2.values[1] + m1.values[1] * m2.values[4] + m1.values[2] * m2.values[7];
	res.values[2] = m1.values[0] * m2.values[2] + m1.values[1] * m2.values[5] + m1.values[2] * m2.values[8];
	res.values[3] = m1.values[3] * m2.values[0] + m1.values[4] * m2.values[3] + m1.values[5] * m2.values[6];
	res.values[4] = m1.values[3] * m2.values[1] + m1.values[4] * m2.values[4] + m1.values[5] * m2.values[7];
	res.values[5] = m1.values[3] * m2.values[2] + m1.values[4] * m2.values[5] + m1.values[5] * m2.values[8];
	res.values[6] = m1.values[6] * m2.values[0] + m1.values[7] * m2.values[3] + m1.values[8] * m2.values[6];
	res.values[7] = m1.values[6] * m2.values[1] + m1.values[7] * m2.values[4] + m1.values[8] * m2.values[7];
	res.values[8] = m1.values[6] * m2.values[2] + m1.values[7] * m2.values[5] + m1.values[8] * m2.values[8];

	return (res);
}

//---- Matrix value operator ---------------------------------------------------

template <typename T>
Mat3<T>	operator*(const Mat3<T> &mat3, const T &value)
{
	Mat3<T>	res;

	for (int i = 0; i < MAT3_SIZE; i++)
		res.values[i] = mat3.values[i] * value;

	return (res);
}


template <typename T>
Mat3<T>	operator*(const T &value, const Mat3<T> &mat3)
{
	Mat3<T>	res;

	for (int i = 0; i < MAT3_SIZE; i++)
		res.values[i] = mat3.values[i] * value;

	return (res);
}


template <typename T>
Mat3<T>	operator/(const Mat3<T> &mat3, const T &value)
{
	Mat3<T>	res;

	for (int i = 0; i < MAT3_SIZE; i++)
		res.values[i] = mat3.values[i] / value;

	return (res);
}

//---- Print operator ----------------------------------------------------------

template <typename T>
std::ostream	&operator<<(std::ostream &os, const Mat3<T> &mat3)
{
	os << "|(" << mat3.values[0] << "," << mat3.values[1] << "," << mat3.values[2]
		<< ");(" << mat3.values[3] << "," << mat3.values[4] << "," << mat3.values[5]
		<< ");(" << mat3.values[6] << "," << mat3.values[7] << "," << mat3.values[8] << ")|";
	return (os);
}

//**** FUNCTIONS ***************************************************************

//**** STATIC FUNCTIONS ********************************************************

//**** USINGS ******************************************************************

// Mat3
using Mat3u = Mat3<unsigned int>;
using Mat3i = Mat3<int>;
using Mat3f = Mat3<float>;
using Mat3d = Mat3<double>;

#endif
