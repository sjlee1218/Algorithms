// I checked all possible case
// So, this algorithm is slower than DP method
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

typedef long long ll;
using namespace std;

ll arr[13][13];

int main() {
    int test_num;
    scanf("%d",&test_num);

    for (int i=0;i<test_num;i++){
        int node_num, edge_num;
        scanf("%d %d",&node_num, &edge_num);

        for(int i = 0; i<13;i++) {
            for (int j = 0; j < 13; j++)
                arr[i][j] = 2147483647;
        }

        for(int i = 0; i< edge_num; i++){
            int s, d; ll w;
            scanf("%d %d %lld", &s, &d, &w);

            arr[s][d] = w;
            arr[d][s] = w;
        }

        vector< vector<int>> perm_arr;
        vector<int> temp_arr;
        for(int i = 1;i <node_num;i++)
            temp_arr.push_back(i);

        ll ret = 2147483647;

        do { // 메모리에서 터짐
            ll sum = arr[0][temp_arr[0]];
            int check = 1;
            for(int j = 0; j < temp_arr.size()-1; j++){
                if(arr[temp_arr[j]][temp_arr[j+1]] == 2147483647){
                    check = 0;
                    break;
                }
                sum += arr[temp_arr[j]][temp_arr[j+1]];
            }
            if (!check)
                continue;

            ll comp = sum + arr[temp_arr[temp_arr.size()-1]][0];
            ret = min(ret, comp);
        } while ( next_permutation(temp_arr.begin(),temp_arr.end()) );


        if (ret >= 2147483647){
            cout << -1 <<'\n';
            continue;
        }
        else
            cout << ret<<'\n';

    }

}
