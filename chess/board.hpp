#pragma once

struct Board {
	constexpr static unsigned WIDTH  = 8;
	constexpr static unsigned HEIGHT = 8;
	Board();
	void show() const;
private:
	char fields[HEIGHT][WIDTH];
};
