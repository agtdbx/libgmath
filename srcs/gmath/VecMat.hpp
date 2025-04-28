#ifndef VEC_MAT_HPP
# define VEC_MAT_HPP

# include <gmath/Vec2.hpp>
# include <gmath/Vec3.hpp>
# include <gmath/Vec4.hpp>
# include <gmath/Mat2.hpp>
# include <gmath/Mat3.hpp>
# include <gmath/Mat4.hpp>

//**** MATRIX VECTOR MULTIPLICATION ********************************************
//---- Matrix vector 2 operator ------------------------------------------------

/**
 * @brief Mat2 Vec2 multiplication.
 *
 * @param mat2 The Mat2.
 * @param vec2 The Vec2.
 *
 * @result Result of mat2 * vec2.
 */
template <typename T>
Vec2<T>	operator*(const Mat2<T> &mat2, const Vec2<T> &vec2)
{
	Vec2<T>	res;

	res.x = mat2.values[0] * vec2.x + mat2.values[1] * vec2.y;
	res.y = mat2.values[2] * vec2.x + mat2.values[3] * vec2.y;

	return (res);
}

/**
 * @brief Mat2 Vec2 multiplication.
 *
 * @param vec2 The Vec2.
 * @param mat2 The Mat2.
 *
 * @result Result of mat2 * vec2.
 */
template <typename T>
Vec2<T>	operator*(const Vec2<T> &vec2, const Mat2<T> &mat2)
{
	Vec2<T>	res;

	res.x = mat2.values[0] * vec2.x + mat2.values[1] * vec2.y;
	res.y = mat2.values[2] * vec2.x + mat2.values[3] * vec2.y;

	return (res);
}

//---- Matrix vector 3 operator ------------------------------------------------

/**
 * @brief Mat3 Vec3 multiplication.
 *
 * @param mat3 The Mat3.
 * @param vec3 The Vec3.
 *
 * @result Result of mat3 * vec3.
 */
template <typename T>
Vec3<T>	operator*(const Mat3<T> &mat3, const Vec3<T> &vec3)
{
	Vec3<T>	res;

	res.x = mat3.values[0] * vec3.x + mat3.values[1] * vec3.y + mat3.values[2] * vec3.z;
	res.y = mat3.values[3] * vec3.x + mat3.values[4] * vec3.y + mat3.values[5] * vec3.z;
	res.z = mat3.values[6] * vec3.x + mat3.values[7] * vec3.y + mat3.values[8] * vec3.z;

	return (res);
}

/**
 * @brief Mat3 Vec3 multiplication.
 *
 * @param vec3 The Vec3.
 * @param mat3 The Mat3.
 *
 * @result Result of mat3 * vec3.
 */
template <typename T>
Vec3<T>	operator*(const Vec3<T> &vec3, const Mat3<T> &mat3)
{
	Vec3<T>	res;

	res.x = mat3.values[0] * vec3.x + mat3.values[1] * vec3.y + mat3.values[2] * vec3.z;
	res.y = mat3.values[3] * vec3.x + mat3.values[4] * vec3.y + mat3.values[5] * vec3.z;
	res.z = mat3.values[6] * vec3.x + mat3.values[7] * vec3.y + mat3.values[8] * vec3.z;

	return (res);
}

//---- Matrix vector 4 operator ------------------------------------------------

/**
 * @brief Mat4 Vec4 multiplication.
 *
 * @param mat4 The Mat4.
 * @param vec4 The Vec4.
 *
 * @result Result of mat4 * vec4.
 */
template <typename T>
Vec4<T>	operator*(const Mat4<T> &mat4, const Vec4<T> &vec4)
{
	Vec4<T>	res;

	res.x = mat4.values[ 0] * vec4.x + mat4.values[ 1] * vec4.y + mat4.values[ 2] * vec4.z + mat4.values[ 3] * vec4.z;
	res.y = mat4.values[ 4] * vec4.x + mat4.values[ 5] * vec4.y + mat4.values[ 6] * vec4.z + mat4.values[ 7] * vec4.z;
	res.z = mat4.values[ 8] * vec4.x + mat4.values[ 9] * vec4.y + mat4.values[10] * vec4.z + mat4.values[11] * vec4.z;
	res.w = mat4.values[12] * vec4.x + mat4.values[13] * vec4.y + mat4.values[14] * vec4.z + mat4.values[15] * vec4.z;

	return (res);
}

/**
 * @brief Mat4 Vec4 multiplication.
 *
 * @param vec4 The Vec4.
 * @param mat4 The Mat4.
 *
 * @result Result of mat4 * vec4.
 */
