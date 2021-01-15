#include "../header/large_trap.h"

large_trap::large_trap() : field{ 'X' } {}

field_effect large_trap::effect(const offset2d& o, bool is_sim) const
{
	if (o.dx >= -1 && o.dx <= 1 && o.dy >= -1 && o.dy <= 1)
	{
		return field_effect{ field_state::DAMAGING, 10 };
	}
	return field_effect{ field_state::NONE, 0 };
}

void large_trap::reveal()
{
	set('T');
}
