#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

// Bitonic Tour

pair<ll,ll> arr[517];
double Tour[517][517]; // Tour[x][y]. x < y

double Euclidean(const pair<ll, ll> a, const pair<ll, ll> b){
    return sqrt(pow(a.first-b.first,2) + pow(a.second-b.second,2));
}

double Patrol(int x_index, int y_index){ // x < y

    if (Tour[x_index][y_index] != -1)
        return Tour[x_index][y_index];

    // index 로 베이스 하나 더

    if (x_index < y_index -1){
        Tour[x_index][y_index] = Patrol(x_index, y_index -1) + Euclidean(arr[y_index - 1], arr[y_index]);
    }
    else{ // x_index == y_index -1. // 1,2 에서 안돌음.
        double minimum = -1;

        for(int k=0; k<y_index-1; k++){
            double temp = Patrol(k, x_index) + Euclidean(arr[k], arr[y_index]);
            minimum = (temp < minimum || minimum == -1) ? temp : minimum;
        }
        Tour[x_index][y_index] = minimum;
    }

    return Tour[x_index][y_index];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.unsetf(ios::fixed);
    cout.precision(5);

    int t;
    cin>>t;

    for (int _=0; _<t;_++){
        int N;
        cin>>N;


        for(int i=0;i<N;i++){
            cin>>arr[i].first >> arr[i].second;
        }

        //sort(arr, arr+N);

        for(int i=0; i < N; i++){
            for (int j=0; j < N; j++){
                Tour[i][j] = -1;
            }
        }

        /*
        for(int i=0; i<N ; i++)
            cout << "(" <<arr[i].first <<","<< arr[i].second<<") ";
        cout<<'\n';
         */

        Tour[0][1] = Euclidean(arr[0], arr[1]);

        double result = -1;

        for (int k=0; k < N-1; k++ ){
            double temp = Patrol(k, N-1) + Euclidean(arr[k], arr[N-1]);
            result = (temp < result || result == -1) ? temp : result;
        }

        /*
        for(int i=0; i < N; i++){
            for (int j=0; j < N; j++){
                cout<<Tour[i][j]<<" ";
            }
            cout<<endl;
        }
         */


        cout << result << "\n";

    }
}
