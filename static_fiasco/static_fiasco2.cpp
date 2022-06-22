#include <iostream>


struct X2 {
	X2() {
		std::cout << "Construct X2\n";
	}

	~X2() {
		std::cout << "Destruct X2\n";
	}
};

static X2 x2 = X2();
