#include "../header/game.h"

game::game(maze *m, player *p) : maze_{ m }, player_{ p } {}

bool game::is_won() const
{
	return player_->get_position() == maze_->exit_;
}

void game::print()
{
	auto hp = player_->hp_ >= 0 ? player_->hp_ : 0;
	std::cout << "HP: " << hp << std::endl;
	maze_->print(player_->get_position());
}
