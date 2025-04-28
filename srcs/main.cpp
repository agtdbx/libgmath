#include <gmath.hpp>

int	main(void)
{
	{
		gm::Vec2i vec2(4, 2);

		std::cout << vec2 << std::endl;
		std::cout << norm(vec2) << std::endl;

		gm::Mat2i	m2(1, 2, 3, 4);

		std::cout << m2 << std::endl;
		m2[gm::Vec2u(0, 1)] = 5;
		std::cout << m2 << std::endl;
		std::cout << m2 + gm::Mat2i::identity() << std::endl;
		std::cout << m2 * 2 << std::endl;
		std::cout << (vec2 * gm::Mat2i::identity()) << std::endl;
	}

	{
		gm::Vec2f vec2(1, 0);
		float	radian = gm::toRadian(180.0f);

		std::cout << vec2 << std::endl;
		vec2 = vec2 * gm::Mat2f::rotation(radian);
		std::cout << vec2 << std::endl;
	}

	{
		gm::Mat3f	mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);

		std::cout << mat3 << std::endl;
		std::cout << gm::Mat3f::identity() << std::endl;
		std::cout << mat3 * gm::Mat3f::identity() << std::endl;

		float	radian = gm::toRadian(90.0f);
		gm::Vec3f	pos(0, 0, 1);
		gm::Vec3f	axis(0, 1, 0);
		gm::Mat3f	rot = gm::Mat3f::rotation(axis, radian);

		std::cout << pos << std::endl;
		std::cout << (pos * rot) << std::endl;
	}
	{
		gm::Mat4f	mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

		std::cout << mat4 << std::endl;
		std::cout << gm::Mat4f::identity() << std::endl;
		std::cout << mat4 * gm::Mat4f::identity() << std::endl;
	}

	return (0);
}
