#include "../header/point2d.h"

point2d::point2d(coord x_in, coord y_in) : x{ x_in }, y{ y_in } {}

bool point2d::operator==(const point2d& o) const
{
	return (x == o.x && y == o.y);
}
bool point2d::operator!=(const point2d& o) const
{
	return (x != o.x || y != o.y);
}
bool point2d::operator<(const point2d& o) const
{
	auto l = x * x + y * y;
	auto o_l = o.x * o.x + o.y + o.y;
	return l < o_l;
}
point2d& point2d::operator+=(const offset2d& o)
{
	x += o.dx;
	y += o.dy;
	return *this;
}
point2d& point2d::operator-=(const offset2d& o)
{
	x -= o.dx;
	y -= o.dy;
	return *this;
}

point2d operator+(const point2d& p, const offset2d& o)
{
	auto res = point2d{ p.x + o.dx, p.y + o.dy };
	return res;
}

point2d operator+(const offset2d& o, const point2d& p)
{
	return (p + o);
}

point2d operator-(const point2d& p, const offset2d& o)
{
	auto res = point2d{ p.x - o.dx, p.y - o.dy };
	return res;
}

point2d operator-(const offset2d& o, const point2d& p)
{
	auto tmp = p - o;
	tmp.x = -tmp.x;
	tmp.y = -tmp.y;
	return tmp;
}

offset2d operator-(const point2d& p1, const point2d& p2)
{
	auto res = offset2d{ p1.x - p2.x, p1.y - p2.y };
	return res;
}

template<>
bool std::less<point2d>::operator()(const point2d& lhs, const point2d& rhs) const
{
	return (lhs < rhs);
}
