#include "person.h"
#include "cat.h"
#include <iostream>

using namespace std;

void Person::adopt(Cat *c){
	cats.emplace_back(c);
	v->addMinion(this);
}

Person::Person(std::string name): name{name} {}

void Perons::print(){
	cout << name << " has " << cats.size() << " cats." << endl;
	cout << "Their names are: ";
	for ( auto cat: cats ){
		cat->print();
	}
}
