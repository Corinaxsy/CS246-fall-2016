#ifndef __CAT__H_
#define __CAT__H_

#include <string>

class Cat{
  Person* minion;
  std::string name;
 public:
  void addMinion(Person*);
  Cat(std::string);
	void print();
};
#endif
