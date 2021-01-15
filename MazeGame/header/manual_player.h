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

#include "player.h"

class manual_player : public player
{
public:

	manual_player(maze maze, point2d position);
};
