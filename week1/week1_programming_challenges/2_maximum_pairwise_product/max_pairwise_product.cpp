#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::max;
using std::greater;

long long maxPairwiseProduct(std::vector<long long>& num) {
	sort(num.begin() , num.end() , greater<int>());
	long long product = num[1]*num[0];
	return product;
}

int main() {
    int n;
	// cout << "Number of entries";
	cin >> n;
	vector<long long> numbers(n);
	for (int i=0;i<n;i++) {
		cin >> numbers[i];
    }
    long long product = maxPairwiseProduct(numbers);
    std::cout << product << "\n";
    return 0;
}
