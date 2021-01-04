#include "header.h"

field_ptr to_field(char c)
{
	if (c == 'I')
	{
		auto res = new maze_entrance();
		return field_ptr(res);
	}
	else if (c == 'O')
	{
		auto res = new maze_exit();
		return field_ptr(res);
	}
	else if (c == 'w')
	{
		auto res = new wall();
		return field_ptr(res);
	}
	else if (c == ' ')
	{
		auto res = new path();
		return field_ptr(res);
	}
	else if (c == 't')
	{
		auto res = new small_trap();
		return field_ptr(res);
	}
	else if (c == 'T')
	{
		auto res = new large_trap();
		return field_ptr(res);
	}
	else if (c == 'H')
	{
		auto res = new hidden_trap();
		return field_ptr(res);
	}
	else
	{
		throw "Character is not valid.";
	}
}

int main()
{
	auto maze_str = std::string("");
	srand((int)time(0));
	std::cout << (rand() % 10) + 1 << std::endl;
	auto m = maze("");
	return 0;
}