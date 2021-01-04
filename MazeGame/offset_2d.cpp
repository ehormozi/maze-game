#include "header.h"

offset2d::offset2d(coord dx_in, coord dy_in) : dx{ dx_in }, dy{ dy_in } {}

bool offset2d::operator==(const offset2d& o) const
{
	return (dx == o.dx && dy == o.dy);
}

bool offset2d::operator!=(const offset2d& o) const
{
	return (dx != o.dx || dy != o.dy);
}

bool offset2d::operator<(const offset2d& o) const
{
	auto l = dx * dx + dy * dy;
	auto o_l = o.dx * o.dx + o.dy + o.dy;
	return l < o_l;
}

offset2d& offset2d::operator+=(const offset2d& o)
{
	dx += o.dx;
	dy += o.dy;
	return *this;
}

offset2d& offset2d::operator-=(const offset2d& o)
{
	dx -= o.dx;
	dy -= o.dy;
	return *this;
}

offset2d offset2d::operator+(const offset2d& other) const
{
	auto res = offset2d{ dx + other.dx, dy + other.dy };
	return res;
}

offset2d offset2d::operator-(const offset2d& other) const
{
	auto res = offset2d{ dx - other.dx, dy - other.dy };
	return res;
}

bool std::less<offset2d>::operator()(const offset2d& lhs, const offset2d& rhs) const
{
	return (lhs < rhs);
}