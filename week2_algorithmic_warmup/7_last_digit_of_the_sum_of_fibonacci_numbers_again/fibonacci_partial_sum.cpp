#include <iostream>
#include <vector>
using std::vector;
#include <iostream>

int get_fibonacci_huge(long long n, long long m) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
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
		int x = get_fibonacci_huge(i,m);
		int y = get_fibonacci_huge(i+1,m);
		if (x==0 && y==1){
			count = i;
			break;
		}
		i++;
	}
	
	return count;
}
long long get_fibonacci_partial_sum(long long from, long long to) {
    int sum = 0;

    int current ;
    

    for (long long i = from; i <= to; ++i) {
		current = get_fibonacci_huge(i,10);
		// (A + B) mod C = (A mod C + B mod C) mod C
        sum = (sum % 10 + current)%10 ;
    }
    return sum ;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
	int period = get_period(10);
    std::cout << get_fibonacci_partial_sum(from%period, to%period) << '\n';
}
