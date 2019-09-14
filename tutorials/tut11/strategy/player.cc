#include "player.h"
#include <iostream>
#include <sstream>
#include <string>
#include "quit.h"

using namespace std;

// Player implmentation
Player::Player(int min, int max): min{min}, max{max} {}

void Player::update(int cmp){}

// Human implementation
Human::Human(int min, int max): Player{min,max} {}

int Human::guess(){
	int guess = 0;
	string word;
	cout << "Please input a guess between " << min << " and " << max << ": ";
	while ( true ){
		cin >> word;
		if ( cin.eof() ) {
			cin.clear(); cin.ignore();
			throw Quit{};
		}
		istringstream iss{word};
		if ( iss >> guess ) {
			if ( guess >= min && guess <= max ) break;
			else cout << "Your guess must be between " << min << " and " << max 
								<< "." << endl;
		}
		cout << "Your guess must be an integer." << endl;
		cin.clear(); cin.ignore();
	}
	return guess;
}

// Easy AI implementation
Easy::Easy(int min, int max): Player{min,max} {}

int Easy::guess(){
	return rand()%(max-min+1) + min;
}

// Hard AI implementation
Hard::Hard(int min, int max): Player{min,max}, max_possible{max}, 
	min_possible{min} {}

int Hard::guess(){
	prevGuess = (max_possible + min_possible) / 2;
	return prevGuess;
}

void Hard::update(int cmp){
	if ( cmp > 0 ) max_possible = prevGuess-1;
	if ( cmp < 0 ) min_possible = prevGuess+1;
}
