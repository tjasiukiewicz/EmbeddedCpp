#include <iostream>

// C++14
//auto my_max(int a, int b) {
//	return a > b ? a: b;
//}

template<typename T1, typename T2>
auto my_max(const T1 & a, const T2 & b) -> decltype(a + b) {
	return a > b ? a: b;
}



int main() {

	auto a = 12.0;

	float b = 12.32;

	float c = 0.1F;
	if (c != 0.1) { // <- Zaskoczenie :)
		std::cout << "Difference!\n";
	}

	decltype(a) d = 32;

	// std::vector<int>::iterator i;
	
	const auto p = 3.1415;

	for (const auto & i: {10, 20, 30, 40}) {
		std::cout << i << '\n';
	}

	// double my_max(int, double)
	std::cout << my_max(12, 15.0) << '\n';
	std::cout << my_max(12.0, 15) << '\n';
}
