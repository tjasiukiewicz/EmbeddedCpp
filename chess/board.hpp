#pragma once

struct Board {
	constexpr static unsigned WIDTH  = 8;
	constexpr static unsigned HEIGHT = 8;
	Board();
	void show() const;
	bool move(unsigned start_col, unsigned start_row, unsigned end_col, unsigned end_row);
private:
	char fields[HEIGHT][WIDTH];
};
