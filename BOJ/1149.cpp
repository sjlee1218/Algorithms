#include <iostream>
#include <algorithm>

typedef long long ll;
using namespace std;

int arr[1002][3];
ll memo[1002][3];

ll RGB(int index, int color) {
	// R: 0, G: 1, B: 2

	if (memo[index][color] != 0)
		return memo[index][color];

	int col1 = abs(1 - color);
	int col2 = (color == 1) ? 2 : 2 - color;

	ll result = min(RGB(index - 1, col1), RGB(index - 1, col2));
	memo[index][color] = result + arr[index][color];
	return memo[index][color];
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

	memo[0][0] = arr[0][0]; memo[0][1] = arr[0][1]; memo[0][2] = arr[0][2];

	ll r1 = RGB(N - 1, 0);
	ll r2 = RGB(N - 1, 1);
	ll r3 = RGB(N - 1, 2);

	ll temp = (r1 < r2) ? r1 : r2;
	ll temp2 = (temp < r3) ? temp : r3;

	cout << temp2;
}
