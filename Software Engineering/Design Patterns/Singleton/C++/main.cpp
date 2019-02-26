#include<iostream>

using namespace std;

class ExampleSingleton {
	
	static ExampleSingleton *singleton;
	static int counter;

	ExampleSingleton() {
		counter++;
	}
	
	public:
	
	static ExampleSingleton* getInstance() {
		if(singleton == NULL) {
			singleton = new ExampleSingleton();
		}
		return singleton;
	}
	
	void print() {
		cout << counter << " instances exist\n";
	}
};

int ExampleSingleton::counter = 0;
ExampleSingleton* ExampleSingleton::singleton = NULL;


int main() {
	
	ExampleSingleton *class1 = ExampleSingleton::getInstance();
	class1->print();

	ExampleSingleton *class2 = ExampleSingleton::getInstance();
	class2->print();

	ExampleSingleton *class3 = ExampleSingleton::getInstance();
	class3->print();
	
}

