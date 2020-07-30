#include <iostream>
#include <vector>
using namespace std;


long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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
long long get_fibonacci_partial_sum_fast(long long from , long long to ){
    int x , y ;
    if(from==to){
        int a=0 , b=1 , temp ,sum=0 ;
        vector<int>v{0,1};
        for (long long i=2; i<60; i++ ) {
            temp = b ;
            b= (b+a)%10;
            a=temp;
            v.push_back(b%10);
            sum=(sum+b)%10;
        }
        return v[from%60];

    }
    if (from==0){
        y=fibonacci_sum_fast(to);
        y%=10;
        return y ;
    }
    else{
         x=fibonacci_sum_fast(from-1);
         y=fibonacci_sum_fast(to);
        if (x > y){
            y+=10;
        }
    }



   return (y-x)%10;

}


int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}

