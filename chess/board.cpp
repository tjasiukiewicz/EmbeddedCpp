#include <cctype>
#include <cstring>
#include "board.hpp"
#include "display.hpp"
#include "move.hpp"

namespace {

inline bool is_cell_empty(char cell) {
	return cell != ' ';
}

} // anonymous namespace

Board::Board() {
	for (auto & row: fields) {
		for (auto & cell: row) {
			cell = ' ';
		}
	}

	const char figures[] = "RNBQKBNR";
	for (auto idx = 0U; idx < BOARD_WIDTH; ++idx) {
		fields[0][idx] = figures[idx];
		fields[1][idx] = 'P';
		fields[6][idx] = 'p';
		fields[7][idx] = tolower(figures[idx]);
	}
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

void Board::prepare_display() const {
	auto ptr = Display::get_data_location();
	// XXX: Maybe conversion to Display format...
	memcpy(ptr, fields, BOARD_WIDTH * BOARD_HEIGHT * sizeof(char));
}
