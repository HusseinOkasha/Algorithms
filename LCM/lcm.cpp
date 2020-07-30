#include <bits/stdc++.h>
using namespace std;
int gcd_fast(int a , int b){
    if (b==0){
        return a ;
    }
    gcd_fast(b ,a%b );

}
long long lcm_fast(int a, int b) {
    int gcd=gcd_fast(a,b);
  if ( gcd==1){
      return (long long) a * b;
  }
  long long ans = (long long)max(a,b)/gcd*min(a,b);
  return ans;

}
int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}


