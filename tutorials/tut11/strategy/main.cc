#include "game.h"
#include <cstdlib>
#include <ctime>

int main(){
	srand(time(NULL));
	Game g(1, 100);
	g.play();
}
