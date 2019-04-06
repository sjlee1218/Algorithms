#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

typedef long long ll;
using namespace std;

class Edge{
public:
    ll weight;
    int dest;
    Edge(ll _w, int _d){
        weight= _w;
        dest=_d;
    }
};
class full_Edge{
public:
    int start, end;
    ll weight;
    full_Edge(int s, int e, ll w){
        start=s; end=e; weight=w;
    }
};

bool operator < (const full_Edge& e1, const full_Edge& e2){
    return e1.weight>e2.weight;
}

struct Data{
    int start, end;
    ll weight;
};
vector<full_Edge> redundant;
priority_queue<full_Edge> candidate;
vector<Data> raw_Data;
int seen[30001];
int level[30001];
int seen_number=1;

bool raw_sort(const Data& d1, const Data& d2){
    if (d1.start<d2.start)
        return true;
    else if (d1.start>d2.start)
        return false;
    else{ // 같다면
        return d1.end < d2.end;
    }
}

bool raw_cmp(const Data& d1, const Data& d2){
    if ((d1.start==d2.start) && (d1.end == d2.end)){
        full_Edge temp(d2.start,d2.end, d2.weight);
        redundant.push_back(temp);
        return true;
    }
    else
        return false;
};


void DFS(vector<Edge> input[], int here, int parent_num){
    seen[here] = seen_number++;
    level[here] = seen[here];

    for(int i=0;i<input[here].size();i++){
        Edge temp = input[here][i];

        if (temp.dest == parent_num)
            continue;

        if (seen[temp.dest] == 0){ // 아직 이 노드 방문 안함
            DFS(input, temp.dest, here);
            level[here] = min(level[here], level[temp.dest]);

            if (seen[here] < level[temp.dest]){ // 여기가 문제였음
                full_Edge insane(here, temp.dest, temp.weight);
                candidate.push(insane);
                //candidate.push(insane);
            }
        }
        else{ // 이미 본 걸 방문함
            level[here] = min(level[here], seen[temp.dest]);
        }
    }

}


int main() {
    int test_num;
    scanf("%d",&test_num);

    for (int i=0;i<test_num;i++){
        int node_num, edge_num;
        scanf("%d %d",&node_num, &edge_num);

        seen_number=1;
        vector<Edge> input[node_num];

        raw_Data.clear();
        redundant.clear();
        //candidate.clear();

        for(int k=0;k<30001;k++){
            seen[k]=0;
            level[k]=0;
        }

        for(int k=0;k<edge_num;k++){
            Data raw;
            int u, v;
            ll weight;
            scanf("%d %d %lld", &u, &v, &weight);
            raw.start = min(u,v);
            raw.end = max(u,v);
            raw.weight=weight;

            raw_Data.push_back(raw);
        }
        sort(raw_Data.begin(), raw_Data.end(), raw_sort);
        /*
        for(int wq=0;wq<raw_Data.size();wq++){
            cout<<raw_Data[wq].start<<" "<<raw_Data[wq].end<<" "<<raw_Data[wq].weight<<endl;
        }*/
        raw_Data.erase(unique(raw_Data.begin(),raw_Data.end(), raw_cmp), raw_Data.end());

        for(auto itr = raw_Data.begin(); itr != raw_Data.end(); itr++){
            Edge temp1((*itr).weight, (*itr).end);
            Edge temp2((*itr).weight, (*itr).start);
            input[(*itr).start].push_back(temp1);
            input[(*itr).end].push_back(temp2);
        }

        /*
        cout<<"------redundant------"<<endl;
        for(int ee=0;ee<redundant.size();ee++){
            cout<<redundant[ee].start<<" "<<redundant[ee].end<<" "<<redundant[ee].weight<<endl;
        }
        cout<<"---------------------"<<endl;
        cout<<"------Real Input------"<<endl;
        for(int zz=0;zz<node_num;zz++) {
            for(auto temp : input[zz])
                cout<<zz<<" "<<temp.dest<<" "<<temp.weight<<endl;
        }
        cout<<"---------------------"<<endl;
         */

        DFS(input,0,-1);
        ll min_length = -1;
        int check=0;

        /*
        cout<<"------Candidate Start------"<<endl;
        while(!candidate.empty()){
            cout<<candidate.top().start<<" "<<candidate.top().end<<" "<<candidate.top().weight<<endl;
            candidate.pop();
        }
        cout<<"------Candidate End------"<<endl;
         */


        while(min_length==-1 && !candidate.empty()){
            check=0;
            full_Edge temp = candidate.top();
            candidate.pop();

            for(int qq=0;qq<redundant.size();qq++){
                if (((redundant[qq].start == temp.start) && (redundant[qq].end == temp.end)) || ( (redundant[qq].end == temp.start) && (redundant[qq].start == temp.end) ) ){
                    check=1;
                    break;
                }
            }

            if(check==0)
                min_length = temp.weight;
        }
        while(!candidate.empty()){
            candidate.pop();
        }

        printf("%lld\n",min_length);



        /*
        cout<<"------redundant------"<<endl;
        for(int qq=0;qq<redundant.size();qq++){
            cout<<redundant[qq].start<<" "<<redundant[qq].end<<" "<<redundant[qq].weight<<endl;
        }
        cout<<"---------------------"<<endl;
        while(!candidate.empty()){
            cout<<candidate.top().weight<<endl;
            candidate.pop();
        }
        cout<<endl;
         */

    }

}

