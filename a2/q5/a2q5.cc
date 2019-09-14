#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// invalidcheck(len,s) read length of s and s, and return if s is invalid
// time: O(n^2)
bool invalidcheck(int len,string s);

// checkstr(org,singput) read org string and sinput string to compare and 
// return the number of letters which are correct
// time O(n^2)
int checkstr(string org, string sinput);

bool invalidcheck(int len,string s) {
 if (len != 5) {
  return true;
 } else {
  int cpr1 = 0;
  int cpr2 = 0;
  while (cpr1 < len) {
   cpr2 = cpr1 + 1;
   while (cpr2 < len) {
    if (s[cpr1] == s[cpr2]) {
     return true;
    }
    ++cpr2;
   }
   ++cpr1;
  }
 }
 return false;
}

int checkstr(string org, string sinput) {
 int len = 5;
 int i = 0, n = 0, same = 0;
 while (i < len) {
  n = 0;
  while (n < len) {
   if (sinput[i] == org[n]) {
    ++same;
   }
   ++n;
  }
  ++i;
 }
 return same;
}


int main (int argc,char *argv[]) {
 if (argc != 2) {
  cerr << "usage: wordguess [filename]" << endl;
  exit(EXIT_FAILURE);
 }
 ifstream filetxt(argv[1]);
 if (!filetxt.is_open()) {
  cerr << argv[1] << " cannot be opened" << endl;
  exit(EXIT_FAILURE);
 }
 string i;
 filetxt >> i;
 filetxt.close();
 if (invalidcheck(i.length(),i)) {
  cerr << "the secret word is invalid" << endl;
  exit(EXIT_FAILURE);
 }
 string sinput;
 while(true) {
  cin >> sinput;
  if (cin.eof()) break;
  if (i == sinput) {
   cout << "you guessed correctly!" << endl;
   break;
  }
  if (invalidcheck(sinput.length(),sinput)) {
    cout << "invalid guess" << endl;
  } else {
    int same = checkstr(i,sinput);
    cout << same << " letters match" << endl;
  }
 }
}
