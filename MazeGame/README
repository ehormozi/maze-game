all : MazeGame

MazeGame : tmp/box_iterator.o tmp/field.o tmp/field_effect.o tmp/game.o tmp/hidden_trap.o tmp/large_trap.o tmp/main.o tmp/manual_player.o tmp/maze.o tmp/maze_entrance.o tmp/maze_exit.o tmp/maze_iterator.o tmp/neighbours_iterator.o tmp/offset_2d.o tmp/path.o tmp/player.o tmp/point2d.o tmp/small_trap.o tmp/storage.o tmp/wall.o
	g++ -Wall tmp/*.o -o MazeGame

tmp/box_iterator.o : src/box_iterator.cpp
	g++ -Wall -c src/box_iterator.cpp -o tmp/box_iterator.o

tmp/field.o : src/field.cpp
	g++ -Wall -c src/field.cpp -o tmp/field.o

tmp/field_effect.o : src/field_effect.cpp
	g++ -Wall -c src/field_effect.cpp -o tmp/field_effect.o

tmp/game.o : src/game.cpp
	g++ -Wall -c src/game.cpp -o tmp/game.o

tmp/hidden_trap.o : src/hidden_trap.cpp
	g++ -Wall -c src/hidden_trap.cpp -o tmp/hidden_trap.o

tmp/large_trap.o : src/large_trap.cpp
	g++ -Wall -c src/large_trap.cpp -o tmp/large_trap.o

tmp/main.o : src/main.cpp
	g++ -Wall -c src/main.cpp -o tmp/main.o

tmp/manual_player.o : src/manual_player.cpp
	g++ -Wall -c src/manual_player.cpp -o tmp/manual_player.o

tmp/maze.o : src/maze.cpp
	g++ -Wall -c src/maze.cpp -o tmp/maze.o

tmp/maze_entrance.o : src/maze_entrance.cpp
	g++ -Wall -c src/maze_entrance.cpp -o tmp/maze_entrance.o

tmp/maze_exit.o : src/maze_exit.cpp
	g++ -Wall -c src/maze_exit.cpp -o tmp/maze_exit.o

tmp/maze_iterator.o : src/maze_iterator.cpp
	g++ -Wall -c src/maze_iterator.cpp -o tmp/maze_iterator.o

tmp/neighbours_iterator.o : src/neighbours_iterator.cpp
	g++ -Wall -c src/neighbours_iterator.cpp -o tmp/neighbours_iterator.o

tmp/offset_2d.o : src/offset_2d.cpp
	g++ -Wall -c src/offset_2d.cpp -o tmp/offset_2d.o

tmp/path.o : src/offset_2d.cpp
	g++ -Wall -c src/path.cpp -o tmp/path.o

tmp/player.o : src/player.cpp
	g++ -Wall -c src/player.cpp -o tmp/player.o

tmp/point2d.o : src/point2d.cpp
	g++ -Wall -c src/point2d.cpp -o tmp/point2d.o

tmp/small_trap.o : src/small_trap.cpp
	g++ -Wall -c src/small_trap.cpp -o tmp/small_trap.o

tmp/storage.o : src/storage.cpp
	g++ -Wall -c src/storage.cpp -o tmp/storage.o

tmp/wall.o : src/wall.cpp
	g++ -Wall -c src/wall.cpp -o tmp/wall.o

clear:
	rm tmp/*
	rm MazeGame
