#include <iostream>
#include "board.hpp"

void try_move(Board & board, unsigned start_col, unsigned start_row, unsigned end_col, unsigned end_row) {
	if (board.move(start_col, start_row, end_col, end_row)) {
		board.show();
	} else {
		std::cerr << "Illegal move!\n";
	}
}

int main() {
	auto board = Board();
	board.show();

	try_move(board, 7U, 1U, 7U, 3U); // Legal move
	try_move(board, 6U, 1U, 6U, 1U); // Illegal move
}
