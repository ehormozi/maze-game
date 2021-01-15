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

#include "point2d.h"
#include "field.h"
#include "box_iterator.h"
#include "maze.h"

class maze_iterator : public box_iterator
{
public:

	using iterator_category = std::forward_iterator_tag;
	using value_type = point2d;
	using difference_type = void;
	using pointer = point2d*;
	using reference = point2d&;

	maze_iterator(coord x_beg, coord x_end, coord y_beg, coord y_end, maze m);

	maze_iterator(const point2d& lower_left, const point2d& upper_right, maze m);

	maze_iterator& operator++();

private:

	maze maze_;
};
