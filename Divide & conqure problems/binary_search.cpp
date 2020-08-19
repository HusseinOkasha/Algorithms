#include <bits/stdc++.h>
using namespace std;
int binary_search(const vector<int> &a, int x) {
  int l = 0, r = (int)a.size()-1;
  int mid ;
  while (l<=r){
      mid= (l+r)/2;
      if (x > a[mid]){
          l=mid+1;
      }
      else if (x< a[mid]){
          r=mid-1;
      }
      else if(x==a[mid]){
          return mid ;
      }
  }
  return -1 ;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
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
}
