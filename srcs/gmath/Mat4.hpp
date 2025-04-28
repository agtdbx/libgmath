#ifndef MAT4_HPP
# define MAT4_HPP

# define MAT4_SIZE 16

# include <gmath/Vec3.hpp>
# include <gmath/Mat2.hpp>
# include <gmath/Mat3.hpp>
# include <gmath/utils.hpp>

#include <cmath>
#include <iostream>
#include <stdexcept>

//**** STATIC FUNCTIONS DEFINE *************************************************

//**** CLASS DEFINE ************************************************************
template <typename T>
class Mat4
{
public:
	T	values[MAT4_SIZE];

	//**** INITIALISION ********************************************************
	//---- Constructors --------------------------------------------------------

	Mat4(void)
	{
		for (int i = 0; i < MAT4_SIZE; i++)
			this->values[i] = T();
	}


	Mat4(const Mat4 &mat4)
	{
		for (int i = 0; i < MAT4_SIZE; i++)
			this->values[i] = mat4.values[i];
	}


	Mat4(const T values[MAT4_SIZE])
	{
		for (int i = 0; i < MAT4_SIZE; i++)
			this->values[i] = values[i];
	}


	Mat4(T x1, T x2, T x3, T x4,
			T y1, T y2, T y3, T y4,
			T z1, T z2, T z3, T z4,
			T w1, T w2, T w3, T w4)
	{
		this->values[ 0] = x1;
		this->values[ 1] = x2;
		this->values[ 2] = x3;
		this->values[ 3] = x4;

		this->values[ 4] = y1;
		this->values[ 5] = y2;
		this->values[ 6] = y3;
		this->values[ 7] = y4;

		this->values[ 8] = z1;
		this->values[ 9] = z2;
		this->values[10] = z3;
		this->values[11] = z4;

		this->values[12] = w1;
		this->values[13] = w2;
		this->values[14] = w3;
		this->values[15] = w4;
	}


	Mat4(const Mat2<T> mat2)
	{
		this->values[ 0] = mat2.values[0];
		this->values[ 1] = mat2.values[1];
		this->values[ 2] = T();
		this->values[ 3] = T();

		this->values[ 4] = mat2.values[2];
		this->values[ 5] = mat2.values[3];
		this->values[ 6] = T();
		this->values[ 7] = T();

		this->values[ 8] = T();
		this->values[ 9] = T();
		this->values[10] = T();
		this->values[11] = T();

		this->values[12] = T();
		this->values[13] = T();
		this->values[14] = T();
		this->values[15] = T();
	}


	Mat4(const Mat3<T> mat3)
	{
		this->values[ 0] = mat3.values[0];
		this->values[ 1] = mat3.values[1];
		this->values[ 2] = mat3.values[2];
		this->values[ 3] = T();

		this->values[ 4] = mat3.values[3];
		this->values[ 5] = mat3.values[4];
		this->values[ 6] = mat3.values[5];
		this->values[ 7] = T();

		this->values[ 8] = mat3.values[6];
		this->values[ 9] = mat3.values[7];
		this->values[10] = mat3.values[8];
		this->values[11] = T();

		this->values[12] = T();
		this->values[13] = T();
		this->values[14] = T();
		this->values[15] = T();
	}

	//---- Destructor ----------------------------------------------------------

	~Mat4()
	{
	}

	//**** ACCESSORS ***********************************************************
	//---- Getters -------------------------------------------------------------

	//---- Setters -------------------------------------------------------------

	//---- Modify Operators ----------------------------------------------------

	Mat4	&operator=(const Mat4 &mat4)
	{
		if (this == &mat4)
			return (*this);

		for (int i = 0; i < MAT4_SIZE; i++)
			this->values[i] = mat4.values[i];

		return (*this);
	}


	Mat4	&operator+=(const Mat4 &mat4)
	{
		for (int i = 0; i < MAT4_SIZE; i++)
			this->values[i] += mat4.values[i];

		return (*this);
	}


	Mat4	&operator-=(const Mat4 &mat4)
	{
		for (int i = 0; i < MAT4_SIZE; i++)
			this->values[i] -= mat4.values[i];

		return (*this);
	}


	Mat4	&operator*=(const T &value)
	{
		for (int i = 0; i < MAT4_SIZE; i++)
			this->values[i] *= value;

		return (*this);
	}


	Mat4	&operator/=(const T &value)
	{
		for (int i = 0; i < MAT4_SIZE; i++)
			this->values[i] /= value;

		return (*this);
	}

	//---- Compare Operators ---------------------------------------------------

	bool	operator==(const Mat4 &mat4) const
	{
		for (int i = 0; i < MAT4_SIZE; i++)
			if (this->values[i] != mat4.values[i])
				return (false);

		return (true);
	}


