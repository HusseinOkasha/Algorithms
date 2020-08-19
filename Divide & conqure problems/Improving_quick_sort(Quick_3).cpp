
/*
 * this problem is about improving Quick sort to work effcient with arrays containing few unique elements
 * it's from : https://www.coursera.org/learn/algorithmic-toolbox/home/welcome
 *
 * */
#include <bits/stdc++.h>
using namespace std;

pair<int , int > partition3(vector<int> &a, int l, int r){
    int x = a[l];
    int j = l-1;
    int m=l;
    bool check=true;
    // i : keeps track of the end of  partion that has elements greater than x.
    // j : keeps track of the end of the partion that has elements equal or lessthan x.
    for (int i = l + 1; i <= r; i++) {
        if (a[i] < x) {
            int y=a[i];
            a.erase(a.begin()+i);
            a.insert(a.begin()+j+1,y);
            j++;
            m++;
        }
        else if (a[i]==x){
            swap(a[m+1],a[i]);
            m++;
        }
    }
    //swap(a[l], a[j]);
    return make_pair(j,m);
}
int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  // i : keeps track of the end of  partion that has elements greater than x.
  // j : keeps track of the end of the partion that has elements equal or lessthan x.
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  // to have balanced partations so we keep complexity nlogn instead of n^2.
  swap(a[l], a[k]);
  pair<int, int > index = partition3(a, l, r);
  if (index.first>0){
      randomized_quick_sort(a, l,index.first);
  }
  randomized_quick_sort(a, index.second+1, r);

}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
