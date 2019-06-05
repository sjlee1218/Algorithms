#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
typedef long long ll;

class Edge{
public:
    int start, dest;
    int cap;
    Edge(int s, int d, int c=1){
        start = s; dest = d; cap = c;
    }
};

vector<Edge> Edge_arr; // edge 들을 저장
vector<int> Node_arr[2003]; // 몇 번의 노드가 몇 번의 엣지를 가지고 있나?
vector<int> level(2003, -1);
vector< pair<int, int> > parent(2003, make_pair(-1,-1));

int BFS(int s, int t){
    for(int i = 0; i<t+1; i++)
        level[i] = -1;

    queue<int> q;
    level[s] = 0;
    q.push(s);

    int check = 0;

    while(!q.empty()){
        int here = q.front();
        int cur_level = level[here];
        q.pop();

        for(int edge_num : Node_arr[here]){
            Edge edge = Edge_arr[edge_num];
            int dest = edge.dest;

            if(edge.cap>0 && level[dest] == -1){ // 갈 수 있는 길이고, 아직 방문한 적이 없었음.
                level[dest] = cur_level + 1;
                q.push(dest);
                if(dest == t)
                    check = 1;
            }
        }
    }

    return check; // t 로 가는 길이 있다면, 1을 리턴, 없다면 0을 리턴
}

int DFS(int s, int t){
    stack<int> st;
    vector<bool> visited(t+1, false);
    for(int i = 0; i<t+1; i++)
        parent[i] = make_pair(-1,-1);

    visited[s] = true;
    st.push(s);

    while(!st.empty()){
        int here = st.top();
        int here_level = level[here];
        st.pop();

        for(int edge_num : Node_arr[here]){
            Edge edge = Edge_arr[edge_num];
            int dest = edge.dest;

            if (level[dest] - here_level != 1) // 1 차이가 안나면 거름
                continue;
            // 이제 1 차이 나는 거임
            if (edge.cap > 0 && !visited[dest]){
                parent[dest] = make_pair(here, edge_num);
                if (dest == t)
                    return 1;
                visited[dest] = true;
                st.push(dest);
            }

        }
    }
    return 0;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for(int _ = 0; _ < t; _++){
        int n, m, l;
        cin >> n >> m >> l;
        // s == node number 0
        // each left node number should be added by 1
        // each right node number should be added by (n+1)
        // t == node number n+m+1
        Edge_arr.clear();
        for(int i = 0; i< n+m+2;i++)
            Node_arr[i].clear();

        int k = 0; // for edge number
        for(int i = 1; i <= n; i++){ // 노드 번호 1번부터 n 번까지, s==0 과 연결
            Edge e(0, i);
            Edge_arr.push_back(e);
            Node_arr[0].push_back(k++);

            Edge e1(i, 0, 0); // 역 간선
            Edge_arr.push_back(e1);
            Node_arr[i].push_back(k++);
        } // s 랑 연결함.

        for(int __ = 0; __ < l; __++){
            int left, right;
            cin >> left >> right;
            left += 1; right += n+1;

            Edge e(left, right);
            Edge_arr.push_back(e);
            Node_arr[left].push_back(k++);

            Edge e1(right, left, 0); // 역 간선
            Edge_arr.push_back(e1);
            Node_arr[right].push_back(k++);
        }

        for(int i = n+1; i <= n+m; i++){ // t == n+m+1 과 연결
            Edge e(i, n+m+1);
            Edge_arr.push_back(e);
            Node_arr[i].push_back(k++);

            Edge e1(n+m+1, i, 0); // 역 간선
            Edge_arr.push_back(e1);
            Node_arr[n+m+1].push_back(k++);
        } // 간선 연결 끝남

        int ret = 1;
        ll flow = 4000000;
        ll sum = 0;

        while(ret){
            ret = BFS(0, n+m+1);
            if(ret==0)
                break;
            // 만약 1을 리턴했어. 즉, 유효하게 레벨 그래프가 그려졌어
            // 이제 DFS 돌려야함.
            while(true){
                int ret_dfs = DFS(0, n+m+1);
                if (!ret_dfs) // 길을 못 찾으면 break. BFS 다시 돌려야함
                    break;
                // 이제, DFS 로 길을 찾은 거임.
                int cur = n+m+1;
                sum += 1;
                while(cur != 0){
                    //cout<<cur<<" ";
                    pair<int, int> par = parent[cur]; // first 가 부모 노드, second 가 엣지 넘버
                    Edge_arr[par.second].cap -= 1;
                    int converse = par.second ^ 1;
                    Edge_arr[converse].cap += 1;
                    cur = par.first;
                }
                //cout<<'\n';
            }
        }

        cout<<sum<<'\n';
    }
}
