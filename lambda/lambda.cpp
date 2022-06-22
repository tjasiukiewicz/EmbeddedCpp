#include <iostream>


int main() {
	// []{}
	[]{}; 
	auto f1 = []() { std::cout << "I'm lambda\n"; }; // Sygnatura to (chyba) void lambda(void);
	f1 = [](){ std::cout << "I'm second lambda\n"; };
}
