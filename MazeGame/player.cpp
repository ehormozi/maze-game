#include "header.h"

player::player(maze maze, point2d position) :
    maze_{ maze },
    position_{ position },
    state_{field_state::NONE},
    hp_{100}
{}

void player::observe()
{
    auto iterator = maze_.observe(position_);
    for (iterator.begin(); !iterator.is_done(); iterator.operator++())
    {
        maze_.reveal(iterator.get_c_pos());
    }
}

field_effect player::act(char input)
{
    if (input == 'w')
    {
        field_effect res;
        if (maze_.has_point({ position_.x - 1, position_.y }) && (*(maze_(position_).get())).to_char() != 'w')
        {
            position_.x -= 1;
            observe();
            return maze_.evaluate_effects(position_);
        }
        else
        {
            return field_effect{ field_state::BLOCKED, 0 };
        }
    }
    else if (input == 's')
    {
        if (maze_.has_point({ position_.x + 1, position_.y }) && (*(maze_(position_).get())).to_char() != 'w')
        {
            position_.x += 1;
            observe();
            return maze_.evaluate_effects(position_);
        }
        else
        {
            return field_effect{ field_state::BLOCKED, 0 };
        }
    }
    else if (input == 'a')
    {
        if (maze_.has_point({ position_.x, position_.y - 1 }) && (*(maze_(position_).get())).to_char() != 'w')
        {
            position_.y -= 1;
            observe();
            return maze_.evaluate_effects(position_);
        }
        else
        {
            return field_effect{ field_state::BLOCKED, 0 };
        }
    }
    else if (input == 'd')
    {
        if (maze_.has_point({ position_.x, position_.y + 1 }) && (*(maze_(position_).get())).to_char() != 'w')
        {
            position_.y += 1;
            observe();
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
