#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

vector< vector<int> > arr (501, vector<int >() );
ll table[501][501][2];

ll DP(int row, int col, int dir) { // dir == 0 ->  오른쪽에서 옴, dir == 1 -> 왼쪽에서 옴
	if (row == 1) {
		return arr[1][0];
	}
	if (col == 0 && dir == 1) {
		return -99999999;
	}
	if ((col == row-1)  && dir == 0) {
		return -99999999;
	}

	if (table[row][col][dir] != 0)
		return table[row][col][dir];

	ll can1 = DP(row - 1, col - dir, 0);
	ll can2 = DP(row - 1, col - dir, 1);

	ll ret = max(can1, can2);

	table[row][col][dir] = ret + arr[row][col];
	return 	table[row][col][dir];
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int l = 1; l <= N; l++) {
		for (int s = 0; s < l; s++) {
			int temp;
			cin >> temp;
			arr[l].push_back(temp);
		}
	}

	table[1][0][0] = arr[1][0];
	table[1][0][1] = arr[1][0];

	ll sum_max = 0;
	for (int i = 0; i < N; i++) {
		ll ret = DP(N, i,0);
		ll ret1 = DP(N, i, 1);

		sum_max = (ret > sum_max) ? ret : sum_max;
		sum_max = (ret1 > sum_max) ? ret1 : sum_max;
	}

	cout << sum_max;


}
