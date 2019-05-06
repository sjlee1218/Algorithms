#include <iostream>
using namespace std;
int main() {
    int remainder,a,b,c,d,sum;

    cin>> remainder;
    remainder= 1000- remainder;
    // 거스름돈이 remainder 743

    sum = remainder / 500; // sum=1
    a = remainder % 500; // a = 280

    sum += a/100; // sum=3
    b = a % 100; // b= 43

    sum += b/50; // sum = 7
    c = b%50;

    sum += c/10;
    d= c%10;

    sum += d / 5;
    sum += d%5;

    cout << sum<<endl;

    return 0;
}
