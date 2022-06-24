#include <iostream>
#include <string>
#include <memory>

struct X {
	X(const std::string& name_)
		: name{name_} {
		std::cout << "X construct name = " << name <<'\n';
	}
	~X() {
		std::cout << "X destruct name = " << name << '\n';
	}
private:
	const std::string name;
};

int main() {
	auto aptr1 = std::make_unique<X>("x1");
	std::cout << "before scope\n";
	{
		auto aptr2 = std::make_unique<X>("x2");
		auto aptr3 = std::unique_ptr<X>();
		aptr3 = std::move(aptr1);
	}
	std::cout << "after scope\n";
}
