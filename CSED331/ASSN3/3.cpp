#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int minCycle(vector<int> graph[], int start, int end)
{
    queue<pair<int, int> > q;
    vector<bool> visited(1002, false);

    q.push(make_pair(start, 1));
    visited[start] = true;

    while(!q.empty())
    {
        int here = q.front().first;
        int level = q.front().second;
        q.pop();

        if(here == end)
            return level;

        for(int i=0; i<graph[here].size();i++)
        {
            int next = graph[here][i];
            if(level == 1 && next == end)
                continue;

            if(!visited[next])
            {
                q.push(make_pair(next, level + 1));
                visited[next] = true;
            }
        }
    }

    return -1;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false); // 이거 하면 scanf로 안바꿔도 됨

    int test_num;
    cin >> test_num;

    for(int j=0;j<test_num;j++){
        int vertices_num, Edge_num;
        int ans = -1;

        cin>>vertices_num>>Edge_num;

        vector<int> graph[1002];

        for (int i = 0; i < Edge_num; i++){
            int s, d;
            cin >> s >> d;
            graph[s].push_back(d);
            graph[d].push_back(s);
        }

        for (int i = 0; i < vertices_num; i++){
            for (int j = 0; j < graph[i].size(); j++) {
                int child = graph[i][j]; // 시작 점 말고, 시작점의 자식들에서 BFS 돌림 -> 시작 점 나오면 cycle 있는거지
                int ret = minCycle(graph,child, i);

                if (ret != -1) {
                    ans = (ans == -1 ? ret : min(ans, ret));
                }
            }
        }

        cout << ans << '\n';
    }
}
