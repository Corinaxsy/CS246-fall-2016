#include <iostream>

using namespace std;

int main(){
  int arr[3][7];

  arr[1][1] = 7;

  cout << arr[1][1] << endl;

  // 2d array
  int** arr2;

  int n, m;
  cin >> n >> m;

  arr2 = new int*[n];
  for ( int i = 0; i < n ; ++i){
    arr2[i] = new int[i];
    for ( int j = 0; j < i; ++j){
      arr2[i][j] = i * j;
    }
  }
  
  for ( int i = 0; i < n ; ++i){
    for ( int j = 0; j < i; ++j){
      cout << arr2[i][j] << " ";
    }
    cout << endl;
  }



  for ( int i = 0; i < n; ++i){
    delete[] arr2[i]; 
  }
  delete[] arr2;
}
