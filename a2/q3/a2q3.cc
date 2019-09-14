#include <iostream>
#include <string>
using namespace std;
// the program takes program source code as input and outputs the same code,
//   nicely formatted for readability

// printspace(n) print n spaces
// required: n is non-negative
// effect : print n spaces
// time: O(n)
void printspace(int n);

// print(olds,news,num) read oldstring,newstring and the number of spaces
//  to print the nicely formatted code
// effect: print the nicely formatted code
// time: O(n)
void print(string olds, string news,int num);

//printspace(n)
void printspace(int n) {
 int i=0;
 while (i<n) {
  cout << " ";
  ++i;
 }
}

// print(olds,news,num)
void print(string olds, string news,int num) {
 while (true) {
  if (cin >> news) { //check it can cin string
   if ((olds != ";") && (olds != "{")  //check if oldstring is special(not)
      && (olds != "}") && (olds != "//")) {
    if (news != "}") {
         cout << olds << " ";
    } else { // "}"
        cout << olds << "\n";
        --num;
        if (num < 0) {
         num = 0;
         printspace(num);
        } else {
         printspace(num);
        }
    }
   } else { //oldstring special
     if (olds == ";") {
          cout << ";\n";
          if (news == "}") { 
           --num;
           if (num < 0) {
            num = 0;
            printspace(num);
           } else {
            printspace(num);
           }
          } else {
           printspace(num);
          }
      } else if (olds == "{") {
          cout << "{\n";
          ++num;
          if (news == "}") { 
           --num;
           if (num < 0) {
            num = 0;
            printspace(num);
           } else {
            printspace(num);
           }
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
           if (num < 0) {
            num = 0;
            printspace(num);
           } else {
            printspace(num);
           }
          } else {
           printspace(num);
          }
          if (cin >> news) {
            olds = news;
          } else {
           break;
          }
      } else {
          cout << "}\n";
          if (news == "}") { 
           --num;
           if (num < 0) {
            num = 0;
            printspace(num);
           } else {
            printspace(num);
           }
          } else {
           printspace(num);
          }
      }
   }
  } else {
    cout << olds << endl;
    break;
  }
 olds = news;
 }
}


//main
int main() {
 string i;
 string s;
 if (cin >> i) {
  print(i,s,0);
 }
}
 
