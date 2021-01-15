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

template <typename T>
class storage
{
	public:

	storage() = delete;

	storage(size_t n);

	storage(const storage& other) = default;

	storage& operator=(const storage& other) = default;

	T& operator()(point2d p);

	T operator()(point2d p) const;

	coord max_coord() const;

	bool has_point(const point2d& p) const;

	void reserve(unsigned n);

	void resize(unsigned n);

	std::vector<T>& get_storage();

	protected:

	unsigned n_;
	std::vector<T> elements_;
};
