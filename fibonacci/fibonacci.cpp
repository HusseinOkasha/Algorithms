
//the problem is to get fib(n) where n<=45.

#include <bits/stdc++.h>
using namespace std;

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
    int temp , a=0 , b=1 ;
    if (n<2){
        return n ;
    }
    for(int i=2 ; i<=n ;i++ ){
        temp = b ;
        b=b+a;
        a=temp;
    }
    return b;
}


int main() {

    int n ;
    cin >> n;
    cout << fibonacci_fast(n);

    return 0;
}
