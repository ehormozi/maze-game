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

class player
{
public:

	player(maze maze, point2d position);

	void observe();

	field_effect act(char input);

	bool point_observed(const point2d& point);
	
	point2d get_position() const;
	
	bool is_dead() const;
	
	void apply_effects(const field_effect &fe);

	maze maze_;

	point2d position_;

	field_state state_;

	int hp_;
};
