#pragma once

#include <memory>
#include "player.hpp"
#include "board.hpp"

struct Game {
	Game();
	void run();
private:
	std::unique_ptr<Player> current_player;
	std::unique_ptr<Player> next_player;
	const std::unique_ptr<Board> board;
};
