#include <iostream>
#include <cctype>
#include "board.hpp"

namespace {

inline void show_row_separator() {
	std::cout << "  +-+-+-+-+-+-+-+-+\n";
}

inline void show_column_name() {
	std::cout << "   a b c d e f g h\n";
}

inline void show_row(const char cells[Board::WIDTH], int row_counter) {
		std::cout << row_counter + 1 << ' ';
		for (int col = 0; col < Board::WIDTH; ++col) {
			std::cout << "|" << cells[col];
		}
		std::cout << "| " << row_counter + 1 << "\n";
		show_row_separator();
}


}

Board::Board() {
	for (auto & row: fields) {
		for (auto & cell: row) {
			cell = ' ';
		}
	}

	const char figures[] = "RNBQKBNR";
	for (auto idx = 0U; idx < WIDTH; ++idx) {
		fields[0][idx] = figures[idx];
		fields[1][idx] = 'P';
		fields[6][idx] = 'p';
		fields[7][idx] = tolower(figures[idx]);
	}
}

void Board::show() const {
	show_column_name();
	show_row_separator();
	int row = HEIGHT;
	while (row-->0) {
		show_row(fields[row], row);
	}
	show_column_name();
}

bool Board::move(int start_col, int start_row, int end_col, int end_row) {
	return true;
}
