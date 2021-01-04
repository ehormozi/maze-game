#pragma once

#include <iterator>
#include <cassert>
#include <memory>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>

/*
class box_iterator;
enum class field_state;
struct field_effect;
*/
class field;
/*
class hidden_trap;
class large_trap;
class manual_player;
class maze;
*/
class maze_iterator;
/*
class maze_entrance;
class maze_exit;
class neighbours_iterator;
struct offset2d;
template <>
struct std::less <offset2d>;
class path;
class player;
struct point2d;
template <>
struct std::less<point2d>;
class small_trap;
template <typename T>
class storage;
class wall;
*/

using coord = int;
using field_ptr = std::shared_ptr<field>;

struct offset2d
{
	offset2d() = delete;

	offset2d(coord dx_in, coord dy_in);

	offset2d(const offset2d& o) = default;

	offset2d& operator=(const offset2d& o) = default;

	bool operator==(const offset2d& o) const;

	bool operator!=(const offset2d& o) const;

	bool operator<(const offset2d& o) const;

	offset2d& operator+=(const offset2d& o);

	offset2d& operator-=(const offset2d& o);

	offset2d operator+(const offset2d& other) const;

	offset2d operator-(const offset2d& other) const;

	coord dx;
	coord dy;
};

struct point2d
{
	point2d() = delete;

	point2d(coord x_in, coord y_in);

	point2d(const point2d& o) = default;

	point2d& operator=(const point2d& o) = default;

	bool operator==(const point2d& o) const;

	bool operator!=(const point2d& o) const;

	bool operator<(const point2d& o) const;

	point2d& operator+=(const offset2d& o);

	point2d& operator-=(const offset2d& o);

	coord x;
	coord y;
};

enum class field_state
{
	NONE = 0,
	FREE,
	DAMAGING,
	ENTRANCE,
	EXIT,
	DEADLY,
	BLOCKED,
};

struct field_effect
{
	field_effect& operator+=(const field_effect& other);

	bool operator!=(const field_effect& rhs);

	field_state state = field_state::NONE;

	unsigned damage = 0;
};

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
};

class box_iterator
{
public:

	using iterator_category = std::forward_iterator_tag;
	using value_type = point2d;
	using difference_type = void;
	using pointer = point2d*;
	using reference = point2d&;

	box_iterator(coord x_beg, coord x_end, coord y_beg, coord y_end);

	box_iterator(const point2d& lower_left, const point2d& upper_right);

	void reset();

	box_iterator& operator++();

	bool operator==(const box_iterator& o) const;

	bool operator!=(const box_iterator& o) const;

	point2d operator*();

	point2d get_c_pos() const;

	bool is_done() const;

	point2d begin();

protected:

	coord x_beg_;
	coord x_end_;
	coord y_beg_;
	coord y_end_;
	point2d c_pos_;
};

class field
{
public:

	field(char c);

	virtual ~field();

	char to_char() const;

	void set(char c) const;

	virtual field_effect effect(const offset2d& o, bool is_sim = true) const = 0;

	field_effect effect() const;

	void reveal();

private:

	mutable char c_;
};

class hidden_trap : public  field
{
public:

	hidden_trap();

	field_effect effect(const offset2d& o, bool is_sim = true) const override;
};

class large_trap : public  field
{
public:

	large_trap();

	field_effect effect(const offset2d& o, bool is_sim = true) const override;
};

class player
{
public:

	player(maze maze, point2d position);

	void observe();

	field_effect act(char input);

	bool point_observed(const point2d& point);

protected:

	maze maze_;
	point2d position_;
	field_state state_;
	unsigned hp_;
};

class manual_player : public player
{
public:

	manual_player(maze maze, point2d position);
};

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

class maze_entrance : public field
{
public:

	maze_entrance();

	field_effect effect(const offset2d& o, bool is_sim = true) const override;
};

class maze_exit : public  field
{
public:

	maze_exit();

	field_effect effect(const offset2d& o, bool is_sim = true) const override;
};

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

template <>
struct std::less<offset2d>
{
	bool operator()(const offset2d& lhs, const offset2d& rhs) const;
};

class path : public  field
{
public:

	path();

	field_effect effect(const offset2d& o, bool is_sim = true) const override;
};

template <>
struct std::less<point2d>
{
	bool operator()(const point2d& lhs, const point2d& rhs) const;
};

class small_trap : public  field
{
public:

	small_trap();

	field_effect effect(const offset2d& o, bool is_sim = true) const override;
};

class wall : public  field
{
public:

	wall();

	field_effect effect(const offset2d& o, bool is_sim = true) const override;
};

field_ptr to_field(char c);
point2d operator+(const point2d& p, const offset2d& o);
point2d operator+(const offset2d& o, const point2d& p);
point2d operator-(const point2d& p, const offset2d& o);
point2d operator-(const offset2d& o, const point2d& p);
offset2d operator-(const point2d& p1, const point2d& p2);