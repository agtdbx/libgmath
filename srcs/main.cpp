// #include <gmath.hpp>
#include <vec2/Vec2i.hpp>

int	main(void)
{
	Vec2i	vec2(4, 2);

	std::cout << vec2 << std::endl;

	vec2.x += 2;
	std::cout << vec2 << std::endl;

	return (0);
}
