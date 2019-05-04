#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

class Edge{
public:
    int start;
    int dest;
    ll capacity;
};

bool comCapacity(const Edge& a, const Edge& b){
    return a.capacity > b.capacity;
}

int size[3000]; // node 의 어레이
Edge edge_arr[100000];

class DisjointSet{
public:
    vector<int> parent;

    DisjointSet(int n): parent(n){
        for (int i=0;i<n;i++)
            parent[i]=i;
    }

    int find(int u){
        if (u == parent[u]) // 자기 자신이 루트
            return u;

        return parent[u] = find(parent[u]);
        // path compression 자기 위에 있는 애들까지 싹 다 컴프레션 됨.
        // 재귀적으로 올라갔다가 내려오는 거니까
    }

    void merge(int a, int b){ // a가 속한 셋과 b가 속한 셋 합침.
        // 무조건 작은 거가 루트가 되게 넣을 거임.
        // 작은 게 b 로 와야함.
        parent[a] = b;
        // parent_b 의 사이즈가 높아져야함. 우리의 최종 목표는 0 번째 노드의 size가 n 이 되는거
        size[b] += size[a];
    }
};

ll Threshold(int vertex_num, int edge_num){
    sort(edge_arr, edge_arr + edge_num, comCapacity); // 내림차순 정렬.
    DisjointSet disjointSet(vertex_num); // 노드 개수로 parent 배열 만듦. parent[0] ~ parent[vetex_num-1]

    /*
    for(int i=0;i<edge_num;i++){
        cout<<edge_arr[i].capacity<<endl;
    }
     */

    for(int i=0;i<edge_num;i++){ // 가장 capacity 가 큰 엣지부터 그래프에 넣는 거임.
        Edge cur_edge = edge_arr[i];
        int start = cur_edge.start;
        int dest = cur_edge.dest; // 둘 중 작은 숫자가 부모가 되어야 함.

        int start_parent = disjointSet.find(start);
        int dest_parent = disjointSet.find(dest);

        if (start_parent != dest_parent) { // 이미 같은 셋에 있을 때는 merge 하면 안됨
            disjointSet.merge(max(start_parent, dest_parent), min(start_parent, dest_parent));
            if (size[0] == vertex_num)
                return cur_edge.capacity;
        }

    }
}


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int V, E;
        cin>>V>>E; // 1≤w≤1,000,000

        for(int j=0;j<V;j++)
            size[j]=1; // 사이즈 초기화

        for(int j=0;j<E;j++){
            int start, end;
            ll capacity;
            cin>>start>>end>>capacity;

            edge_arr[j].start = start;
            edge_arr[j].dest = end;
            edge_arr[j].capacity = capacity;
        }
        // 그래프는 커넥티드 된 상태인데, 몇을 넘으면 디스커넥티드 될까? 를 찾는 거임.

        ll ans = Threshold(V, E);
        cout<<ans<<'\n';
    }

    return 0;
}
