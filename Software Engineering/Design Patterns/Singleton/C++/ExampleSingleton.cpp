#include<iostream>

using namespace std;

ExampleSingleton::counter = 0;
ExampleSingleton::singleton = NULL:

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
