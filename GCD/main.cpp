#include <bits/stdc++.h>
using namespace std;

int counter=0; // to illustrate how fast it's
int GCD(int x , int y ){
    counter++;
    if (y==0){
        return x ;
    }
    GCD(y,x%y);
}
int main() {
    cout << GCD(7,3) << endl ;
    cout << "Number of iterations: " << counter << endl ;
    return 0;
}
/*
    The idea is GCD (x,y) = GCD(y , x%y). by trying different numbers you will get it .
    Ok, how this is useful:
       by taking the mod every time you are reducing the numbers significantly.
       GCD(234,357) = GCD(357,234)= GCD(234,123) = GCD(123,111) = GCD(111,12) = GCD(12,3)
       =GCD(3,0)=3
       istead of going like 234 iteration only less than 10 iteration and we got the answer

 */