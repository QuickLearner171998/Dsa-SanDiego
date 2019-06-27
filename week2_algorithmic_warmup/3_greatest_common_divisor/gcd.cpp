#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd(int a, int b){
	if (b>a){
		int temp = a;
		a =b;
		b=temp;
	}
	if(b==0){
		return a;
	}
	int temp = b;
	b = a%b;
	a = temp;
	return gcd(a,b);
}
	

int main() {
  int a, b;
  std::cout<<"Enter two int a,b";
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;
  getchar();
  return 0;
}
