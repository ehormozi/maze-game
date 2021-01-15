#include "../header/maze_iterator.h"

maze_iterator::maze_iterator(coord x_beg, coord x_end, coord y_beg, coord y_end, maze m) :
	box_iterator{ x_beg, x_end, y_beg, y_end },
	maze_{ m }
{
	if (x_beg_ > maze_.max_coord() || y_beg_ > maze_.max_coord())
	{
		throw "No intersection between box and maze";
	}
	if (x_end_ < 0 || y_end_ < 0)
	{
		throw "No intersection between box and maze";
	}
	if (x_beg_ < 0)
	{
		x_beg_ = 0;
	}
	if (y_beg_ < 0)
	{
		y_beg_ = 0;
	}
	if (x_end_ > maze_.max_coord())
	{
		x_end_ = maze_.max_coord() + 1;
	}
	if (y_end_ > maze_.max_coord())
	{
		y_end_ = maze_.max_coord() + 1;
	}
}

maze_iterator::maze_iterator(const point2d& upper_left, const point2d& lower_right, maze m)	:
	maze_iterator{ upper_left.x, lower_right.x, upper_left.y, lower_right.y, m } {}

maze_iterator& maze_iterator::operator++()
{
	assert(!is_done());
	if (c_pos_.y == y_end_ - 1)
	{
		c_pos_.x = c_pos_.x + 1;
		c_pos_.y = y_beg_;
	}
	else
	{
		c_pos_.y = c_pos_.y + 1;
	}
	return *this;
}
