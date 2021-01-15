#include "../header/path.h"

path::path() : field{ 'X' } {}

field_effect path::effect(const offset2d& o, bool is_sim) const
{
	if (o.dx == 0 && o.dy == 0)
	{
		return field_effect{ field_state::FREE, 0 };
	}
	return field_effect{ field_state::NONE, 0 };
}

void path::reveal()
{
	set(' ');
}
