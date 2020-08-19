
/*
 * Finding number of pair in array a where a[i] > a[j] and i < j
 * this problem is from : https://www.coursera.org/learn/algorithmic-toolbox/home/welcome
 * */
#include <bits/stdc++.h>
using namespace std;

int  merge(int a[] , int l ,int mid, int  h , const int &size ){
    int i=l ,j=mid+1, k=l;
    int b[size];
    int counter=0 , size_left=mid+1-i ;

    while (i<mid+1 && j<=h){
        if(a[i] <= a[j]){
            b[k]=a[i];
            i++;

        }
        else{
            b[k]=a[j];
            j++;
            counter+=size_left;
        }
        size_left=mid+1-i;
        k++;
    }
    while(i<mid+1){
        b[k]=a[i];
        i++;
        k++;
    }
    while (j<=h){
        b[k]=a[j];
        j++;
        k++;
    }
    for (int f=l; f<=h ;f++){
        a[f]=b[f];
    }
    return counter;

}
int merge_sort(int a[] , int l , int h , const int& size){
    int counter=0;
    if (l<h) {
        int mid =(l+h)/2;
        counter+=merge_sort(a, l, mid, size);
        counter+=merge_sort(a, mid+1, h , size);
        counter+=merge(a,l, mid,h , size);
    }
   return counter;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  int a[n];
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  //vector<int> b(a.size());
  std::cout << merge_sort(a,0,n-1,n) << '\n';


  return 0;
}
