#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

vector<vector<ll> > arr(102, vector<ll>(102, 100000000));

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    int s, d, w;
    for(int i=0; i< M; i++){
        cin >> s >> d >> w;
        arr[s][d] = (arr[s][d] > w)? w : arr[s][d];
    }
    
    for(int i=1; i <= N; i++){
        for (int j=1; j <= N; j++){
            for(int k=1; k <= N; k++){
                if (j==k)
                    continue;
                if ((arr[j][i]==100000000) || (arr[i][k]==100000000))
                    continue;
                if (arr[j][k] > arr[j][i] + arr[i][k]){
                    arr[j][k] = arr[j][i] + arr[i][k];
                }

            }
        }
    }

    for (int j=1; j<= N; j++){
        for(int k=1; k<= N; k++){
            if (arr[j][k]==100000000)
                cout<<0<<" ";
            else
                cout << arr[j][k] << " ";
        }
        cout << "\n";
    }


    return 0;
}
