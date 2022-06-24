#include <iostream>
#include "board.hpp"
#include "move.hpp"
#include "player.hpp"

int main() {
	auto board = Board();
	board.show();

	if(board.move(Move("e2", "e4"))) {
		board.show();
	} else {
		std::cerr << "Illegal move!\n";
	}

	if(board.move(Move("e7", "e5"))) {
		board.show();
	} else {
		std::cerr << "Illegal move!\n";
	}

	auto player = Player("Adam");
	auto move = player.get_move();
	if(board.move(move)) {
		board.show();
	} else {
		std::cerr << "Illegal move!\n";
	}
}
