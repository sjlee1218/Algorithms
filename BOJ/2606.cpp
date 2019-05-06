#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

vector<int> arr[102];
vector<bool> visited(102,0);

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin>>N;

    int E;
    cin>>E;

    for(int i=0; i<E; i++){
        int s, d;
        cin >> s >> d;

        arr[s].push_back(d);
        arr[d].push_back(s);
    }

    // 1 번에서 시작.
    visited[1] = true;
    int result =0;
    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int top = q.front();
        q.pop();

        for (int dest : arr[top]){
            if (!visited[dest]){
                q.push(dest);
                visited[dest] = true;
                result++;
            }
        }
    }

    cout << result;

    return 0;
}
