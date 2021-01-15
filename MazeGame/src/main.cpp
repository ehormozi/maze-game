#include "../header/game.h"

int main()
{
	auto m = maze{100};
	auto p = player{m, m.getCoordEntrance()};
	auto g = game{&m, &p};
	p.observe();
	g.print();
	while (!g.is_won() && !p.is_dead())
	{
		char in;
		std::cin >> in;
		auto effects = p.act(in);
		p.apply_effects(effects);
		p.observe();
		g.print();
	}
	if (g.is_won())
	{
		std::cout << "You Won!" << std::endl;
	}
	else if (p.is_dead())
	{
		std::cout << "You Died!" << std::endl;
	}
	return 0;
}
