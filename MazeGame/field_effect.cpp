#include "header.h"

field_effect& field_effect::operator+=(const field_effect& other)
{
	damage += other.damage;
	state = state > other.state ? state : other.state;
	return *this;
}

bool field_effect::operator!=(const field_effect& rhs)
{
	return state == rhs.state && damage == rhs.damage;
}