#ifndef __K__H_
#define __K__H_

#include "A.h"
#include "B.h"
#include "C.h"
#include "D.h"
#include "E.h"
#include "F.h"
#include "G.h"
#include "H.h"
#include "I.h"
#include "J.h"
#include <iostream>

struct K: public A{
	B b;
	C* c;
	D& d;
	void foo(E);
	void foo(F*);
	void foo(G&);
	H func();
	I* func2();
	J& func3();
};

std::istream& operator<<(std::istream&, const K&);
#endif
