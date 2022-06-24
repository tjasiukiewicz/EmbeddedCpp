#include <iostream>
#include <cctype>
#include <cassert>
#include "board.hpp"

namespace {

inline void show_row_separator() {
	std::cout << "  ";
	auto i = Board::WIDTH;
	while (i-->0) {
		std::cout << "+-";
	}
	std::cout << "+\n";
}

inline void show_column_name() {
	std::cout << "   ";
	for (auto i = 0U; i < Board::WIDTH; ++i) {
		std::cout << static_cast<char>('a' + i) << ' ';
	}
	std::cout << '\n';
}

inline void show_row(const char cells[Board::WIDTH], int row_counter) {
	std::cout << row_counter + 1 << ' ';
	for (unsigned col = 0U; col < Board::WIDTH; ++col) {
		std::cout << "|" << cells[col];
	}
	std::cout << "| " << row_counter + 1 << "\n";
	show_row_separator();
}

inline bool is_cell_empty(char cell) {
	return cell != ' ';
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
	int row_idx = HEIGHT;
	while (row_idx-->0) {
		show_row(fields[row_idx], row_idx);
	}
	show_column_name();
}

bool Board::move(const Move& move) {
	auto indexes = move.calculate_indexes();
	if (indexes.has_value()) {
		auto [s_row, s_col, e_row, e_col] = *indexes;
		if (!is_cell_empty(fields[e_row][e_col])) {
			// Move piece
			char piece = fields[s_row][s_col];
			fields[s_row][s_col] = ' ';
			fields[e_row][e_col] = piece;
			return true;
		}
	}

	return false;
}
