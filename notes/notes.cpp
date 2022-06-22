
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

