#include "header.h"

maze::maze(size_t n) : storage{ n } {}

maze::maze(std::string s) : storage{ s.length() }
{
	for (unsigned i = 0; i < s.length(); i++)
	{
		elements_[i] = to_field(s[i]);
	}
}

maze_iterator maze::observe(const point2d& p)
{
	return maze_iterator{ p.x - 2, p.x + 2, p.y - 2, p.y + 2, *this };
}

field_effect maze::evaluate_effects(const point2d& p) const
{
	auto res = field_effect{ field_state::NONE, 0 };
	auto iter = maze_iterator{ 0, max_coord() + 1, 0, max_coord() + 1, *this };
	for (point2d it = iter.begin(); !iter.is_done(); iter.operator++())
	{
		if (has_point(iter.get_c_pos()))
		{
			auto f = operator()(iter.get_c_pos());
			res += (*(f.get())).effect(iter.get_c_pos() - p);
		}
	}
	return res;
}

void maze::reveal(const point2d& point)
{
	(*(operator()(point).get())).reveal();
}