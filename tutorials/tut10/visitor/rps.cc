#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Rock;
class Paper;
class Scissors;

class Form{
    public:
	virtual void attack(Form * f) = 0;
	virtual void defend(Rock & r) = 0;
	virtual void defend(Paper & p) = 0;
	virtual void defend(Scissors & s) = 0;
};

class Rock: public Form{
	void attack(Form * f){
		f->defend(*this);
	}
	void defend(Rock & r){
		cout << "Rock versus Rock: Tie." << endl;
	}
	void defend(Paper & p){
		cout << "Rock versus Paper: Win." << endl;
	}
	void defend(Scissors &s){
		cout << "Rock versus Scissors: Lose." << endl;
	}
};

class Paper: public Form{
	void attack(Form * f){
		f->defend(*this);
	}
	void defend(Rock & r){
		cout << "Paper versus Rock: Lose." << endl;
	}
	void defend(Paper & p){
		cout << "Paper versus Paper: Tie." << endl;
	}
	void defend(Scissors &s){
		cout << "Paper versus Scissors: Win." << endl;
	}
};

class Scissors: public Form{
	void attack(Form * f){
		f->defend(*this);
	}
	void defend(Rock & r){
		cout << "Scissors versus Rock: Win." << endl;
	}
	void defend(Paper & p){
		cout << "Scissors versus Paper: Lose." << endl;
	}
	void defend(Scissors &s){
		cout << "Scissors versus Scissors: Tie." << endl;
	}
};

int main(){
	srand(time(NULL));
	Form * me;
	cout << "Choose rock, paper or scissors" << endl;
	string choice;
	cin >> choice;

	if (choice == "rock") me = new Rock();
	else if (choice == "paper") me = new Paper();
	else me = new Scissors();

	Form * enemy;
	int enemyChoice = rand() % 3;
	if ( enemyChoice == 0 ) enemy = new Rock();
	else if ( enemyChoice == 1) enemy = new Paper();
	else enemy = new Scissors();

	me->attack(enemy);

	delete me;
	delete enemy;
}
