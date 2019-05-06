#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

char Func(char q, ll num){
    if (0x41 <=  q && q <= 0x5a){
        ll temp = q + num % 26;
        if (temp > 0x5a){
            int c = temp - 0x5a;
            return 0x41 +c -1;
        }
        return (char) temp;
    }
    else if (0x61 <= q && q <=0x7a){
        ll temp = q+ num % 26;
        if (temp > 0x7a){
            int c = temp - 0x7a;
            return 0x61 +c -1;
        }
        return (char)temp;
    }
    else{
        return q;
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    ll num, len;
    cin >> num >> len;

    string remainder;
    getline(cin, remainder);


    string s;
    getline(cin, s, '\n');

    for(int i = 0; i< len; i++) {
        char c = Func(s[i], num);
        cout<<c;
    }
}
