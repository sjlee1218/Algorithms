#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

bool visit[102][102];
vector<int> arr[102];

void BFS(int start, int N){
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int top = q.front();
        q.pop();

        for(int dest : arr[top]){
            if (!visit[start][dest]){
                q.push(dest);
                visit[start][dest] = true;
            }
        }
    }

}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin>>N;

    int x;
    for (int i=0; i< N; i++){
        for (int j=0; j< N; j++){
            cin >> x;
            if (!x)
                continue;
            arr[i].push_back(j);
        }
    }

    for (int i=0; i< N; i++){
        BFS(i, N);
    }

    for (int i=0; i< N; i++){
        for (int j=0; j< N; j++){
            cout << visit[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}
