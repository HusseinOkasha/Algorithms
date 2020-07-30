
// the problem is to get thr last digit of large fibonacci number
// 0<= n <= 10000000

/*
    the idea is that you can't find data type that can store fib(10000000)
    then you take %10 of it .
    and also we aren't intersted in the whole number . all we need is the last digit.
    so we can say that last digit of fib(2) = fib(1)%10 +fib(0)%10.

 */
#include <iostream>
using namespace std;
int get_fibonacci_last_digit_fast(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
    }

    return current ;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
}
