#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll Sum_arr[3001][3001];
int origin_arr[3001][3001];
ll Conv_arr[3001][3001];

ll Find_Sum(int n,int m){
    if (n<0 || m<0)
        return 0;

    if(n==0 && m ==0) {
        Sum_arr[0][0] = origin_arr[0][0];
        return origin_arr[0][0];
    }

    if (Sum_arr[n][m] != 0)
        return Sum_arr[n][m];

    ll sum1 = Find_Sum(n-1,m);
    ll sum2 = Find_Sum(n,m-1);
    ll sub = Find_Sum(n-1,m-1);

    Sum_arr[n][m] = sum1 + sum2 - sub + origin_arr[n][m];
    return Sum_arr[n][m];
}

ll Conv(int y1, int x1, int y2, int x2){
    if (!x1 && !y1){
        return Sum_arr[y2][x2];
    }
    else if (x1 && !y1){
        return Sum_arr[y2][x2] - Sum_arr[y2][x1-1];
    }
    else if (!x1 && y1){
        return Sum_arr[y2][x2] - Sum_arr[y1-1][x2];
    }
    else
        return Sum_arr[y2][x2] - Sum_arr[y2][x1-1] - Sum_arr[y1-1][x2] + Sum_arr[y1-1][x1-1];
    //Conv_arr[i][j] = Sum_arr[i+D-1][j+D-1] - Sum_arr[i-1][j+D-1] - Sum_arr[i+D-1][j-1] + Sum_arr[i-1][j-1]
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;

    for(int _=0;_<t;_++) {
        int N, M, D;
        cin >> N >> M >> D;


        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++){
                cin>>origin_arr[i][j];
                Sum_arr[i][j]=0;
                Conv_arr[i][j]=0;
            }
        }

        ll temp = Find_Sum(N - 1, M - 1);

        for (int i = 0; i < N - D + 1; i++) { // y
            for (int j = 0; j < M - D + 1; j++) { // j == x
                Conv_arr[i][j] = Conv(i, j, i+D-1, j+D-1);
                cout<<Conv_arr[i][j]<<" ";
            }
            cout<<'\n';
        }

    }

    return 0;
}