	bool	operator!=(const Mat4 &mat4) const
	{
		for (int i = 0; i < MAT4_SIZE; i++)
			if (this->values[i] != mat4.values[i])
				return (true);

		return (false);
	}

	//---- Accessor Operators --------------------------------------------------

	T	&operator[](unsigned int n)
	{
		if (n >= MAT4_SIZE)
			throw std::runtime_error("Index out of mat4 bounds");

		return (this->values[n]);
	}

	//**** PUBLIC METHODS ******************************************************

	Mat2<T>	asMat2(void) const
	{
		Mat2<T>	res;

		res.values[0] = this->values[0];
		res.values[1] = this->values[1];
		res.values[2] = this->values[4];
		res.values[3] = this->values[5];

		return (res);
	}


	Mat3<T>	asMat3(void) const
	{
		Mat3<T>	res;

		res.values[0] = this->values[0];
		res.values[1] = this->values[1];
		res.values[2] = this->values[2];
		res.values[3] = this->values[4];
		res.values[4] = this->values[5];
		res.values[5] = this->values[6];
		res.values[6] = this->values[8];
		res.values[7] = this->values[9];
		res.values[8] = this->values[10];

		return (res);
	}

	//**** STATIC METHODS ******************************************************

	static Mat4<T>	identity(void)
	{
		Mat4<T>	res;

		res.values[0] = T(1);
		res.values[5] = T(1);
		res.values[10] = T(1);
		res.values[15] = T(1);

		return (res);
	}


	static Mat4<T>	rotation3D(const Vec3<T> &axis, T radian)
	{
		Mat4<T>	res;
		T		tmpCos = cos(radian);
		T		tmpSin = sin(radian);
		T		invTmpCos = T(1) - tmpCos;
		T		tmpSinAx = tmpSin * axis.x;
		T		tmpSinAy = tmpSin * axis.y;
		T		tmpSinAz = tmpSin * axis.z;

		// Line 1
		res.values[ 0] = (axis.x * axis.x) * invTmpCos + tmpCos;
		res.values[ 1] = (axis.x * axis.y) * invTmpCos - tmpSinAz;
		res.values[ 2] = (axis.x * axis.z) * invTmpCos + tmpSinAy;
		res.values[ 3] = T();
		// Line 2
		res.values[ 4] = (axis.y * axis.x) * invTmpCos + tmpSinAz;
		res.values[ 5] = (axis.y * axis.y) * invTmpCos + tmpCos;
		res.values[ 6] = (axis.y * axis.z) * invTmpCos - tmpSinAx;
		res.values[ 7] = T();
		// Line 3
		res.values[ 8] = (axis.z * axis.x) * invTmpCos - tmpSinAy;
		res.values[ 9] = (axis.z * axis.y) * invTmpCos + tmpSinAx;
		res.values[10] = (axis.z * axis.z) * invTmpCos + tmpCos;
		res.values[11] = T();
		// Line 4
		res.values[12] = T();
		res.values[13] = T();
		res.values[14] = T();
		res.values[15] = T(1);

		return (res);
	}


	static Mat4<T>	perceptive(T fovY, T ratio, T near, T far)
	{
		Mat4<T>	res;

		// Remap z in range [0, 1]
		res.values[10] = - (far / (far - near));
		res.values[11] = - ((far * near) / (far - near));

		// Compute fov
		T	tanFov = tan(toRadian(fovY / T(2.0)));

		// Scaling factor x * ratio because fov is for y
		res.values[0] = T(1.0) / (tanFov * ratio);
		// Scaling factor y
		res.values[5] = T(1.0) / tanFov;

		return (res);
	}

private:

};

//**** EXTERNS OPERATORS *******************************************************
//---- Matrix matrix operator --------------------------------------------------

template <typename T>
Mat4<T>	operator+(const Mat4<T> &m1, const Mat4<T> &m2)
{
	Mat4<T>	res;

	for (int i = 0; i < MAT4_SIZE; i++)
		res.values[i] = m1.values[i] + m2.values[i];

	return (res);
}


template <typename T>
Mat4<T>	operator-(const Mat4<T> &m1, const Mat4<T> &m2)
{
	Mat4<T>	res;

	for (int i = 0; i < MAT4_SIZE; i++)
		res.values[i] = m1.values[i] - m2.values[i];

	return (res);
}


