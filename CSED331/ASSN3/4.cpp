#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Edge{
public:
    int dest;
    long long price;
    long long distance;
    Edge(int _d, long long p, long long dist){
        dest = _d;
        price = p;
        distance = dist;
    }
};

class Node{
public:
    vector<Edge> edge_vec;
};

long long MIN_PRICE;
long long MAX_PRICE;

Node arr[1001];

bool Dijkstra(int Node_num, long long Limit_price, long long limitM){
    // max_price 를 리턴, 불가능하면 -1을 리턴
    //start_node 0, final_node = Node_num-1
    vector<long long> dist(1001, -1);
    dist[0]=0;

    priority_queue<pair<long long, int> > q;
    q.push(make_pair(0,0));

    while(!q.empty()){
        long long here_dist = -q.top().first;
        int here = q.top().second;
        q.pop();

        for(Edge current : arr[here].edge_vec){
            int dest = current.dest;
            long long price = current.price;
            long long distance = current.distance;

            if(price>Limit_price)
                continue;

            if (distance>limitM)
                continue;

            if (dist[dest] == -1 || dist[dest]>here_dist + distance){
                dist[dest] = here_dist + distance;
                q.push(make_pair(-(dist[here] + distance), dest));
            }
        }
    }

    //cout<<"최소 거리: "<<dist[Node_num-1]<<endl;

    if(dist[Node_num-1] == -1){ // 가는 길 없음
        return false;
    }
    if (dist[Node_num-1]>limitM) // 그 거리 안에 못감
        return false;
    return true;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false); // 이거 하면 scanf로 안바꿔도 됨

    int test_num;
    cin>>test_num;

    for(int i=0; i<test_num;i++){
        int P, S;
        long long limitM;
        cin>> P>>S>>limitM;
        //scanf("%d %d %lld",&P, &S, &limitM);

        MIN_PRICE=2147483648;
        MAX_PRICE=-1;

        for(int k = 0; k < P; k++){
            arr[k].edge_vec.clear();
        }

        for(int j=0;j<S;j++){
            int start, end;
            long long p, d;
            cin>>start>>end>>p>>d;
            //scanf("%d %d %lld %lld",&start, &end, &)
            MIN_PRICE = (MIN_PRICE>p) ? p : MIN_PRICE;
            MAX_PRICE = (MAX_PRICE<p) ? p : MAX_PRICE;
            Edge temp(end, p, d);
            arr[start].edge_vec.push_back(temp);
        }

        long long low = MIN_PRICE;
        long long high = MAX_PRICE + 1;
        long long print_min_price=-1;

        while(low < high){
            long long mid = (low+high)/2;
            // mid 를 돈의 상한선으로 주는 거야. 여기서 되면, high = mid 가 되는 거고
            // 안되면 low = mid+1


            if (!Dijkstra(P, mid, limitM)) { // 못 갔음
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }

        cout<< (low == MAX_PRICE + 1 ? -1 : low) <<endl;
        // 우리가 가야 하는 곳은 P-1, 시작은 0

    }
}
