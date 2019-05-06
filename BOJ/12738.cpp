#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll origin_arr[1000002];
vector<ll> lis;

int main() {
    ll N;
    scanf("%lld", &N);

    for(int i = 0; i<N; i++){
        scanf("%lld", &origin_arr[i]);
    }

    lis.push_back(-2000000000);
    for(int i=0;i<N;i++){
        ll cur = origin_arr[i];
        if (cur > lis.back()){
            lis.push_back(cur);
        }
        else{
            vector<ll>::iterator it = lower_bound(lis.begin(), lis.end(), cur);
            *it = cur;
        }

    }

    cout<<lis.size()-1;
    return 0;
}
