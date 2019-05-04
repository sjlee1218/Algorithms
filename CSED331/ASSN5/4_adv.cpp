#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

// Bitonic Tour

pair<ll,ll> arr[303];
ll Tour[303][303]; // Tour[x][y]. x < y

ll Manhattan(const pair<ll, ll> a, const pair<ll, ll> b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

ll Patrol(int x_index, int y_index){ // x < y

    if (Tour[x_index][y_index] != -1)
        return Tour[x_index][y_index];

    // index 로 베이스 하나 더

    if (x_index < y_index -1){
        Tour[x_index][y_index] = Patrol(x_index, y_index -1) + Manhattan(arr[y_index - 1], arr[y_index]);
    }
    else{ // x_index == y_index -1. // 1,2 에서 안돌음.
        ll minimum = -1;

        for(int k=0; k<y_index-1; k++){
            ll temp = Patrol(k, x_index) + Manhattan(arr[k], arr[y_index]);
            minimum = (temp < minimum || minimum == -1) ? temp : minimum;
        }
        Tour[x_index][y_index] = minimum;
    }

    return Tour[x_index][y_index];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;

    for (int _=0; _<t;_++){
        int N;
        cin>>N;

        arr[0].first = 0; arr[0].second = 0;


        for(int i=1;i<=N;i++){
            cin>>arr[i].first >> arr[i].second;
        }


        sort(arr, arr+N+1);


        for(int i=0; i <= N; i++){
            for (int j=0; j <= N; j++){
                Tour[i][j] = -1;
            }
        }

        /*
        for(int i=0; i<=N ; i++)
            cout << "(" <<arr[i].first <<","<< arr[i].second<<") ";
        cout<<'\n';
         */

        Tour[0][1] = Manhattan(arr[0], arr[1]);

        ll result = -1;

        for (int k=0; k <= N; k++ ){
            ll temp = Patrol(k, N) + Manhattan(arr[k], arr[N]);
            result = (temp < result || result == -1) ? temp : result;
        }

        /*
        for(int i=0; i <= N; i++){
            for (int j=0; j <= N; j++){
                cout<<Tour[i][j]<<" ";
            }
            cout<<endl;
        }
        */

        cout << result << "\n";

    }
}
