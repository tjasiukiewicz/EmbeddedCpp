#include <iostream>

template<typename... Args>
void count_elements(Args... args) {
	std::cout << "Args counter = " << sizeof...(args) << '\n';
}

template<typename Arg>
void print_arguments(Arg arg) {
	std::cout << arg << '\n';
}

template<typename Arg, typename... Args>
void print_arguments(Arg arg, Args... args) {
	std::cout << arg << ", ";
	print_arguments(args...);
}

void printer(int&& value) {
	std::cout << "printer && value = " << value << '\n';

}

void printer(int& value) {
	std::cout << "printer & value = " << value << '\n';
}

template<typename Arg>
void use_printer(Arg arg) {
	printer(std::forward<Arg>(arg));
}

template<typename Arg>
void print_ints(Arg && arg) {
	printer(std::forward<Arg>(arg));
}

template<typename Arg, typename... Args>
void print_ints(Arg && arg, Args&&... args) {
	printer(std::forward<Arg>(arg));
	print_ints(std::forward<Args>(args)...);
}

int main() {
	count_elements(1, 2, "ala");	
	count_elements(12323.3);	

	print_arguments(5, 4334.2, "Tola");

	int a = 12;

	printer(std::move(a));

	use_printer(std::move(a));
	std::cout << "-----\n";

	a = 13;
	int b = 12;
	print_ints(a, b, std::move(a));
	//print_ints(b);
}
