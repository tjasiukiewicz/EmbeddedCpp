#include <iostream>
#include "game.hpp"

Game::Game()
	: current_player{std::make_unique<Player>("Adam")},
	next_player{std::make_unique<Player>("Eve")},
	board{std::make_unique<Board>()}
{
}

void Game::run() {
	board->show();
	for(;;) {
		auto move = current_player->get_move();
		if (!board->move(move)) {
			std::cerr << "Illegal move! Try again.\n";
			continue;
		}
		board->show();
		std::swap(current_player, next_player);
	}
}
