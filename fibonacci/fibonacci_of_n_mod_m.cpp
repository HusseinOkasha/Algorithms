#include <bits/stdc++.h>
using namespace std;

/*
   the problem is to find f(n)%m where 0<= n <= 100000000000000.
   the idea of the solution is that f(n)%m is a periodic function.
   visit this : https://en.wikipedia.org/wiki/Pisano_period for more info.

 */


long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}
long long unsigned fibonacci_fast(long long unsigned  n , int m ) {
    long long unsigned temp , a=0 , b=1 ;
    if (n<2){
        return n ;
    }
    for(int i=2 ; i<=n ;i++ ){
        temp = b ;
        b=(b+a)%m;
        a=temp;
    }
    return b;
}

long long unsigned  get_fibonacci_huge_fast (long long unsigned n  , int  m ){


    long long unsigned   a=1 , b=1 , temp , period=3 , pre=0 , current=1 ;
    for (long long i=3; i<= m*m; i++ ){
        temp = b ;
        b=(b+a)%m;
        a=temp;
        pre=current, current= b%m;

        if (pre==0 && current ==1 ){

            period-=1;
            break;
        }
        period++;
    }

    int index=n%period;

    return fibonacci_fast(index , m);

}


int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}


