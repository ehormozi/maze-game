#include "../header/hidden_trap.h"

hidden_trap::hidden_trap() : field{ 'X' } {}

field_effect hidden_trap::effect(const offset2d& o, bool is_sim) const
{
	if (o.dx >= -1 && o.dx <= 1 && o.dy >= -1 && o.dy <= 1)
	{
		std::cout << "hidden trap discovered." << std::endl;
		set('T');
		return field_effect{ field_state::DAMAGING, 10 };
	}
	return field_effect{ field_state::NONE, 0 };
}

void hidden_trap::reveal()
{
	set(' ');
}
