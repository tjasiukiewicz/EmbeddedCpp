#pragma once

#include <string>
#include <optional>
#include <tuple>

struct Move {
	using coordinates = std::tuple<int, int, int, int>;
	using coords_option_t = std::optional<coordinates>;

	Move(const std::string & from, const std::string& to);
	[[nodiscard]] coords_option_t calculate_indexes() const;
private:
	const std::string from;
	const std::string to;
};
