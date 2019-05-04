#include <iostream>
#include <math.h>
using namespace std;

int main() {
    long double rad;

    cin >> rad;

    cout << fixed;
    cout.precision(8);
    cout << rad*rad*M_PI<<endl;
    cout << rad*rad*2 << endl;
    return 0;
}
