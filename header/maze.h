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

#include "storage.h"

class maze_iterator;

class maze : public storage<field_ptr>
{
	public:

	maze() = delete;

	maze(size_t n);

	maze(std::string s);

	maze(const maze& other) = default;

	maze& operator=(const maze& other) = default;

	maze_iterator observe(const point2d& p);

	field_effect evaluate_effects(const point2d& p) const;

	void reveal(const point2d& point);
	
	void print(const point2d& player_position) const;
	
	point2d getCoordEntrance() const;
	
	point2d getCoordExit() const;
		
	point2d exit_;
};
