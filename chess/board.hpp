#pragma once

#include "move.hpp"

struct Board {
	constexpr static unsigned WIDTH  = 8;
	constexpr static unsigned HEIGHT = 8;

	Board();

	void show() const;
	bool move(const Move& move);
private:
	char fields[HEIGHT][WIDTH];
};
