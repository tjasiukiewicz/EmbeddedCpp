#include <iostream>

template<int MinValue, int MaxValue>
struct Counter {
	Counter()
		: value{MinValue} {
	}

	operator int() const {
		return value;
	}

	Counter& operator++() {
		++value;
		if (value > MaxValue) {
			value = MinValue;
		}

		return *this;
	}
private:
	int value;
};

int main() {
	auto counter1 = Counter<15, 17>();
	auto counter2 = Counter<16, 17>();
	++counter1;
	++counter1;
	++counter1;
	++counter2;
	std::cout << counter1 << '\n';
	std::cout << counter2 << '\n';
	std::cout << sizeof(counter1) << '\n';
}
