#ifndef VEC_MAT_HPP
# define VEC_MAT_HPP

# include <gmath/Vec2.hpp>
# include <gmath/Vec3.hpp>
# include <gmath/Vec4.hpp>
# include <gmath/Mat2.hpp>
# include <gmath/Mat3.hpp>
# include <gmath/Mat4.hpp>

//---- Matrix vector 2 operator ------------------------------------------------

template <typename T>
Vec2<T>	operator*(const Mat2<T> &mat2, const Vec2<T> &vec2)
{
	Vec2<T>	res;

	res.x = mat2.values[0] * vec2.x + mat2.values[1] * vec2.y;
	res.y = mat2.values[2] * vec2.x + mat2.values[3] * vec2.y;

	return (res);
}


template <typename T>
Vec2<T>	operator*(const Vec2<T> &vec2, const Mat2<T> &mat2)
{
	Vec2<T>	res;

	res.x = mat2.values[0] * vec2.x + mat2.values[1] * vec2.y;
	res.y = mat2.values[2] * vec2.x + mat2.values[3] * vec2.y;

	return (res);
}

//---- Matrix vector 3 operator ------------------------------------------------

template <typename T>
Vec3<T>	operator*(const Mat3<T> &mat3, const Vec3<T> &vec3)
{
	Vec3<T>	res;

	res.x = mat3.values[0] * vec3.x + mat3.values[1] * vec3.y + mat3.values[2] * vec3.z;
	res.y = mat3.values[3] * vec3.x + mat3.values[4] * vec3.y + mat3.values[5] * vec3.z;
	res.z = mat3.values[6] * vec3.x + mat3.values[7] * vec3.y + mat3.values[8] * vec3.z;

	return (res);
}


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

#endif
