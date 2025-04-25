#include <gmath.hpp>

int	main(void)
{
	gm::Vec2d	vec2(4, 2);

	std::cout << vec2 << std::endl;

	vec2.r += 2;
	std::cout << vec2 << std::endl;
	std::cout << gm::normalize(vec2) << std::endl;
	std::cout << gm::norm(vec2) << std::endl;

	vec2[1] += 2;

	std::cout << vec2 << std::endl;

	return (0);
}
