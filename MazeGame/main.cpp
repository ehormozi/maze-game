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
    for (size_t i = 0; i < 25; i++)
    {
        int r = (rand() % 20) + 1;
        if (r == 1)
        {
            maze_str.push_back('I');
        }
        else if (r == 2)
        {
            maze_str.push_back('O');
        }
        else if (r >= 3 && r <= 6)
        {
            maze_str.push_back('w');
        }
        else if (r >= 7 && r <= 14)
        {
            maze_str.push_back(' ');
        }
        else if (r == 15 || r == 16)
        {
            maze_str.push_back('t');
        }
        else if (r == 17 || r == 18)
        {
            maze_str.push_back('T');
        }
        else if (r == 19 || r == 20)
        {
            maze_str.push_back('H');
        }
    }
	auto m = maze(maze_str);
	return 0;
}
