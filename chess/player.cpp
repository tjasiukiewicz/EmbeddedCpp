#include "player.hpp"
#include "display.hpp"

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
	std::string move_s;
	for(;;) {
		Display::show_player_prompt(name);
		move_s = Display::get_move_string();
		if (is_move_ok(move_s)) {
			break;
		}
		Display::illegal_move_error();
	}
	return Move({move_s.begin(), move_s.begin() + 2}, {move_s.begin() + 2, move_s.end()});
}
