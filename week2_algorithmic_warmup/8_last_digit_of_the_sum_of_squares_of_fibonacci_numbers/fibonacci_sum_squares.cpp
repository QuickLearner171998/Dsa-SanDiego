#include <iostream>
#include <vector>
using std::vector;
#include <iostream>

int get_fibonacci_last_digit(int n, int m) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
		// (A + B) mod C = (A mod C + B mod C) mod C
        current = tmp_previous % m + current %m ;
    }

    return current % m;
}

int get_period(long long m) {
	int count;
	int i =2;
	while(i){
		int x = get_fibonacci_last_digit(i,m);
		int y = get_fibonacci_last_digit(i+1,m);
		if (x==0 && y==1){
			count = i;
			break;
		}
		i++;
	}
	
	return count;
}

/* int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
} */
int fibonacci_sum_squares(int n) {
	int fn_last_digit ;
	fn_last_digit = get_fibonacci_last_digit(n,10);
	int fn_1_last_digit ;
	fn_1_last_digit = get_fibonacci_last_digit(n+1, 10);
	return (fn_last_digit*fn_1_last_digit)%10;
}


int main() {
    long long n = 0;
    std::cin >> n;
	int period = get_period(10);
    std::cout << fibonacci_sum_squares(n%period);
}

