#include <iostream>
#include <sstream>
using namespace std;
/* this program makes change for any country’s
monetary system */
// require: all integers are positive
// time: O(n^2)


// sort(a,len) sort the array
// require: all integers are positive
// time: O(n^2)
void sort(int a[], int len);

// print(a,len,sum) print the combination of coins or Impossible
// time: O(n)
void print(int a[], int len, int sum);


// sort(a,len)
void sort(int a[], int len) {
 int i = 0;
 int pos = 0;
 while (i < len) {
  pos = i;
  int n = i;
  while (n < len) {
   if (a[pos] < a[n]) {
        pos = n;
   }
   ++n;
  }
  int temp = a[pos];
  a[pos] = a[i];
  a[i] = temp;
  ++i;
 }
}


// print(a,len,sum)
void print(int a[], int len, int sum) {
 int n=0,denom=0,num=0;
 int remainder = sum;
 while (n < len) { //check if it is impossible
  denom = a[n];
  remainder = remainder%denom;
  ++n;
 }
 if (remainder != 0) {
   cout << "Impossible" << endl;
   exit(0);
 }
 remainder = sum;
 n = 0;
 while (n < len) { // type
  denom = a[n];
  num = remainder/denom;
  remainder = remainder%denom;
  if (num != 0) {
    cout << num << " x " << denom << endl;
  }
  ++n;
 }
}

// main program
int main(int argc, char *argv[]) {
 switch(argc) { // check the number of anguments
  case 1 :
     cout << "Usage: change [denominations] [amount]" << endl;
     exit(0);
  case 2 :
     cout << "Usage: change [denominations] [amount]" << endl;
     exit(0);
 }
 int deno[argc - 2]; // make a array of demominations
 int i = 1;
 int m = 0;
 while (i <= (argc - 2)) { //extract denomination
  stringstream buffer1(argv[i]);
  int n;
  buffer1 >> n;
  deno[m]=n;
  ++i;
  ++m;
  }
  sort(deno,argc - 2); //sort the array of denominations
  int sum;
  stringstream buffer2(argv[argc-1]);
  buffer2 >> sum;
  print(deno, argc - 2, sum); //print the result
}
