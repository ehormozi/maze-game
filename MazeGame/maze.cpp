#include "header.h"

template <typename T>
storage<T>::storage(size_t n)
{
	if (n != (std::sqrt(n)) * (std::sqrt(n)))
	{
		throw "n is not valid";
	}
	n_ = n;
	elements_ = std::vector<T>(n);
}

template <typename T>
T& storage<T>::operator()(point2d p)
{
	if (p.x >= std::sqrt(n_) || p.y >= std::sqrt(n_))
	{
		throw std::out_of_range("point not valid");
	}
	return elements_[p.x * std::sqrt(n_) + p.y];
}

template <typename T>
T storage<T>::operator()(point2d p) const
{
	if (p.x >= std::sqrt(n_) || p.y >= std::sqrt(n_))
	{
		throw std::out_of_range("point not valid");
	}
	return elements_[p.x * std::sqrt(n_) + p.y];
}

template <typename T>
coord storage<T>::max_coord() const
{
	return std::sqrt(n_) - 1;
}

template <typename T>
bool storage<T>::has_point(const point2d& p) const
{
	return p.x <= max_coord() && p.y <= max_coord();
}

template <typename T>
void storage<T>::reserve(unsigned n)
{
	elements_.reserve(n);
}

template <typename T>
void storage<T>::resize(unsigned n)
{
	if (n != (std::sqrt(n)) * (std::sqrt(n)))
	{
		throw "n is not valid";
	}
	elements_.resize(n);
	n_ = n;
}

template <typename T>
std::vector<T>& storage<T>::get_storage()
{
	return elements_;
}

maze::maze(size_t n) : storage{ n } {}

maze::maze(std::string s) : storage{ s.length() }
{
	for (unsigned i = 0; i < s.length(); i++)
	{
		elements_[i] = to_field(s[i]);
	}
}

maze_iterator maze::observe(const point2d& p)
{
	return maze_iterator{ p.x - 2, p.x + 2, p.y - 2, p.y + 2, *this };
}

field_effect maze::evaluate_effects(const point2d& p) const
{
	auto res = field_effect{ field_state::NONE, 0 };
	auto iter = maze_iterator{ 0, max_coord() + 1, 0, max_coord() + 1, *this };
	for (point2d it = iter.begin(); !iter.is_done(); iter.operator++())
	{
		if (has_point(iter.get_c_pos()))
		{
			auto f = operator()(iter.get_c_pos());
			res += (*(f.get())).effect(iter.get_c_pos() - p);
		}
	}
	return res;
}

void maze::reveal(const point2d& point)
{
	(*(operator()(point).get())).reveal();
}

void maze::print()
{
	for (size_t i = 0; i <= max_coord(); i++)
	{
		for (size_t j = 0; j <= max_coord(); j++)
		{
			auto p = point2d{i, j};
			std::cout << (*(operator(p).get())).to_char() << std::endl;
		}
		std::cout << std::endl;
	}
}
