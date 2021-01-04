#include "header.h"

neighbours_iterator::neighbours_iterator(point2d p) :
	p_{ p },
	box_iterator { p_.x - 1, p_.x + 1, p_.y - 1, p_.y + 1 }
{
	c_pos_.y = p_.y;
}

void neighbours_iterator::reset()
{
	c_pos_.x = p_.x - 1;
	c_pos_.y = p_.y;
}

neighbours_iterator& neighbours_iterator::operator++()
{
	box_iterator::operator++();
	if ((c_pos_.x != p_.x && c_pos_.y != p_.y) || (c_pos_.x == p_.x && c_pos_.y == p_.y))
	{
		box_iterator::operator++();
	}
	return *this;
}

bool neighbours_iterator::is_done() const
{
	return c_pos_.x == p_.x + 1 && c_pos_.y == p_.y;
}