#include <iostream>
#include <iostream>
#include <vector>
#include<algorithm>
using std::vector;
using std::cin;
using std::cout;
using std::max;
using std::greater;

int get_fibonacci_last_digit_(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current ;
		// (A + B) mod C = (A mod C + B mod C) mod C
        current = (tmp_previous %10) + (current %10);
    }

    return current %10;
}

int get_period() {
	int count;
	int i =2;
	while(i){
		int x = get_fibonacci_last_digit_(i);
		int y = get_fibonacci_last_digit_(i+1);
		if (x==0 && y==1){
			count = i;
			break;
		}
		i++;
	}
	
	return count;
}

		

int main() {
    int n;
    std::cin >> n;
    int period = get_period();
	// cout << period << '\n' ;
	int last_dig = get_fibonacci_last_digit_((n%period));
	
    std::cout << last_dig << '\n';
	getchar();
	return 0;
    }
