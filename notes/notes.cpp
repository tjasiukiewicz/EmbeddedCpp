
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

https://www.amazon.com/Advanced-Metaprogramming-Classic-Davide-Gennaro/dp/1484210115/ref=sr_1_1?crid=3679X3LJANPHI&keywords=metaprogramming+c%2B%2B+classic&qid=1656073897&sprefix=metaprogramming+c%2B%2B+classic%2Caps%2C169&sr=8-1
https://www.amazon.com/Template-Metaprogramming-Concepts-Techniques-Beyond/dp/0321227255/ref=pd_bxgy_img_sccl_1/133-2789568-3984402?pd_rd_w=8uu40&content-id=amzn1.sym.7757a8b5-874e-4a67-9d85-54ed32f01737&pf_rd_p=7757a8b5-874e-4a67-9d85-54ed32f01737&pf_rd_r=3XV31JVNSP8715J9W58Z&pd_rd_wg=SZX4d&pd_rd_r=e6932638-28d9-4009-a3ff-437fb46b2eb0&pd_rd_i=0321227255&psc=1
https://www.amazon.com/C-Templates-Complete-Guide-2nd/dp/0321714121/ref=pd_bxgy_img_sccl_2/133-2789568-3984402?pd_rd_w=JAqPb&content-id=amzn1.sym.7757a8b5-874e-4a67-9d85-54ed32f01737&pf_rd_p=7757a8b5-874e-4a67-9d85-54ed32f01737&pf_rd_r=HAFD686F95NS9RBTANGH&pd_rd_wg=wtRye&pd_rd_r=16214f85-8a31-4e07-9fa2-45706619d6bc&pd_rd_i=0321714121&psc=1
https://www.youtube.com/user/CppCon
https://www.youtube.com/watch?v=A8eCGOqgvH4
https://herbsutter.com/
https://www.youtube.com/watch?v=ZQFzMfHIxng
https://www.amazon.com/Large-Scale-Architecture-Addison-Wesley-Professional-Computing/dp/0201717069/ref=sr_1_1?crid=FWHYK7HCRHPW&keywords=big+architecture+c%2B%2B&qid=1656074489&sprefix=big+architecture+c%2B%2B%2Caps%2C184&sr=8-1
https://www.youtube.com/watch?v=QjFpKJ8Xx78
https://www.state-machine.com/
https://www.se-radio.net/
https://www.spreaker.com/user/semihalf/semihalf-001-backdoory-sprzetowe
https://www.infoq.com/
https://embeddedgurus.com/
https://accu.org/journals/nonmembers/overload_issue_members/
http://www.gii.upv.es/tlsf/


