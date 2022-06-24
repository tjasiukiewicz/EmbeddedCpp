#pragma once

#include <string>
#include "move.hpp"

struct Player {
	Player(const std::string& name);
	Move get_move() const;
private:
	const std::string name;
};
