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

void print(string olds, string news,int num) {
 if (cin >> news) { //check it can cin string
  if ((olds != ";") && (olds != "{")  //check if oldstring is special(not)
      && (olds != "}") && (olds != "//")) {
    if (news != "}") {
         cout << olds << " ";
    } else { // "}"
        cout << olds << "\n";
        --num;
        printspace(num);
    }
  } else { //oldstring special
     if (olds == ";") {
          cout << ";\n";
          if (news == "}") { 
           --num;
           printspace(num);
          } else {
           printspace(num);
          }
      } else if (olds == "{") {
          cout << "{\n";
          ++num;
          if (news == "}") { 
           --num;
           printspace(num);
          } else {
           printspace(num);
          }
      } else if (olds == "//") {
          cout << "// ";
          string s;
          getline(cin,s,'\n');
          cout << news << s << "\n";
          if (news == "}") { 
           --num;
           printspace(num);
          } else {
           printspace(num);
          }
          if (cin >> news) {
            print(news,news,num);
          }
      } else {
          cout << "}\n";
          if (news == "}") { 
           --num;
           printspace(num);
          } else {
           printspace(num);
          }
      }
  }
  print(news,news,num);
 } else {
    cout << olds << endl;
    exit(EXIT_SUCCESS);
 }
}
int main() {
 string i;
 string s;
 if (cin >> i) {
  print(i,s,0);
 }
}
 
