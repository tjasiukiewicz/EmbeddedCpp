#pragma once

#include <string>

struct Display {
	Display() = delete;
	Display(const Display&) = delete;
	Display& operator=(const Display&) = delete;

	static char * get_data_location();
	static void show();
	static void illegal_move_error();
	static void show_player_prompt(const std::string& name);
	static std::string get_move_string();
};
