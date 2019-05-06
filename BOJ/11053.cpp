#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

int arr[1003];
vector<int> vec_arr[1003];
vector<int> sum(1003, 0);

int find_sum(int index) {
    if (sum[index] != 0)
        return sum[index];

    int max = 0;
    for (int dest : vec_arr[index]) {
        if (dest >= index)
            continue;
        int temp = find_sum(dest);
        max = (max < temp) ? temp : max;
    }

    sum[index] = max + 1;
    return sum[index];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N; i++) {
        int cur = arr[i];
        for (int j = 0; j < N; j++) {
            if (i == j)
                continue;
            if (cur < arr[j]) {
                vec_arr[j].push_back(i);
            }
        }
    }

    int max =0;
    for (int i = N - 1; i >= 0; i--) {
        int temp = find_sum(i);
        max = (max < temp) ? temp : max;
    }

    cout << max;

}
