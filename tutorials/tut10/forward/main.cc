#include "cat.h"
#include "person.h"

using namespace std;

int main(){
	Person bob{"Bob"};

	Cat oreo{"Oreo"};
	Cat pixel{"Pixel"};
	Cat nougat{"Nougat"};

	bob.adopt(&oreo);
	bob.adopt(&pixel);
	bob.adopt(&nougat);

	bob.print();
}
