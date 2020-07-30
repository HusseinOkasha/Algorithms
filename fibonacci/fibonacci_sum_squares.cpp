#include <bits/stdc++.h>
using namespace std;

/*
    problem is to find last digit of summation of the square of n fibonacci numbers.
*/

/*
    the idea is that summation of square of the nth fibonacci numbers = fib(n)*fib(n+1).

 */
int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}
int fibonacci_sum_squares_fast(long long n) {
    int fib_current=1 , fib_pre=0  , fib_temp;
    int square_current=1 , square_pre=0 , square_temp;
    int sum=0;
    if (n < 2 ){
        return (int)n ;
    }
    for (int i=0; i<= n ;i++){
        fib_temp=fib_current;
        fib_current= (fib_current+fib_temp)%10;
        fib_pre=fib_temp;
        square_temp=square_current;
        square_current=(fib_current*fib_current)%10;
        square_pre=square_temp;
        sum= (sum+square_current)%10;

    }
    return sum;
}

int fibonacci_sum_squares_supper_fast(long long n){
     int a=0 , b=1 , temp ;
     vector<int>v{0,1};
     for (int i=2 ; i<60 ; i++){
          temp=b;
          b=(b+a)%10;
          a=temp;
          v.push_back(b);
     }
     int ans=v[n%60]*v[(n+1)%60];
     ans%=10;
     return ans;

}


int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_supper_fast(n);
}
