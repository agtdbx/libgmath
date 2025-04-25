#include <gmath.hpp>

int	main(void)
{
	gm::Mat2i	m2(1, 2, 3, 4);

	std::cout << m2 << std::endl;
	std::cout << m2 + gm::Mat2i(1, 0, 0, 1) << std::endl;
	std::cout << m2 * 2 << std::endl;

	return (0);
}
