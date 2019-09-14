#include "cat.h"

void Cat::addMinion(Person* p){
	minion = p;
}

Cat::Cat(std::string name): name{name} {}

void Cat::print(){
	cout << name << endl;
}
