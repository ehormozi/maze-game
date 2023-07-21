#include "../header/maze_exit.h"

maze_exit::maze_exit() : field{ 'O' } {}

field_effect maze_exit::effect(const offset2d& o, bool is_sim) const
{
	if (o.dx == 0 && o.dy == 0)
	{
		return field_effect{ field_state::EXIT, 0 };
	}
	return field_effect{ field_state::NONE, 0 };
}

void maze_exit::reveal()
{
	set('O');
}
