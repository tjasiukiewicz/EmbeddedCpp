#include <iostream>
#include "game.hpp"
#include "player.hpp"
#include "board.hpp"

Game::Game()
	: current_player{new Player("Adam")}, next_player{new Player("Eve")}, board{new Board()} {
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

Game::~Game() {
	delete current_player;
	delete next_player;
	delete board;
}
