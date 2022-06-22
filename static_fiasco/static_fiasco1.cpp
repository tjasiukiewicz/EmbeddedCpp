#include <iostream>

struct X1 {
	X1() {
		std::cout << "Construct X1\n";
	}

	~X1() {
		std::cout << "Destruct X1\n";
	}
};

static X1 x1 = X1();

int main() {
	//...
}
