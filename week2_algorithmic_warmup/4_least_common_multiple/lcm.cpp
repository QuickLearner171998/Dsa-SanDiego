#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;

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

long long lcm(long long a, long long b){
	int gc_num = gcd(a,b);
	long long lc_num = (long long)(a*b)/gc_num ;
	return lc_num;
}
	
int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
