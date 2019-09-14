#include <iostream>
using namespace std;

struct IntArray {
  int size;
  int capacity;
  int *contents;
};


// readIntArray() read the ints and put them into array,return an IntArray
// effect: allocates heap for array
// time: O(n)
IntArray readIntArray();

// addToIntArray(intary)read original array and  add ints into array
// effect: allocates heap for array
// time: O(n)
void addToIntArray(IntArray& intary);

//printIntArray(a) print the item of the array
void printIntArray(const IntArray& a);

//copyary(size,oldar[],newar[]) coty the item of oldar to newar
// effect: delete oldar[]
// time: O(n)
void copyary(int size,int oldar[], int newar[]);

// Do not change this function!

int main() {  // Test harness for IntArray functions.
  bool done = false;
  IntArray a[4];
  a[0].contents = a[1].contents = a[2].contents = a[3].contents = 0;

  while(!done) {
    char c;
    char which;

    // Note:  prompt prints to stderr, so it should not occur in .out files
    cerr << "Command?" << endl;  // Valid commands:  ra, rb, rc, rd,
                                 //                  +a, +b, +c, +d,
                                 //                  pa, pb, pc, pd, q
    cin >> c;  // Reads r, +, p, or q
    if (cin.eof()) break;
    switch(c) {
      case 'r':
        cin >> which;  // Reads a, b, c, or d
        delete [] a[which-'a'].contents;
        a[which-'a'].contents = 0;
        a[which-'a'] = readIntArray();
        break;
      case '+':
        cin >> which;  // Reads a, b, c, or d
        addToIntArray(a[which-'a']);
        break;
      case 'p':
        cin >> which;  // Reads a, b, c, or d
        printIntArray(a[which-'a']);
        cout << "Capacity: " << a[which-'a'].capacity << endl;
        break;
      case 'q':
        done = true;
    }
  }

  for (int i = 0; i < 4; ++i) delete [] a[i].contents;
}

void copyary(int size,int oldar[], int newar[]) {
 int n = 0;
 while (n < size) {
  newar[n] = oldar[n];
  ++n;
 }
 delete [] oldar;
}


IntArray readIntArray() {
 int i;
 IntArray intary;
 intary.size = 0;
 intary.capacity = 0;
 intary.contents = new int[intary.capacity];
 while (true) {
  cin >> i;
  if (cin.fail()) { // check if cin successfully
     if (cin.eof()) break;
     cin.clear();
     cin.ignore();
     break;
  } else {
    if (intary.capacity == 0) { // if capacity isn't enouph, allocate new
        intary.capacity = 5;
        delete [] intary.contents;
        intary.contents = new int[intary.capacity];
    } else if (intary.size >= intary.capacity) {
        intary.capacity *= 2;
        int *newintary = new int[intary.capacity];
        copyary(intary.size,intary.contents,newintary);
        intary.contents = newintary;
    }
    int *ary = intary.contents;
    ary[intary.size] = i;
    ++(intary.size);
  }
 }
 return intary;
}

void addToIntArray(IntArray &intary) {
 int i;
 while (true) {
  cin >> i;
  if (cin.fail()) {
     if (cin.eof()) break;
     cin.clear();
     cin.ignore();
     break;
  } else {
    if (intary.capacity == 0) {
        intary.capacity = 5;
        delete [] intary.contents;
        intary.contents = new int[intary.capacity];
    } else if (intary.size >= intary.capacity) {
        intary.capacity *= 2;
        int *newintary = new int[intary.capacity];
        copyary(intary.size,intary.contents,newintary);
        intary.contents = newintary;
    }
    int *ary = intary.contents;
    ary[intary.size] = i;
    ++(intary.size);
  }
 }
}

void printIntArray(const IntArray &a) {
 int *printar = a.contents;
 int i = 0;
 int size = a.size;
 while (i < size) {
  cout << printar[i] << " ";
  ++i;
 }
 cout << "\n";
}
