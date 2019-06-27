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

int main() {
    long long n, m;
    std::cin >> n >> m;
	int period = get_period(m);
    std::cout << get_fibonacci_huge(n%period, m) << '\n';
}
