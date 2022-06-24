#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

template<typename T>
struct Instances {
	Instances() {
		Instances<T>::instances.push_back(static_cast<T*>(this));
	}

	static std::vector<T*> get_instances() {
		return Instances<T>::instances;
	}

	~Instances() {
		auto & inst = Instances<T>::instances;
		inst.erase(std::remove(inst.begin(), inst.end(), this), inst.end());
	}
private:
	static std::vector<T*> instances;
};

template<typename T>
std::vector<T*> Instances<T>::instances;

/*
template<typename... Types>
struct Airplane : public Types... {
};

auto a = Airplane<Type1, Type2, Type3>("Wrona");
*/

struct Airplane : public Instances<Airplane> {
	Airplane(const std::string& name)
		: name{name} {
	}

	const std::string & get_name() const {
		return name;
	}

private:
	std::string name;
};

int main() {
	auto a1 = Airplane("F16");
	auto a2 = Airplane("F22");
	auto a3 = Airplane("DC8");

	for (const auto & a: {&a1, &a2, &a3}) {
		std::cout << a->get_name() << '\n';
	}
	
	std::cout << "-------\n";

	for (const auto & a: Airplane::get_instances()) {
		std::cout << a->get_name() << '\n';
	}

	std::cout << "-------\n";

	for (const auto & a: Instances<Airplane>::get_instances()) {
		std::cout << a->get_name() << '\n';
	}

	{
		auto a3 = Airplane("SZD Pirat");
	}

	std::cout << "-------\n";

	for (const auto & a: a1.get_instances()) {
		std::cout << a->get_name() << '\n';
	}

}
