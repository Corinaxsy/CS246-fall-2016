#include <iostream>

using namespace std;

int main(){
		int x = 10, y = 5;

		int &rx = x;
		int &ry = y;

		int *px = &x;
		int *py = &y;

		int res1 = (*px + *py) * (*px - *py);
		int res2 = (rx + ry) * (rx - ry);

		cout << res1 << endl;
		cout << res2 << endl;
}
