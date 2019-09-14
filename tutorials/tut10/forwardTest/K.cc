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
#include "K.h"

void K::foo(E e){}

void K::foo(F* f){}

void K::foo(G& g){}

H K::func(){
	return H();
}

I* K::func2(){
	return new I();
}

J& K::func3(){
	return *(new J());	
}

std::ostream& operator<<(std::ostream& out, const K& k){
	out << k.c << " " << k.b.c << " " << k.c->c << " " << k.d.c;
	return out;
}
