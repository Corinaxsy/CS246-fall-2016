int foo(int &x, const int& y){
	return x + y;
}

int main(){
  	int a = 42;
  	foo(a,a);
  	foo(a,43);
  	foo(43,a); // Invalid, what does it mean to change a literal?
  	foo(43,43); // As above
}
