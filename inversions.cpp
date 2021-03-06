#include <iostream>
#include <vector>

using std::vector;

long long merge(vector<int> &a, vector<int> &b, int left, int ave, int right) {
  int i = left, j = ave + 1, k = left;
  int inversion_count = 0;

  while(i <= ave && j <= right) {
    if(a[i] <= a[j]) {
      b[k++] = a[i++];
    }
    else {
      b[k++] = a[j++];
      inversion_count = inversion_count + ave - i + 1;
    }
  }

  while(i <= ave) {
    b[k++] = a[i++];
  }

  for(int i = left; i <= right; i++) {
    a[i] = b[i];
  }

  return inversion_count;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right == left) return 0;
  size_t ave = left + (right - left) / 2;
  
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave + 1, right);
  //write your code here

  number_of_inversions += merge(a, b, left, ave, right);
  
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b = a;
  
  std::cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
}
