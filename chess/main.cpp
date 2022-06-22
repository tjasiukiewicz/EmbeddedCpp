#include <iostream>
#include "board.hpp"

int main() {
	auto board = Board();
	board.show();
	if (board.move(7, 1, 7, 3)) {
		board.show();
	} else {
		std::cerr << "Illegal move!\n";
	}
}
