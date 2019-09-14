#include <iostream>
#include <string>

using namespace std;

struct Animal{
  virtual bool fly() const { return false; }
};

struct Cat: public Animal{
};

struct NyanCat: public Cat{
  bool fly() const override { return true; }
};

struct Bird: public Animal{
  bool fly() const override { return true; }
};

struct Penguin: public Bird{
  bool fly() const override { return false; }
};

int main(){
	cout << boolalpha;

	Cat cat;
	NyanCat nCat;

	Bird bird;
	Penguin penguin;

	string junk;

	cout << "nyan cat through Animal object. Can it fly?" << endl;
	Animal animal = nCat;
	cin >> junk;
	cout << animal.fly() << endl;


	cout << "nyan cat through Animal pointer. Can it fly?" << endl;
	Animal* animalPoint = &nCat;
	cin >> junk;
	cout << animalPoint->fly() << endl;

	cout << "nyan cat through Animal reference. Can it fly?" << endl;
	Animal& animalPoint = nCat;
	cin >> junk;
	cout << animalPoint.fly() << endl;
	
	cout << "Penguin through Animal reference. Can it fly?" << endl;
	Animal& pen1 = penguin;
	cin >> junk;
	cout << pen1.fly() << endl;

	cout << "Penguin through Animal reference. Can it fly?" << endl;
	Animal& pen1 = penguin;
	cin >> junk;
	cout << pen1.fly() << endl;

	cout << "Penguin through Bird object. Can it fly?" << endl;
	Bird pen2 = penguin;
	cin >> junk;
	cout << pen2.fly() << endl;
}
