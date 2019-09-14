#include "game.h"
#include <cstdlib>
#include "player.h"
#include <iostream>
#include "quit.h"

using namespace std;

Game::Game(int min, int max): min(min), max(max) {
	secret = rand()%(max-min+1) + min;
	while ( true ){
			cout << "Choose the player: (p, e, h)" << endl;
			char player;
			cin >> player;
			if ( player == 'p' ) guesser = new Human(min,max);
			else if ( player == 'e' ) guesser = new Easy(min,max);
			else if ( player == 'h' ) guesser = new Hard(min,max);
			else continue;
		break;
	}
}

void Game::play(){
	while ( true ){
		int guess = 5;
		try {
			guess = guesser->guess();
		} catch ( Quit& q ) {
			delete guesser;
			guesser = new Hard(min,max);
			guess = guesser->guess();
		}
		if ( guess == secret ) {
			cout << guess << " is the secret number. You win." << endl;
			cout << "You guessed in " << guesses << " guesses." << endl;
			break;
		} else if ( guess < secret ){
			cout << guess << " is lower than the secret number." << endl;
			guesser->update(-1);
		} else {
			cout << guess << " is higher than the secret number." << endl;
			guesser->update(1);
		}
		++guesses;
	}
}

Game::~Game(){
	delete guesser;
}
