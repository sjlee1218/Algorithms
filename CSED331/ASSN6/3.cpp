#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// Maximum flow with node capacity

using namespace std;
typedef long long ll;

struct Edge {
    int start,dest;
    ll edge_cap;
};

struct Node{
    ll node_cap;
    vector<int> edge_vec;
};

vector<Edge> edge_arr;
Node Node_arr[502]; // edge 번호를 저장
vector< pair<int, int> > previous(502, make_pair(-1,-1) ); // <어디서 왔는가, 엣지 번호>

int BFS(int V, int E) { // V 가 노드 갯수, E 가 엣지 개수
    queue<int> q;
    vector<bool> visited(V, 0);
    for (int i = 0; i < V; i++)
        previous[i] = make_pair(-1,-1);

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int here = q.front();
        q.pop();

        if (Node_arr[here].node_cap <=0)
            continue;

        for (int edge_num : Node_arr[here].edge_vec) {
            Edge edge = edge_arr[edge_num];
            int dest = edge.dest;

            if (!visited[dest] && edge_arr[edge_num].edge_cap>0 && Node_arr[dest].node_cap > 0) {
                visited[dest] = true;
                previous[dest] = make_pair(here, edge_num);
                q.push(dest);
                if (dest == V - 1)
                    return 1;

            }
        }
    } // 계속 찾고 못 찾으면 0을 리턴

    return 0;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n, m;
        cin >> n >> m;

        edge_arr.clear();
        for (int i = 0; i < n; i++) {
            Node_arr[i].edge_vec.clear();
            cin >> Node_arr[i].node_cap;
        }

        int edge_num = 0;
        for (int i = 0; i < m; i++) {
            int s, e;
            ll c;
            cin >> s >> e >> c;
            Edge edge;

            edge.start = s; edge.dest = e; edge.edge_cap = c;
            edge_arr.push_back(edge);
            Node_arr[s].edge_vec.push_back(edge_num);
            edge_num++;

            edge.start = e; edge.dest = s; edge.edge_cap = 0;
            edge_arr.push_back(edge);
            Node_arr[e].edge_vec.push_back(edge_num);
            edge_num++;
        }

        int ret = 1;
        ll flow = 4000000;
        ll sum = 0;

        while (ret) {
            ret = BFS(n, m); // 더 이상 n-1 로 가는 길이 없으면 0을 리턴
            // 있으면 1
            // previous[n-1] 을 뒤로 따라가면서 이 루트를 따라갈 수 있음

            if (ret) {
                int cur = n - 1;
                while (cur != 0) {
                    pair<int, int> p = previous[cur];
                    flow = min(flow, edge_arr[p.second].edge_cap);
                    flow = min(flow, Node_arr[cur].node_cap); // node cap 도 따져주자
                    cur = p.first;
                    if (cur == 0)
                        flow = min(flow, Node_arr[cur].node_cap);
                } // cur 이 0 이 되면서 나올 거임.
                sum += flow;
                cur = n - 1;
                while (cur != 0) {
                    pair<int, int> p = previous[cur];
                    Node_arr[cur].node_cap -= flow; // cur 만 빼주면 됨. here, dest 둘 다 빼주면, here은 다음에서도 빼져서 두 번 빠지게 됨
                    // 그냥 빼면 됨
                    edge_arr[p.second].edge_cap -= flow; //p.second 가 엣지 번호
                    int converse = p.second ^ 1;
                    edge_arr[converse].edge_cap += flow;
                    cur = p.first;
                    if (cur == 0)
                        Node_arr[cur].node_cap -= flow;
                } // cur 이 0 이 되면서 나올 거임.
            }
        }

        cout << sum << '\n';
    }
}

