#include <iostream>

using namespace std;
typedef long long ll;

ll arr[92][2]; // first index is the length
ll result[92];

ll Func(int N){
    if (result[N] != 0)
        return result[N];

    for(int i = 3; i <= N ; i++){
        arr[i][0] = arr[i-1][0] + arr[i-1][1];
        arr[i][1] = arr[i-1][0];
        result[i] = arr[i][0] + arr[i][1];
    }

    return result[N];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin>>N;

    // 어레이의 첫 번째 칸에는 맨 뒤가 0 인 애들의 개수, 두 번째 칸에는 맨 뒤가 1인 애들의 개수.
    arr[1][0] = 0;
    arr[1][1] = 1;
    result[1] = 1;

    arr[2][0] = 1;
    arr[2][1] = 0;
    result[2] = 1;

    ll temp = Func(N);
    cout<<temp;
}
