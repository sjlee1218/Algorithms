#include <iostream>
using namespace std;

long long memo[1000][1000] = { 0 };

long long func(int a, int b);

int main() {

	int a, b;

	cin >> a >> b;

	long long result;
	result = func(a, b);

	cout << result;
}

long long func(int a, int b) {

	if (a == 1 || b == 0 || a == b) {
		return 1;
	}

	if (memo[a][b] != 0) {
		return memo[a][b];
	}
	memo[a][b] = func(a - 1,b - 1) + func(a - 1,b);
	return memo[a][b];
}
