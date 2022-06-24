#include <iostream>
#include "player.hpp"

namespace {

bool is_move_ok(const std::string& move_s) {
	if (move_s.length() == 4) {
		auto from = std::string(move_s.begin(), move_s.begin() + 2);
		auto to = std::string(move_s.begin() + 2, move_s.end());
		auto move = Move(from, to);
		if (move.calculate_indexes()) {
			return true;
		}
	}
	return false;
}


} // anonymous namespace

Player::Player(const std::string& name_)
	: name{name_} {}

Move Player::get_move() const {
	std::cout << "Move like: e2e4\n";
	std::cout << "Player: " << name << " Your move: ";
	std::string move_s;
	for(;;) {
		std::cin >> move_s;
		if (is_move_ok(move_s)) {
			break;
		}
		std::cerr << "Illegal move! Try again.\n";
	}
	return Move({move_s.begin(), move_s.begin() + 2}, {move_s.begin() + 2, move_s.end()});
}
