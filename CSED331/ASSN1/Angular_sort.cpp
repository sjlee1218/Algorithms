#include <iostream>
#include <math.h>

#define MAX_NUM 1000000

long point_arr[MAX_NUM][2];
double polar_arr[MAX_NUM][2]; // [0] for distance from (0,0), [1] for rad

long sorted_point[MAX_NUM][2];
double sorted_polar[MAX_NUM][2];

using namespace std;

void merge(int left, int mid, int right){
    int i, j, k, l;
    i = left;
    j = mid+1;
    k = left;

    while(i<=mid && j<=right){
        if (polar_arr[i][1] < polar_arr[j][1]){
            sorted_point[k][0] = point_arr[i][0];
            sorted_point[k][1] = point_arr[i][1];

            sorted_polar[k][0] = polar_arr[i][0];
            sorted_polar[k++][1] = polar_arr[i++][1];
        }
        else if(polar_arr[i][1] > polar_arr[j][1]){
            sorted_point[k][0] = point_arr[j][0];
            sorted_point[k][1] = point_arr[j][1];

            sorted_polar[k][0] = polar_arr[j][0];
            sorted_polar[k++][1] = polar_arr[j++][1];
        }
        else{ // same angle
            double i_dist = point_arr[i][0]*point_arr[i][0] + point_arr[i][1]*point_arr[i][1];
            double j_dist = point_arr[j][0]*point_arr[j][0] + point_arr[j][1]*point_arr[j][1];

            if(i_dist<j_dist){
                sorted_point[k][0] = point_arr[i][0];
                sorted_point[k][1] = point_arr[i][1];

                sorted_polar[k][0] = polar_arr[i][0];
                sorted_polar[k++][1] = polar_arr[i++][1];
            }
            else{
                sorted_point[k][0] = point_arr[j][0];
                sorted_point[k][1] = point_arr[j][1];

                sorted_polar[k][0] = polar_arr[j][0];
                sorted_polar[k++][1] = polar_arr[j++][1];
            }
        }
    }

    if(i>mid){
        for(l=j; l<=right; l++) {
            //sorted[k++] = list[l];
            sorted_point[k][0] = point_arr[l][0];
            sorted_point[k][1] = point_arr[l][1];

            sorted_polar[k][0] = polar_arr[l][0];
            sorted_polar[k++][1] = polar_arr[l][1];
        }
    }
    else{
        for(l=i; l<=mid; l++) {
            sorted_point[k][0] = point_arr[l][0];
            sorted_point[k][1] = point_arr[l][1];

            sorted_polar[k][0] = polar_arr[l][0];
            sorted_polar[k++][1] = polar_arr[l][1];
        }
    }

    for(l=left; l<=right; l++){
        point_arr[l][0] = sorted_point[l][0];
        point_arr[l][1] = sorted_point[l][1];

        polar_arr[l][0] = sorted_polar[l][0];
        polar_arr[l][1] = sorted_polar[l][1];
    }
}

void merge_sort(int left, int right){
    int mid;

    if(left<right){
        mid = (left+right)/2;
        merge_sort(left, mid);
        merge_sort(mid+1, right);
        merge(left, mid, right);
    }
}

int main() {
    int test_num;
    cin>>test_num;

    for(int i=0;i<test_num;i++){
        int point_num;
        cin>>point_num;

        for(int k=0;k<point_num;k++) {
            cin >> point_arr[k][0] >> point_arr[k][1];
            double theta = atan2(point_arr[k][0], point_arr[k][1]);
            if (theta < 0) {
                theta += atan(1) * 8;
            }
            double dist = point_arr[k][0] * point_arr[k][0] + point_arr[k][1] * point_arr[k][1];

            polar_arr[k][0] = dist;
            polar_arr[k][1] = theta;
        }

        merge_sort(0,point_num-1);

        for(int q=0;q<point_num;q++){
            cout<<point_arr[q][0]<<" "<<point_arr[q][1]<<endl;
        }
        cout<<endl;
    }

    return 0;
}
