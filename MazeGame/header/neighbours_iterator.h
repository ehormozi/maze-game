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

#include "box_iterator.h"

class neighbours_iterator : box_iterator
{
public:

	using iterator_category = std::forward_iterator_tag;
	using value_type = point2d;
	using difference_type = void;
	using pointer = point2d*;
	using reference = point2d&;

	neighbours_iterator(point2d p);

	void reset();

	neighbours_iterator& operator++();

	bool is_done() const;

protected:

	point2d p_;
};
