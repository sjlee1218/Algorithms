#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
typedef long long ll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int female, male, intern;
	cin >> female >> male >> intern;

	int total = female + male;
	ll sum = 0;

	while ((total-intern) >= 0 && female>=0 && male >= 0) {
		female -= 2;
		male -= 1;
		sum++;
		total -= 3;
	}

	cout << sum-1;
}
