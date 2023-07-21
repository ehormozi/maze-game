#include "../header/small_trap.h"

small_trap::small_trap() : field{ 'X' } {}

field_effect small_trap::effect(const offset2d& o, bool is_sim) const
{
	if (o.dx == 0 && o.dy == 0)
	{
		return field_effect{ field_state::DEADLY, 0 };
	}
	return field_effect{ field_state::NONE, 0 };
}

void small_trap::reveal()
{
	set('t');
}
