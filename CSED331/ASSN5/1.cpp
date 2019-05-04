#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

ll original_arr[3002][3002];
ll memo[3002][3002][2];
int N, M;
ll MINLL = -9e12-1;

long long Func(int row_index, int col_index, int dir){
    // direction : -> 0, <- +1

    // base case 0,0
    // row 와 col 중 하나가 0 일 경우
    // rowindex가 N-1 인 경우, colindex 가 M-1 인 경우.
    if (row_index == 0 && col_index == 0)
        return memo[0][0][dir];

    if (row_index < 0 || row_index > N-1 || col_index < 0 || col_index > M-1)
        return MINLL;

    if (memo[row_index][col_index][dir] != MINLL)
        return memo[row_index][col_index][dir];

    ll origin = original_arr[row_index][col_index];

    ll result1 = origin + Func(row_index-1, col_index,1);
    ll result2 = origin + Func(row_index-1, col_index,0);
    ll result3;
    if (dir)
        result3 = origin + Func(row_index, col_index+1, 1);
    else
        result3 = origin + Func(row_index, col_index-1, 0);

    ll temp = (result1 < result2) ? result2 : result1;
    ll temp1 = (result3 < temp) ? temp : result3;

    memo[row_index][col_index][dir] = temp1;
    return temp1;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;

    for(int _=0; _<t; _++){
        cin>>N>>M;

        for (int __=0; __<N ;__++) {
            for (int k = 0; k < M; k++) {
                cin >> original_arr[__][k];
                memo[__][k][0] = MINLL;
                memo[__][k][1] = MINLL;
            }
        }

        memo[0][0][0] = original_arr[0][0];
        memo[0][0][1] = original_arr[0][0];

        /*
        for(int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++)
                cout << Func(i, j, 0) << ' ';
            cout << '\n';
        }
        cout<<endl;
         */

        cout<< Func(N-1, M-1, 0)<<'\n';
    }

    return 0;
}
