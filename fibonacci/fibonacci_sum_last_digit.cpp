#include <bits/stdc++.h>
using namespace std;

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}
int fibonacci_sum_fast(long long n) {
    int   a=0 , b=1 , temp    ;
    vector<int>v={0,1};
    long long  sum=1;
    if (n <= 1){
        return n;
    }
    for (long long i=2; i<60; i++ ) {
        temp = b ;
        b= (b+a)%10;
        a=temp;
        v.push_back(b%10);
        sum=(sum+b)%10;
    }
    long long  times = n /60;
    sum=(sum*times)%10;

    times = n%60;
    for(int i=0; i<=times ;i++ ){
        sum= (sum+v[i])%10;
    }

    return  sum;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
