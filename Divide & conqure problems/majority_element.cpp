
/*
 * this is problem about getting a number that is repeated more than n/2 times where n: size of the array
 * this problem from :https://www.coursera.org/learn/algorithmic-toolbox/home/welcome
 * */
#include <bits/stdc++.h>
using namespace std;
int get_majority_element(vector<int> &a, int left, int right) {
  map<int, int >mp;
  for (int i=0; i<a.size() ;i++){
      mp[a[i]]++;
  }
  int max=INT32_MIN , index;
  for (auto it =mp.begin() ;it!=mp.end() ;it++){
      if (it->second > max){
          max=it->second;
          index=it->first;
      }
  }
  if (mp[index] > a.size()/2){
      return 1;
  }
  return 0 ;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << get_majority_element(a, 0, a.size()) << '\n';
}
