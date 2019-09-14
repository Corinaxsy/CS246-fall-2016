#ifndef ___GAME___H__
#define ___GAME___H__

class Player;

class Game{
	int min, max;
	int secret;
	int guesses = 1;
	Player* guesser;
 public:
	Game(int min = 1, int max = 100);
	~Game();

	void play();
};

#endif
