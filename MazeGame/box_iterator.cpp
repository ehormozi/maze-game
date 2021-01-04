#include "header.h"

box_iterator::box_iterator(coord x_beg, coord x_end, coord y_beg, coord y_end) :
	x_beg_{ x_beg },
	x_end_{ x_end },
	y_beg_{ y_beg },
	y_end_{ y_end },
	c_pos_{ point2d{x_beg_, y_beg_} } {}

box_iterator::box_iterator(const point2d& lower_left, const point2d& upper_right) :
	x_beg_{ lower_left.x },
	x_end_{ upper_right.x },
	y_beg_{ lower_left.x },
	y_end_{ upper_right.y },
	c_pos_{ point2d{lower_left.x, lower_left.y} } {}

void box_iterator::reset()
{
	c_pos_.x = x_beg_;
	c_pos_.y = y_beg_;
}

box_iterator& box_iterator::operator++()
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

bool box_iterator::operator==(const box_iterator& o) const
{
	return x_beg_ == o.x_beg_ && x_end_ == o.x_end_ && y_beg_ == o.y_beg_ && y_end_ == o.y_end_ && c_pos_ == o.c_pos_;
}

bool box_iterator::operator!=(const box_iterator& o) const
{
	return !(*this == o);
}

point2d box_iterator::operator*()
{
	return c_pos_;
}

point2d box_iterator::get_c_pos() const
{
	return c_pos_;
}

bool box_iterator::is_done() const
{
	return c_pos_.x == x_end_ - 1 && c_pos_.y == y_end_ - 1;
}

point2d box_iterator::begin()
{
	reset();
	return get_c_pos();
}
