#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void streamTest(istream& is, ostream& os){
	string word;
	while ( is >> word ){
		istringstream iss{word};
		int num;

		os << word << " is";
		if ( ! (iss >> num) || ! iss.eof() ){
			os << " not";
		}
		os << " an integer" << endl;
	}
}

int main(){
	ofstream fout{"streams.out"};
	ifstream fin{"streams.in"};
	
	streamTest(cin, fout);
	//streamTest(fin, cout);
}


