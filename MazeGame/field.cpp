#include "header.h"

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

void field::reveal()
{
}
