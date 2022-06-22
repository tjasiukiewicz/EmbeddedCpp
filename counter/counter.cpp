#include <iostream>

struct Counter {
	Counter(int min_value, int max_value)
		: min_value{min_value}, max_value{max_value}, value{min_value} {
	}

	int get() const {
		return value;
	}
	Counter& operator++() {
		++value;
		if (value > max_value) {
			value = min_value;
		}

		return *this;
	}
private:
	int min_value;
	int max_value;
	int value;
};

int main() {
	auto counter = Counter(15, 17);
	++counter;
	++counter;
	++counter;
	std::cout << counter.get() << '\n';
	std::cout << sizeof(counter) << '\n';
}
