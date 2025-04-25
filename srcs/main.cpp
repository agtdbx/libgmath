#include <gmath.hpp>

int	main(void)
{
	{
		gm::Vec2i vec2(4, 2);

		std::cout << vec2 << std::endl;
		std::cout << norm(vec2) << std::endl;

		gm::Mat2i	m2(1, 2, 3, 4);

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

	return (0);
}
