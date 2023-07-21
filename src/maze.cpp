#include "../header/maze.h"
#include "../header/maze_iterator.h"

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

maze::maze(size_t n) : storage{ n }, exit_{ 0, 0 }
{
	auto maze_str = std::string("");
	srand((int)time(0));
	for (size_t i = 0; i < 100; i++)
	{
		int r = (rand() % 20) + 1;
		if (r == 1)
		{
		    if (maze_str.find('I') == std::string::npos)
		    {
			maze_str.push_back('I');
		    }
		    else
		    {
			maze_str.push_back(' ');
		    }
		}
		else if (r == 2)
		{
		    if (maze_str.find('O') == std::string::npos)
		    {
			maze_str.push_back('O');
		    }
		    else
		    {
			maze_str.push_back(' ');
		    }
		}
		else if (r >= 3 && r <= 7)
		{
		    maze_str.push_back('w');
		}
		else if (r >= 8 && r <= 17)
		{
		    maze_str.push_back(' ');
		}
		else if (r == 18)
		{
		    maze_str.push_back('t');
		}
		else if (r == 19)
		{
		    maze_str.push_back('T');
		}
		else if (r == 20)
		{
		    maze_str.push_back('H');
		}
	}
	if (maze_str.find('I') == std::string::npos)
	{
		maze_str[0] = 'I';
	}
	if (maze_str.find('O') == std::string::npos)
	{
		maze_str[maze_str[99]] = 'O';
	}
	for (unsigned i = 0; i < n_; i++)
	{
		elements_[i] = to_field(maze_str[i]);
	}
	exit_ = getCoordExit();
}

maze::maze(std::string s) : storage{ s.length() }, exit_{ 0, 0 }
{
	for (unsigned i = 0; i < s.length(); i++)
	{
		elements_[i] = to_field(s[i]);
	}
	exit_ = getCoordExit();
}

maze_iterator maze::observe(const point2d& p)
{
	return maze_iterator{ p.x - 2, p.x + 3, p.y - 2, p.y + 3, *this };
}

field_effect maze::evaluate_effects(const point2d& p) const
{
	auto res = field_effect{ field_state::NONE, 0 };
	auto iter = maze_iterator{ 0, max_coord() + 1, 0, max_coord() + 1, *this };
	for (iter.begin(); !iter.is_done(); ++iter)
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

void maze::print(const point2d& player_position) const
{
	for (int i = 0; i <= max_coord(); i++)
	{
		for (int j = 0; j <= max_coord(); j++)
		{
			auto p = point2d{i, j};
			if (p == player_position)
			{
				std::cout << 'P';
			}
			else
			{
				std::cout <<
				(*(operator()(p).get())).to_char();
			}
		}
		std::cout << std::endl;
	}
}

point2d maze::getCoordEntrance() const
{
	auto it = box_iterator(0, max_coord() + 1, 0, max_coord() + 1);
	for (it.begin(); !it.is_done(); ++it)
	{
		if ((*(operator()(it.get_c_pos()).get())).to_char() == 'I')
		{
			return it.get_c_pos();
		}
	}
	throw "No entrance found in maze.";
}

point2d maze::getCoordExit() const
{
	auto it = box_iterator(0, max_coord() + 1, 0, max_coord() + 1);
	for (it.begin(); !it.is_done(); ++it)
	{
		if ((*(operator()(it.get_c_pos()).get())).to_char() == 'O')
		{
			return it.get_c_pos();
		}
	}
	throw "No exit found in maze.";
}
