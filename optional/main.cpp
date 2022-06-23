#include <iostream>
#include <optional>
#include <cmath>

std::optional<double> my_sqrt(double value) {
	if (value < 0.0) {
		return {};
	}
	//return std::make_optional<double>(std::sqrt(value));
	return {std::sqrt(value)};
}

int main() {
	auto result = my_sqrt(2);
	if (result.has_value()) {
		std::cout << *result << '\n';
	} else {
		std::cerr << "No results!\n";
	}
}
