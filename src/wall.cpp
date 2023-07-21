#include "../header/wall.h"

wall::wall() : field{ 'X' } {}

field_effect wall::effect(const offset2d& o, bool is_sim) const
{
	if (o.dx == 0 && o.dy == 0)
	{
		return field_effect{ field_state::BLOCKED, 0 };
	}
	return field_effect{ field_state::NONE, 0 };
}

void wall::reveal()
{
	set('w');
}
