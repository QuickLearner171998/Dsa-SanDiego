#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x) {
  
  int left_ind = 0, right_ind = (int)a.size(); 
  int mid;
  while (right_ind > left_ind) {
        mid = (right_ind + left_ind) / 2;
        if (a[mid] == x) return mid;
        if (a[mid] > x) {
            // go left
            right_ind = mid;
        } else {
            left_ind = mid + 1;
        }
    }
    return -1;
}


int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
  getchar();
  return 0;
}
