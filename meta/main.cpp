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

template<int Index>
struct fibonacci {
	constexpr static int value = fibonacci<Index - 2>::value + fibonacci<Index - 1>::value;
};

template<>
struct fibonacci<1> {
	constexpr static int value = 1;
};

template<>
struct fibonacci<0> {
	constexpr static int value = 1;
};

int main() {
	std::cout << value2 << '\n';

	std::cout << "3! = " << fractional<3>::value << '\n';

	std::cout << "fibonacci<5>::value = " << fibonacci<5>::value << '\n';
}
