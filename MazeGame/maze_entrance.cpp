#include "header.h"

maze_entrance::maze_entrance() : field{ 'X' } {}

field_effect maze_entrance::effect(const offset2d& o, bool is_sim) const
{
	if (o.dx == 0 && o.dy == 0)
	{
		return field_effect{ field_state::ENTRANCE, 0 };
	}
	return field_effect{ field_state::NONE, 0 };
}
