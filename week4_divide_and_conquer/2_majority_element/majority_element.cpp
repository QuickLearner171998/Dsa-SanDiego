#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  sort(a.begin(), a.end());
  int mid_ind = (right - left)/2 + left;
  int mid_ele = a[mid_ind];
  int count=0;
  for (int i=0;i<right;i++){
      if (a[i]==mid_ele) count++;
  }
  if (count>mid_ind) return 1;
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (int i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}