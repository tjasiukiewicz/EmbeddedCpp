#include <iostream>
#include <string>
#include <cstring>

struct X {
	X(const char * name_) {
		name = new std::string(name_);
		std::cout << "Construct X name = " << *name << '\n';
	}

	// non copyable object
	/*
	X(const X&) = delete;
	X& operator=(const X&) = delete;
	*/

	// Copy constructor and copy operator
	X(const X& src) {
		delete this->name;
		name = new std::string(*(src.name));
		std::cout << "Copy from src.name = " << *(src.name) << '\n';
	}

	X& operator=(const X& src) {
		std::cout << "operator= X from src.name = " << *(src.name) << '\n';
		delete name;
		name = new std::string(*(src.name));
		return *this;
	}

	// Move constructor and move operator
	X(X&& src) {
		delete this->name;
		name = src.name;
		src.name = nullptr;
		std::cout << "Move constructor from name = " << *(this->name) << '\n';
	}

	X& operator=(X&& src) {
		delete name;
		name = src.name;
		src.name = nullptr;
		std::cout << "operator= && X from src.name = " << *name << '\n';

		return *this;
	}

	const std::string * info() const {
		return name;
	}

	~X() {
		std::cout << "Destruct X name = ";
		if (name != nullptr) {
			std::cout << *name << '\n';
		} else {
			std::cout << "nullptr!\n";
		}
		delete name;
	}

private:
	std::string * name;
};

// Static construction digression 
void foo() {
	static auto x = X("static in function foo()");
	// ... 
}


void runner(X&& x) {
	// x object maybe is unstable!
	if (x.info() != nullptr) {
		std::cout << *(x.info()) << '\n';
	}
}


int main() {
	std::cout << "Start main()\n";
	auto x = X("My name1...");
	auto y = X("My name2...");
	auto a = X("My name a...");
	X q = X("My name3..."); // Copy delusion

	y = std::move(x);
	
	q = X(std::move(a));

	runner(std::move(q));

	//foo();
	//foo();

	std::cout << "End main()\n";
}
