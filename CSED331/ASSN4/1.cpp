#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

// --------- Disjoint Set-----------
using namespace std;

typedef struct{
    int fee;
    int deadline;
} Exhibit;

bool comFee(const Exhibit& a, const Exhibit& b){
    return a.fee>b.fee;
}

Exhibit arr[300002];

struct DisjointSet{
    vector<int> parent;
    DisjointSet(int n): parent(n+1){ // 0 번째가 비어 있는 일임.
        for (int i=0;i<n+1;i++)
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
        int parent_a = find(a); // a 가 속한 셋의 루트를 찾음
        int parent_b = find(b);

        parent[parent_a] = parent_b;
    }


};


long long find_max_exhibit(int n, int max_dead){
    long long sum=0;
    sort(arr, arr+n, comFee);

    DisjointSet disjointSet(max_dead); // max_dead 개 만듦.

    for (int i=0;i<n;i++) {

        int parent_of_i = disjointSet.find(arr[i].deadline);
        // max_dead 가 4면, 0 1 2 3 이 index 임

        if (parent_of_i !=0){ // 1 이상이 유효한 날임. k 번 째가 되는 날이면, k-1 번째를 부모로 만들거야.
            disjointSet.merge(parent_of_i, parent_of_i-1);
            sum += arr[i].fee;
        }
    }

    return sum;
}


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int n; // 1<=n<=300000
        cin>>n;


        int max_deadline = -1;

        for(int j=0;j<n;j++){
            int fee,deadline;
            cin>>fee>>deadline; // 0<f≤1,000,000 0≤d≤100,000

            if (deadline==0) // 날짜 1일부터 시작하므로, 0인 d는 불가능함.
                continue;

            max_deadline = (max_deadline<deadline) ? deadline : max_deadline;

            Exhibit temp;
            temp.fee = fee;
            temp.deadline= deadline;

            arr[j] = temp;
        }

        long long sum = find_max_exhibit(n, max_deadline);

        cout<<sum<<'\n';

    }
}
