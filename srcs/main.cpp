#include <gmath.hpp>

int	main(void)
{
	{
		gm::Vec2i vec2(4, 2);

		std::cout << vec2 << std::endl;
		std::cout << norm(vec2) << std::endl;

		gm::lerp(1, 1, 1.0f);

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
		float	radian = gm::radians(180.0f);

		std::cout << vec2 << std::endl;
		vec2 = vec2 * gm::Mat2f::rotation(radian);
		std::cout << vec2 << std::endl;
	}

	{
		gm::Mat3f	mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);

		std::cout << mat3 << std::endl;
		std::cout << gm::Mat3f::identity() << std::endl;
		std::cout << mat3 * gm::Mat3f::identity() << std::endl;

		float	radian = gm::radians(90.0f);
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

	{
		gm::Mat2i	mat2(0, 1, 2, 3);
		gm::Mat3i	mat3(0, 1, 2, 3, 4, 5, 6, 7, 8);
		gm::Mat4i	mat4(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);

		std::cout << "mat2 : " << std::endl;
		gm::print(mat2);
		std::cout << "mat2 transposed : " << std::endl;
		gm::print(gm::transpose(mat2));

		std::cout << "mat3 : " << std::endl;
		gm::print(mat3);
		std::cout << "mat3 transposed : " << std::endl;
		gm::print(gm::transpose(mat3));

		std::cout << "mat4 : " << std::endl;
		gm::print(mat4);
		std::cout << "mat4 transposed : " << std::endl;
		gm::print(gm::transpose(mat4));
	}

	{
		gm::initRandom();

		std::cout << "Random vec2" << std::endl;
		for (int i = 0; i < 5; i++)
		{
			gm::Vec2f	vec2 = gm::Vec2f::randomNormal();

			std::cout << "vec2 : " << vec2 << ", norm : " << gm::norm(vec2) << std::endl;
		}

		std::cout << "Random vec3" << std::endl;
		for (int i = 0; i < 5; i++)
		{
			gm::Vec3f	vec3 = gm::Vec3f::randomNormal();

			std::cout << "vec3 : " << vec3 << ", norm : " << gm::norm(vec3) << std::endl;
		}
	}

	return (0);
}
