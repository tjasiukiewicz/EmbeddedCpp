
// W pliku foo.cpp jest
// static MyClass myClass = MyClass(); < MyClass potrzebuje w kontstrukcji xClass typu XClass

static XClass xClass = XClass();
// Konstrukcja może się nie powieść: Static Initialization Fiasco.


static int counter; 

int foo() {
	static int data = 12;
	++data;
	return data;
}


// C 
// int main(int agv, char ** args) { .. 
// C: int main() <- wiele argumentów
//int main(void) {
int main() {
//	return 0;
//	foo(); // <- dla C ma sygnaturę int foo(...) 
}


// cppisights
#include <cstdio>
#include <functional> // std::function<ReturnType(Arg1, Arg2, ... )>


void foo(int a) {
	//
}

struct X {
	void operator()(int) {
    }
};


void runner(std::function<void(int)> fun, int arg) {
	fun(arg);
}

int main()
{
	auto f1 = [](int a) { printf("%d\n", a); };
 	auto f2 = [](int a) { printf("%d\n", a); };
    // Nie mogę tego zrobić. To inne typy danych!
    //f1 = f2;
  
  	std::function<void(int)> f3 = [](int a) { printf("%d\n", a); };
    auto f4 = [](int a) { printf("%d\n", a); };
    f3 = f4;
    f3 = foo;
    X x = X();
    f3 = x;
    
    std::function<void(int)> funct_table[] = { x, foo, f1, f2};
  
    funct_table[0] = foo;
 
  	for (const auto & fun: funct_table) {
      runner(fun, 433);
    }
    
}

// godbolt
#include <functional>

int foo(int) {
    return 100;
}

int main() {
    std::function<int(int)> f1 = [](int a){ return a;};
    auto f2 = [](int a){ return a + 2;};
    f1 = foo;
    f1 = f2;
    return f1(42) + f2(33);
}


// constexpr goodbolt
#include <cstdint>

#define HZ 1000000

constexpr uint16_t rs_baud(unsigned speed) {
    // C++11 tylko wyrażenia
    return HZ < 500000 ? speed * HZ/1000 + 100: HZ/1000 * speed + 500;
    /* C++14 i nowszy
    if (HZ < 500000) {
        return speed * HZ/1000 + 100;
    }
    return HZ/1000 * speed + 500;
    */
}

int main() {
    const uint16_t bauds = rs_baud(9600);
    const auto b2 = rs_baud(13);
    return bauds + b2;
}

// Links...
//
https://isocpp.org/
https://herbsutter.com/
https://en.cppreference.com/w/cpp/language/attributes/nodiscard
https://en.cppreference.com/w/cpp/language/attributes
https://en.cppreference.com/w/cpp/utility/tuple
https://en.m.wikibooks.org/wiki/More_C%252B%252B_Idioms/Curiously_Recurring_Template_Pattern
https://github.com/kvasir-io/Kvasir
https://www.boost.org/doc/libs/1_64_0/libs/msm/doc/HTML/index.html
https://www.boost.org/doc/libs/1_79_0/libs/statechart/doc/index.html