template <typename T>
Mat4<T>	operator*(const Mat4<T> &m1, const Mat4<T> &m2)
{
	Mat4<T>	res;

	res.values[0] = m1.values[0] * m2.values[0] + m1.values[1] * m2.values[4] + m1.values[2] * m2.values[8] + m1.values[3] * m2.values[12];
	res.values[1] = m1.values[0] * m2.values[1] + m1.values[1] * m2.values[5] + m1.values[2] * m2.values[9] + m1.values[3] * m2.values[13];
	res.values[2] = m1.values[0] * m2.values[2] + m1.values[1] * m2.values[6] + m1.values[2] * m2.values[10] + m1.values[3] * m2.values[14];
	res.values[3] = m1.values[0] * m2.values[3] + m1.values[1] * m2.values[7] + m1.values[2] * m2.values[11] + m1.values[3] * m2.values[15];
	res.values[4] = m1.values[4] * m2.values[0] + m1.values[5] * m2.values[4] + m1.values[6] * m2.values[8] + m1.values[7] * m2.values[12];
	res.values[5] = m1.values[4] * m2.values[1] + m1.values[5] * m2.values[5] + m1.values[6] * m2.values[9] + m1.values[7] * m2.values[13];
	res.values[6] = m1.values[4] * m2.values[2] + m1.values[5] * m2.values[6] + m1.values[6] * m2.values[10] + m1.values[7] * m2.values[14];
	res.values[7] = m1.values[4] * m2.values[3] + m1.values[5] * m2.values[7] + m1.values[6] * m2.values[11] + m1.values[7] * m2.values[15];
	res.values[8] = m1.values[8] * m2.values[0] + m1.values[9] * m2.values[4] + m1.values[10] * m2.values[8] + m1.values[11] * m2.values[12];
	res.values[9] = m1.values[8] * m2.values[1] + m1.values[9] * m2.values[5] + m1.values[10] * m2.values[9] + m1.values[11] * m2.values[13];
	res.values[10] = m1.values[8] * m2.values[2] + m1.values[9] * m2.values[6] + m1.values[10] * m2.values[10] + m1.values[11] * m2.values[14];
	res.values[11] = m1.values[8] * m2.values[3] + m1.values[9] * m2.values[7] + m1.values[10] * m2.values[11] + m1.values[11] * m2.values[15];
	res.values[12] = m1.values[12] * m2.values[0] + m1.values[13] * m2.values[4] + m1.values[14] * m2.values[8] + m1.values[15] * m2.values[12];
	res.values[13] = m1.values[12] * m2.values[1] + m1.values[13] * m2.values[5] + m1.values[14] * m2.values[9] + m1.values[15] * m2.values[13];
	res.values[14] = m1.values[12] * m2.values[2] + m1.values[13] * m2.values[6] + m1.values[14] * m2.values[10] + m1.values[15] * m2.values[14];
	res.values[15] = m1.values[12] * m2.values[3] + m1.values[13] * m2.values[7] + m1.values[14] * m2.values[11] + m1.values[15] * m2.values[15];

	return (res);
}

//---- Matrix value operator ---------------------------------------------------

template <typename T>
Mat4<T>	operator*(const Mat4<T> &mat4, const T &value)
{
	Mat4<T>	res;

	for (int i = 0; i < MAT4_SIZE; i++)
		res.values[i] = mat4.values[i] * value;

	return (res);
}


template <typename T>
Mat4<T>	operator*(const T &value, const Mat4<T> &mat4)
{
	Mat4<T>	res;

	for (int i = 0; i < MAT4_SIZE; i++)
		res.values[i] = mat4.values[i] * value;

	return (res);
}


template <typename T>
Mat4<T>	operator/(const Mat4<T> &mat4, const T &value)
{
	Mat4<T>	res;

	for (int i = 0; i < MAT4_SIZE; i++)
		res.values[i] = mat4.values[i] / value;

	return (res);
}

//---- Print operator ----------------------------------------------------------

template <typename T>
std::ostream	&operator<<(std::ostream &os, const Mat4<T> &mat4)
{
	os << "|(" << mat4.values[0] << "," << mat4.values[1] << "," << mat4.values[2] << "," << mat4.values[3]
		<< ");(" << mat4.values[4] << "," << mat4.values[5] << "," << mat4.values[6] << "," << mat4.values[7]
		<< ");(" << mat4.values[8] << "," << mat4.values[9] << "," << mat4.values[10] << "," << mat4.values[11]
		<< ");(" << mat4.values[12] << "," << mat4.values[13] << "," << mat4.values[14] << "," << mat4.values[15] << ")|";
	return (os);
}

//**** FUNCTIONS ***************************************************************

//**** STATIC FUNCTIONS ********************************************************

//**** USINGS ******************************************************************

// Mat4
using Mat4u = Mat4<unsigned int>;
using Mat4i = Mat4<int>;
using Mat4f = Mat4<float>;
using Mat4d = Mat4<double>;

#endif
