#include <gmath.hpp>

int	main(void)
{
	gm::Vec2d	vec2(4, 2);

	std::cout << vec2 << std::endl;

	vec2.x += 2;
	std::cout << vec2 << std::endl;
	std::cout << gm::normalize(vec2) << std::endl;
	std::cout << gm::norm(vec2) << std::endl;

	vec2[1] += 2;

	std::cout << vec2 << std::endl;

	gm::Vec3d	vec3(vec2, 1);
	std::cout << vec3 << std::endl;
	std::cout << vec3.xy() << std::endl;

	return (0);
}
