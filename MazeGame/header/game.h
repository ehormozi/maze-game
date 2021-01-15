#pragma once

#include <iterator>
#include <cassert>
#include <memory>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>

#include "maze.h"
#include "player.h"

class game
{
public:

	game(maze *m, player *p);
	bool is_won() const;
	void print();
	void print_guide() const;

private:

	maze *maze_;
	player *player_;
};
