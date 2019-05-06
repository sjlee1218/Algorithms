#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
typedef long long ll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string N;
	cin >> N;

	vector<int> candidate;

	bool check = 0;

	for (char c : N) {
		int rem = (int)(c - '0');
		if (rem == 0)
			check = 1;
		candidate.push_back(rem);
	}

	if (!check) {
		cout << -1;
		return 0;
	}

	sort(candidate.begin(), candidate.end());

	ll sum1 = 0;

	for (int n : candidate)
		sum1 += (n%3);

	if (sum1 % 3 != 0) {
		cout << -1;
		return 0;
	}
	
	string s = "";

	for (int i = candidate.size() - 1; i >= 0; i--) {
		char c = candidate[i] + '0';
		s.push_back(c);
	}

	cout << s;
	return 0;

}
