#include <utility>
#include <iostream>
#include "move.hpp"
#include "board.hpp"

namespace {

bool in_length(const std::string& position) {
	return position.length() == 2;
}

bool in_column(const std::string& position) {
	return (position[0] >= 'a') && (position[0] <= static_cast<char>('a' + Board::WIDTH));
}

bool in_row(const std::string& position) {
	return ((position[1] >= '1') && (position[1] <= static_cast<char>('0' + Board::WIDTH)));
}

std::pair<int, int> name_to_index(const std::string& position) {
	int col = position[0] - 'a';
	int row = position[1] - '0' - 1;
	return {row, col};
}

}

Move::Move(const std::string& from, const std::string& to)
	: from{from}, to{to} {
}

Move::coords_option_t Move::calculate_indexes() const {
	if (in_length(from) && in_column(from) && in_row(from) && in_length(to) && in_column(to) && in_row(to)) {
		auto [start_row, start_col] = name_to_index(from);
		auto [end_row, end_col] = name_to_index(to);
		return {{start_row, start_col, end_row, end_col}};
	}
	return {};
}

