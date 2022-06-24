#include <iostream>
#include "display.hpp"
#include "settings.hpp"

namespace {

inline void show_row_separator() {
	std::cout << "  ";
	auto i = BOARD_WIDTH;
	while (i-->0) {
		std::cout << "+-";
	}
	std::cout << "+\n";
}

inline void show_column_name() {
	std::cout << "   ";
	for (auto i = 0U; i < BOARD_WIDTH; ++i) {
		std::cout << static_cast<char>('a' + i) << ' ';
	}
	std::cout << '\n';
}

inline void show_row(const char cells[BOARD_WIDTH], int row_counter) {
	std::cout << row_counter + 1 << ' ';
	for (unsigned col = 0U; col < BOARD_WIDTH; ++col) {
		std::cout << "|" << cells[col];
	}
	std::cout << "| " << row_counter + 1 << "\n";
	show_row_separator();
}

} // anonymous namespace


static char fields[BOARD_HEIGHT][BOARD_WIDTH];

char * Display::get_data_location() {
	return reinterpret_cast<char *>(fields);
}

void Display::show() {
	show_column_name();
	show_row_separator();
	int row_idx = BOARD_HEIGHT;
	while (row_idx-->0) {
		show_row(fields[row_idx], row_idx);
	}
	show_column_name();
}

void Display::illegal_move_error() {
	std::cerr << "Illegal move! Try again.\n";
}

void Display::show_player_prompt(const std::string& name) {
	std::cout << "Move like: e2e4\n";
	std::cout << "Player: " << name << " Your move: ";
}

std::string Display::get_move_string() {
	std::string move_s;
	std::cin >> move_s;
	return move_s;
}
