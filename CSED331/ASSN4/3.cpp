#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

typedef long long ll;
using namespace std;

ll Park(vector<ll> height_arr, int seg_num, int limit_width){
    ll answer = 0;
    stack<pair<ll, ll> > st; // first is x, seconde is y

    int i = 0;

    while(i<limit_width){
        ll ith_height = height_arr[i];

        if (st.empty() || st.top().second <= ith_height){
            st.push(make_pair(i, ith_height));
            i++;
        }
        else{
            pair<ll, ll> top = st.top();
            st.pop();

            ll top_y = top.second;

            ll x;
            if (!st.empty())
                x= st.top().first +1;
            else
                x=0;

            ll candidate = (i - x) * top_y;

            answer = (answer < candidate) ? candidate : answer;
        }
    }

    return answer;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int n,w;
        cin>>n>>w; // 1<= w <= 1,000,000 범위
        // w 가 10 이면, 내 배열은 0~9 까지 있는 거고, 9 가 9 ~ 10 을 의미하는 거임.

        vector<ll> height_arr(w+1); // 0 < y <= 1,000,000
        height_arr[w]=0;
        // 배열의 인덱스는 0 ~ w-1
        for(int j=0;j<n;j++){
            ll left_x, right_x, y;
            cin>>left_x>>right_x>>y;

            for(ll k=left_x;k<right_x;k++){ // 등호 빠져야 함. 0,2,3 들어오면, 0~1 에 3, 1~2 에 3 라서 등호 빼는게 맞음
                height_arr[k] = y;
            }// 1 단위로 업데이트
        }

        ll answer = Park(height_arr, n,w+1);
        cout << answer << '\n';
    }
}
