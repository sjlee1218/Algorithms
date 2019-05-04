#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Fishes{
    int x;
    int y;
    vector<int> vec_arr;
};

Fishes arr[1002];
int fish[1002];

int find_fish(int index){
    if (fish[index] != -1)
        return fish[index];

    Fishes cur = arr[index];

    int max = -1;
    for(int dest : cur.vec_arr){
        int temp = find_fish(dest);
        max = (max < temp) ? temp : max;
    }
    fish[index] = max + 1;

    return fish[index];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    // (1000000,1000000) 여기가 목표

    for (int _=0; _<t; _++){
        int N;
        cin >> N;

        for (int i=0; i< N; i++) {
            cin >> arr[i].x >> arr[i].y;
            arr[i].vec_arr.clear();
            fish[i]=-1;
        }

        arr[N].x = 1000001;
        arr[N].y = 1000001;
        arr[N].vec_arr.clear();
        fish[N] = -1;

        for (int i=0; i <= N; i++){
            int cur_x = arr[i].x;
            int cur_y = arr[i].y;

            for (int j=0; j <= N; j++){
                if (j==i)
                    continue;
                if (cur_x <= arr[j].x && cur_y <= arr[j].y){ // 큰 거 에서 잇자
                    arr[j].vec_arr.push_back(i);
                }
            }
        }

        int result = find_fish(N);
        cout<<result<<'\n';

    }


    return 0;
}
