#include <iostream>
#include <queue>
#include <vector>

using namespace std;


class Edge{
public:
    int dest;
    long long weight;
    Edge(int _dest, long long _weight){
        dest = _dest;
        weight = _weight;
    }

};

class Node{
public:
    vector<Edge> path_vec;
    int ComeEdge;
    int check;
};

//Node arr[3001];
//int check[3001];

vector<int> Topological_sort(Node arr[], int vertices_num, int edges_num){
    queue<int> q;
    vector<int> result;
    //vector<int> shit(3000,0);
    //long long max_dist = -1;

    for (int i=0;i< vertices_num;i++){
        if(arr[i].ComeEdge==0){ // 들어오는 에지 개수 0개. 토폴로직 소트의 처음 시작
            q.push(i);
            arr[i].check=1;
        }
        else
            arr[i].check=0;
    }

    while(!q.empty()){
        int start = q.front();
        q.pop();
        result.push_back(start);

        Node temp = arr[start];
        for (int i=0;i<temp.path_vec.size();i++){
            int dest = temp.path_vec[i].dest;
            (arr[dest].ComeEdge)--;

            if(!(arr[dest].ComeEdge))
                q.push(dest);
        }
    }

    return result;
}

long long max_dist = -1;

void find_max(vector<int> Sorted, int vertices_num, Node arr[], int start){
    vector<long long> dist(3001,-1);
    dist[start]=0;
    for(int i=0;i<Sorted.size();i++){
        int v = Sorted[i];
        if (dist[v]==-1)
            continue;
        for(vector<Edge>::iterator itr = arr[v].path_vec.begin(); itr != arr[v].path_vec.end();itr++){
            int dest = (*itr).dest;
            long long weight = (*itr).weight;
            if (dist[dest] < dist[v] + weight)
                dist[dest] = dist[v] + weight;
            if(max_dist<dist[dest])
                max_dist=dist[dest];
        }
    }
}

int main(){
    int test_num;
    scanf("%d", &test_num);

    for(int i=0;i<test_num;i++){
        int vertices_num, edges_num; // vertice <= 3000, edge_num<=1000000
        scanf("%d %d",&vertices_num, &edges_num);
        // vertex == 0, 1, 2, ..., vertice_num-1

        if(edges_num==0 || vertices_num==1){
            cout<<0<<endl;
            continue;
        }

        Node arr[3001];
        for(int k=0;k<vertices_num;k++){
            arr[k].ComeEdge=0;
        }

        for(int j=0; j<edges_num;j++){
            int start, end;
            long long weight;
            scanf("%d %d %lld",&start, &end, &weight);
            //arr[start].push_back(make_pair(end, weight));
            Edge temp(end, weight);
            arr[start].path_vec.push_back(temp);
            arr[end].ComeEdge++;
        } // graph 다 만들었음.

        vector<int> Sorted = Topological_sort(arr, vertices_num,edges_num);
        //sorted 가 위상 정렬된 그래프임

        for(int i=0;i<vertices_num;i++) {
            if (arr[i].check)
                find_max(Sorted,vertices_num,arr, i);
        }

        printf("%lld\n",max_dist);
        max_dist=-1;

    }
}
