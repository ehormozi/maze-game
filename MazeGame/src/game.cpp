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
	std::cout << std::endl;
	maze_->print(player_->get_position());
}

void game::print_guide() const
{
	std::cout << "I: entrance" << std::endl;
	std::cout << "O: exit" << std::endl;
	std::cout << "P: current position" << std::endl;
	std::cout << "w: wall" << std::endl;
	std::cout << "T: large trap" << std::endl;
	std::cout << "t: small trap" << std::endl;
	std::cout << "X: fog of war" << std::endl;
	std::cout << std::endl;
	std::cout << "Whitespace is walkable region." << std::endl;
	std::cout << std::endl;
}
