#include <iostream>


// Old way :)
enum Values {
	value1 = 10,
	value2 = value1 + 20, 
};


template<int Value>
struct fractional {
	constexpr static int value = fractional<Value - 1>::value * Value;
};

template<>
struct fractional<0> {
	constexpr static int value = 1;
};

int main() {
	std::cout << value2 << '\n';

	std::cout << fractional<3>::value << '\n';


}
