#ifndef __CAT__H_
#define __CAT__H_

#include <vector>
#include <string>

class Person{
  std::vector<Cat*> cats;
  std::string name;
 public:
  void adopt(Cat*);
  Person(std::string);

	void print();
};

#endif
