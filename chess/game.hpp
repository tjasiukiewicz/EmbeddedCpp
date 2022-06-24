#pragma once

struct Player;
struct Board;

struct Game {
	Game();
	void run();
	~Game();
private:
	Player * current_player;
	Player * next_player;
	Board * board;
};
