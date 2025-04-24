#ifndef VEC2I_HPP
# define VEC2I_HPP

#include <iostream>

class Vec2i
{
public:
	int	x;
	int	y;

	Vec2i(void);
	Vec2i(const Vec2i &obj);
	Vec2i(int x, int y);
	~Vec2i();

	Vec2i	&operator=(const Vec2i &obj);

private:

};

std::ostream	&operator<<(std::ostream &os, const Vec2i &vec2);

#endif
