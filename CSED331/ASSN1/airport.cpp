#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_NUM 100000

using namespace std;

typedef pair<int,int> int_pair;

bool comparator(const int_pair& l, const int_pair& r){
    return l.first<r.first;
}

int main() {
    int test_num;
    cin>>test_num;

    for(int i=0;i<test_num;i++) {
        int point_num;
        cin >> point_num;

        int point_arr[point_num][2];

        vector<int_pair> X_pairs;
        vector<int_pair> Y_pairs;

        long long x_dist_arr[point_num][2];
        long long y_dist_arr[point_num][2];
        long long final_dist[point_num];

        for(int j=0;j<point_num;j++){
            cin>>point_arr[j][0]>>point_arr[j][1];

            X_pairs.push_back(int_pair(point_arr[j][0],j));
            Y_pairs.push_back(int_pair(point_arr[j][1],j));

            x_dist_arr[j][0] = 0;
            y_dist_arr[j][0] = 0;
            final_dist[j] = 0;
        }

        stable_sort(X_pairs.begin(), X_pairs.end(),comparator);
        stable_sort(Y_pairs.begin(), Y_pairs.end(),comparator);

        long long x_sum=0;
        long long y_sum=0;
        for(int j=1;j<point_num;j++){
            x_sum = x_sum + (X_pairs[j].first - X_pairs[j-1].first)*j;
            y_sum = y_sum + (Y_pairs[j].first - Y_pairs[j-1].first)*j;
            x_dist_arr[j][0] += x_sum;
            x_dist_arr[j][1] = X_pairs[j].second; // 인덱스까지 저
            y_dist_arr[j][0] += y_sum;
            y_dist_arr[j][1] = Y_pairs[j].second;
        }

        x_sum=0;
        y_sum=0;
        for(int j=point_num-2;j>=0;j--){
            x_sum = x_sum + (X_pairs[j+1].first - X_pairs[j].first)* (point_num-j-1);
            y_sum = y_sum + (Y_pairs[j+1].first - Y_pairs[j].first)* (point_num-j-1);
            x_dist_arr[j][0] += x_sum;
            y_dist_arr[j][0] += y_sum;
            x_dist_arr[j][1] = X_pairs[j].second; // 인덱스까지 저장
            y_dist_arr[j][1] = Y_pairs[j].second;
        }

        for(int j=0; j<point_num;j++){
            final_dist[x_dist_arr[j][1]] += x_dist_arr[j][0];
            final_dist[y_dist_arr[j][1]] += y_dist_arr[j][0];
        }

        long long min = final_dist[0];
        for(int j=1;j<point_num;j++){
            if(final_dist[j]<min)
                min=final_dist[j];
        }

        cout<<min<<endl;
    }

}
