#pragma once

struct Board {
	constexpr static unsigned WIDTH  = 8;
	constexpr static unsigned HEIGHT = 8;
	Board();
	void show() const;
	bool move(int start_col, int start_row, int end_col, int end_row);
private:
	char fields[HEIGHT][WIDTH];
};
