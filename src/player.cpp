#include "../header/player.h"
#include "../header/maze.h"
#include "../header/maze_iterator.h"

player::player(maze maze, point2d position) :
    maze_{ maze },
    position_{ position },
    state_{field_state::NONE},
    hp_{100}
{}

void player::observe()
{
    auto iterator = maze_.observe(position_);
    for (iterator.begin(); !iterator.is_done(); ++iterator)
    {
    	if (!point_observed(iterator.get_c_pos()))
    	{
	        maze_.reveal(iterator.get_c_pos());
	}
    }
}

field_effect player::act(char input)
{
    if (input == 'z')
    {
        field_effect res;
        if (maze_.has_point({ position_.x - 1, position_.y }) && (*(maze_(point2d{position_.x - 1, position_.y}).get())).to_char() != 'w')
        {
            position_.x -= 1;
            return maze_.evaluate_effects(position_);
        }
        else
        {
            return field_effect{ field_state::BLOCKED, 0 };
        }
    }
    else if (input == 's')
    {
        if (maze_.has_point({ position_.x + 1, position_.y }) && (*(maze_(point2d{position_.x + 1, position_.y}).get())).to_char() != 'w')
        {
        	position_.x += 1;
        	return maze_.evaluate_effects(position_);
        }
        else
        {
            return field_effect{ field_state::BLOCKED, 0 };
        }
    }
    else if (input == 'q')
    {
        if (maze_.has_point({ position_.x, position_.y - 1 }) && (*(maze_(point2d{position_.x, position_.y - 1}).get())).to_char() != 'w')
        {
            position_.y -= 1;
            return maze_.evaluate_effects(position_);
        }
        else
        {
            return field_effect{ field_state::BLOCKED, 0 };
        }
    }
    else if (input == 'd')
    {
        if (maze_.has_point({ position_.x, position_.y + 1 }) && (*(maze_(point2d{position_.x, position_.y + 1}).get())).to_char() != 'w')
        {
            position_.y += 1;
            return maze_.evaluate_effects(position_);
        }
        else
        {
            return field_effect{ field_state::BLOCKED, 0 };
        }
    }
    else
    {
        throw "User input is not valid";
    }
}

bool player::point_observed(const point2d& point)
{
    return (*(maze_(point).get())).to_char() != 'X';
}

point2d player::get_position() const
{
	return position_;
}

bool player::is_dead() const
{
	return hp_ <= 0;
}

void player::apply_effects(const field_effect &fe)
{
	hp_ -= fe.damage;
	state_ = fe.state;
	if (state_ == field_state::DEADLY)
	{
		hp_ = 0;
	}
}
