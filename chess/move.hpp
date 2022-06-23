#pragma once

#include <string>

struct Move {
	Move(const std::string & from, const std::string& to);
	[[nodiscard]] bool calculate_indexes(int & start_row, int & start_col, int & end_row, int & end_col) const;
private:
	const std::string from;
	const std::string to;
};
