#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int i = 0; int j = i+1;


    int arr[9];
    for(int k = 0; k < 9; k++)
        cin >> arr[k];


    while(i <9){
        while(j<9) {
            ll sum = 0;

            for (int k = 0; k < 9; k++) {
                if ((k == i) || (k == j))
                    continue;
                sum += arr[k];
            }
            if (sum == 100) {
                vector<int> vec;
                for (int k = 0; k < 9; k++) {
                    if ((k == i) || (k == j))
                        continue;
                    vec.push_back(arr[k]);
                }
                sort(vec.begin(), vec.end());
                for(int t : vec)
                    cout<< t<< "\n";
                return 0;
            }
            j++;
        }
        i++; j = i+1;
    }
}
