#pragma once
#include "settings.hpp"

struct Move;

struct Board {
	Board();

	void show() const;
	bool move(const Move& move);
private:
	char fields[BOARD_HEIGHT][BOARD_WIDTH];
};
