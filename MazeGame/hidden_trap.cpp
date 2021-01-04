#include "header.h"

hidden_trap::hidden_trap() : field{ 'X' } {}

field_effect hidden_trap::effect(const offset2d& o, bool is_sim) const
{
	if (o.dx >= -3 && o.dx <= 3 && o.dy >= -3 && o.dy <= 3)
	{
		return field_effect{ field_state::DAMAGING, 10 };
	}
	return field_effect{ field_state::NONE, 0 };
}
