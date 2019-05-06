#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	int coin[101];
	for (int i = 0; i < N; i++)
		cin >> coin[i];

	// 쓸 수 있는 코인의 갯수를 늘려가며 하는 거임.
	vector<ll> dp(K + 1, 10000000000);

	dp[0] = 0;
	int cur_coin = -1;
	for (int i = 0; i < N; i++) {
		if (cur_coin == coin[i])
			continue;
		else
			cur_coin = coin[i];
		for (int j = cur_coin; j < K + 1; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}
	if (dp[K] == 10000000000)
		cout << -1;
	else
		cout << dp[K];

}
