#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>

// 3SAT 문제인 듯?
// (x | y | z) & (x | ~y | ~z) & ... 이런 거임.

using namespace std;
typedef long long ll;

vector< vector<int> > arr(1001, vector<int>(3, -1));
bool bool_arr[1001];
bool Bulb_arr[21]; // Bulb 는 1부터 시작해서, 20까지 있음.

int Func(int bit, int Bulb, int Clause){

    for(int i = 1; i<=Bulb;i++){
        int temp = bit & 1;
        Bulb_arr[i] = temp;
        bit = bit >>1;
    } // 어떤 전구를 키고 끌지 다 정함.

    int sum = 0;
    for(int i = 0; i < Clause ; i++){ // 이제, 각 clause 마다 따지는 거임.
        int temp = 0;
        int a = arr[i][0]; int b = arr[i][1]; int c = arr[i][2];

        temp |= (a > 0) ? Bulb_arr[a] : !Bulb_arr[-a];
        temp |= (b > 0) ? Bulb_arr[b] : !Bulb_arr[-b];
        temp |= (c > 0) ? Bulb_arr[c] : !Bulb_arr[-c];

        sum += temp;
    }

    return sum;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for(int _ = 0; _ <t; _++){
        int N,X;
        cin >> N >> X;

        for(int i = 0; i<X; i++){
            int a, b, c;
            cin >> a >> b >> c;
            arr[i][0] = a; arr[i][1] = b; arr[i][2] = c;
        }

        // bitmask 로 하자
        // 000000 -> 모든 전구 끄는거
        // 000001 -> 1번 전구 킴
        // 000010 -> 2번 전구 킴
        // 000011 -> 1, 2 번 전구 킴
        int ret = -1;
       for(int i = 1; i <= pow(2,N); i++) {
           ret = Func(i, N, X); // N 은 전구 개수. X 는 clause 의 갯수. ret == X 여야 함.
           if (ret == X)
               break;
       }
        // 2^N 의 경우의 수가 있는 거임
        if (ret == X)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