template <typename T>
Vec4<T>	operator*(const Vec4<T> &vec4, const Mat4<T> &mat4)
{
	Vec4<T>	res;

	res.x = mat4.values[ 0] * vec4.x + mat4.values[ 1] * vec4.y + mat4.values[ 2] * vec4.z + mat4.values[ 3] * vec4.z;
	res.y = mat4.values[ 4] * vec4.x + mat4.values[ 5] * vec4.y + mat4.values[ 6] * vec4.z + mat4.values[ 7] * vec4.z;
	res.z = mat4.values[ 8] * vec4.x + mat4.values[ 9] * vec4.y + mat4.values[10] * vec4.z + mat4.values[11] * vec4.z;
	res.w = mat4.values[12] * vec4.x + mat4.values[13] * vec4.y + mat4.values[14] * vec4.z + mat4.values[15] * vec4.z;

	return (res);
}

//**** VECTOR ROTATE ***********************************************************
//---- Vec2 --------------------------------------------------------------------

/**
 * @brief Rotate a Vec2.
 *
 * @param vec2 The Vec2 to rotate.
 * @param radians The angle in radians.
 *
 * @return Vec2 rotate by angle in radians.
 */
template <typename T>
Vec2<T>	rotate(const Vec2<T> &vec2, T radians)
{
	const Mat2<T>	matRot = Mat2<T>::rotation(radians);

	return (matRot * vec2);
}

/**
 * @brief Rotate a Vec2 arround a point.
 *
 * @param vec2 The Vec2 to rotate.
 * @param point The point to rotate arround.
 * @param radians The angle in radians.
 *
 * @return Vec2 rotate by angle in radians arround point.
 */
template <typename T>
Vec2<T>	rotateArround(const Vec2<T> &vec2, const Vec2<T> &point, T radians)
{
	const Mat2<T>	matRot = Mat2<T>::rotation(radians);

	return ((matRot * (vec2 - point)) + point);
}

//---- Vec3 --------------------------------------------------------------------

/**
 * @brief Rotate a Vec3.
 *
 * @param vec3 The Vec3 to rotate.
 * @param axis Vec3 to tell on wich axis the rotation will be done. It must be normalized.
 * @param radians The angle in radians.
 *
 * @return Vec3 rotate by axis and angle in radians.
 */
template <typename T>
Vec3<T>	rotate(const Vec3<T> &vec3, const Vec3<T> &axis, T radians)
{
	const Mat3<T>	matRot = Mat3<T>::rotation(axis, radians);

	return (matRot * vec3);
}

/**
 * @brief Rotate a Vec3 arround a point.
 *
 * @param vec3 The Vec3 to rotate.
 * @param point The point to rotate arround.
 * @param axis Vec3 to tell on wich axis the rotation will be done. It must be normalized.
 * @param radians The angle in radians.
 *
 * @return Vec3 rotate by axis and angle in radians arround point.
 */
template <typename T>
Vec3<T>	rotateArround(const Vec3<T> &vec3, const Vec3<T> &point, const Vec3<T> &axis, T radians)
{
	const Mat3<T>	matRot = Mat3<T>::rotation(axis, radians);

	return ((matRot * (vec3 - point)) + point);
}

//---- Vec4 --------------------------------------------------------------------

/**
 * @brief Rotate a Vec4 in 3D.
 *
 * @param vec4 The Vec4 to rotate.
 * @param axis Vec3 to tell on wich axis the rotation will be done. It must be normalized.
 * @param radians The angle in radians.
 *
 * @return Vec4 rotate by axis and angle in radians in 3D.
 */
template <typename T>
Vec4<T>	rotate(const Vec4<T> &vec4, const Vec3<T> &axis, T radians)
{
	const Mat4<T>	matRot = Mat4<T>::rotation(axis, radians);

	return (matRot * vec4);
}

/**
 * @brief Rotate a Vec4 arround a point in 3D.
 *
 * @param vec4 The Vec4 to rotate.
 * @param point The point to rotate arround.
 * @param axis Vec3 to tell on wich axis the rotation will be done. It must be normalized.
 * @param radians The angle in radians.
 *
 * @return Vec4 rotate by axis and angle in radians arround point in 3D.
 */
template <typename T>
Vec4<T>	rotateArround(const Vec4<T> &vec4, const Vec4<T> &point, const Vec3<T> &axis, T radians)
{
	const Mat4<T>	matRot = Mat4<T>::rotation(axis, radians);

	return ((matRot * (vec4 - point)) + point);
}

#endif
