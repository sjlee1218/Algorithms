#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

class union_find {
public:
	vector<int> parent, rank;
	union_find(int N) : parent(N), rank(N, 1) {
		for (int i = 0; i < N; i++)
			parent[i] = i;
	}
	int find(int x) {
		if (parent[x] == x)
			return x;
		else
			return parent[x] = find(parent[x]);
	}

	int merge(int a, int b) {
		int parent_A = find(a);
		int parent_B = find(b);

		if (parent_A == parent_B) return -1; //부모가 같아지는 경우. 그래프로 치면 cycle 이 생기는 건가?

		if (rank[parent_A] > rank[parent_B]) {
			parent[parent_B] = parent_A;
		}
		else {
			parent[parent_A] = parent_B;
			if (rank[parent_A] == rank[parent_B])
				rank[parent_B]++;
		}
		return 1;
	}
};

class Edge {
public:
	int s, e, w;
};

bool comp_edge(const Edge& a, const Edge& b) {
	return a.w < b.w;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int _ = 0; _ < t; _++) {
		int V, E;
		cin >> V >> E;

		union_find myset(V);
		vector<Edge> edge_arr;

		for (int i = 0; i < E; i++) {
			int s, e;
			cin >> s >> e;
			Edge temp;
			temp.s = s - 1; temp.e = e - 1; temp.w = 1;
			edge_arr.push_back(temp); // non-directed graph
		}

		sort(edge_arr.begin(), edge_arr.end(), comp_edge);

		int num = 0;
		int sum = 0;

		for (Edge edge : edge_arr) {
			int s = edge.s; int e = edge.e; int w = edge.w;

			if (myset.merge(s, e) == -1) {
				continue;
			}
			else { // 그래프에 추가하면 됨, 이미 merge 되어 있는 상태임
				num++;
				sum += w;
			}
			if (num == V - 1)
				break;
		}

		cout << sum << '\n';
	}
}
