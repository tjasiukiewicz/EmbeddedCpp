#include "game.hpp"
#include "display.hpp"

Game::Game()
	: current_player{std::make_unique<Player>("Adam")},
	next_player{std::make_unique<Player>("Eve")},
	board{std::make_unique<Board>()}
{
}

void Game::run() {
	board->prepare_display();
	Display::show();
	for(;;) {
		auto move = current_player->get_move();
		if (!board->move(move)) {
			Display::illegal_move_error();
			continue;
		}
		board->prepare_display();
		Display::show();
		std::swap(current_player, next_player);
	}
}
