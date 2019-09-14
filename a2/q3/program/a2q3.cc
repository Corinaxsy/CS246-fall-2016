#include <iostream>
#include <string>
using namespace std;


void printspace(int n) {
 int i=0;
 while (i<n) {
  cout << " ";
  ++i;
 }
}

string printword(string a) {
 string s;
 cout << a;
 while (cin >> s) {
 if ((s != ";") && (s != "{") && (s != "}") && (s != "//")) {
   cout << " " << s;
  } else {
   cout <<" ";
   break;
  }
 }
 return s;
}

string printspecialloop(int num) {
 string s;
 while (cin >> s) {
  if (s == ";") {
    printspace(num);
    cout << ";\n";
  } else if (s == "{") {
    printspace(num);
    ++num;
    cout << "{\n";
  } else if (s == "//") {
    printspace(num);
    cout << "// ";
    getline(cin,s,'\n');
    cout << s << "\n";
  } else if (s == "}") {
    --num;
    printspace(num);
    cout << "}\n";
  } else {
    printspace(num);
    break;
  }
 }
 return s;
}
 

int main() {
 string s;
 string a;
 a = s;
 int spacenum = 0;
 if (cin >> s) {

 while (true) {
  printword(a);
  if (s == ";") {
     cout << ";\n";
  } else if (s == "{") {
     ++spacenum;
     cout << "{\n";
  } else if (s == "//") {
     getline(cin,s,'\n');
     cout << s << "\n";
  } else if (s == "}") {
     cout << "\n";
     --spacenum;
     printspace(spacenum);
     cout << "}\n";
  }
  a = printspecialloop(spacenum);
  if (s == "") {
   break;
  }
 }
 }
 return 0;
}
