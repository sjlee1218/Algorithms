#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

ll stair_arr[302];
ll dp_arr[302][2][2];


ll Stair(int index, int cur, int before){
    if (index < 0) // - MAX 해야하나? 불가능 한 거니까
        return -40000000;
    // cur 과 before 는. 0 -> 1칸 만에 온거. 1 -> 2칸 뛰어서 온 거

    if (dp_arr[index][cur][before] != 0)
        return dp_arr[index][cur][before];

    if (!cur && !before){ // 1칸 1칸
        dp_arr[index][0][0] = 0;
    }
    else{ // 2칸 2칸
        dp_arr[index][cur][before] = max(Stair(index-cur-1,1,cur), Stair(index-cur-1,0,cur)) + stair_arr[index];
    }

    return dp_arr[index][cur][before];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin>>N;

    for (int i=0; i< N; i++)
        cin >> stair_arr[i];

    dp_arr[0][0][0] = stair_arr[0];
    dp_arr[0][0][1] = stair_arr[0];
    if (N>1) {
        dp_arr[1][1][0] = stair_arr[1];
        dp_arr[1][1][0] = stair_arr[1];
    }

    ll result2 = Stair(N-1,1,0);
    ll result3 = Stair(N-1,0,1);
    ll result4 = Stair(N-1,1,1);

    ll temp = max(result2, result3);
    ll temp1 = max(temp, result4);

    cout<< temp1;

}
