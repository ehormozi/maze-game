#include "../header/field.h"
#include "../header/maze_entrance.h"
#include "../header/maze_exit.h"
#include "../header/wall.h"
#include "../header/path.h"
#include "../header/small_trap.h"
#include "../header/large_trap.h"
#include "../header/hidden_trap.h"

field::field(char c) : c_{ c } {}

char field::to_char() const
{
	return c_;
}

field::~field()
{
}

void field::set(char c) const
{
	c_ = c;
}

field_effect field::effect() const
{
	return effect({ 0,0 });
}

field_ptr to_field(char c)
{
	if (c == 'I')
	{
		auto res = new maze_entrance();
		return field_ptr(res);
	}
	else if (c == 'O')
	{
		auto res = new maze_exit();
		return field_ptr(res);
	}
	else if (c == 'w')
	{
		auto res = new wall();
		return field_ptr(res);
	}
	else if (c == ' ')
	{
		auto res = new path();
		return field_ptr(res);
	}
	else if (c == 't')
	{
		auto res = new small_trap();
		return field_ptr(res);
	}
	else if (c == 'T')
	{
		auto res = new large_trap();
		return field_ptr(res);
	}
	else if (c == 'H')
	{
		auto res = new hidden_trap();
		return field_ptr(res);
	}
	else
	{
		
		throw std::runtime_error("Character is not valid.");
	}
}
