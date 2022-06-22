
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

