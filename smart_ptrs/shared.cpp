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
	auto aptr1 = std::make_shared<X>("x1");
	std::cout << "before scope\n";
	{
		auto aptr2 = std::shared_ptr<X>();
		aptr2 = std::move(aptr1);
		std::cout << "In scope count = " << aptr1.use_count() << '\n';
	}
	std::cout << "after scope\n";
	std::cout << "In scope count = " << aptr1.use_count() << '\n';
	
}
