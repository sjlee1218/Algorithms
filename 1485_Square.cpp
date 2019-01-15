#include <iostream>
#include <math.h>

using namespace std;

int arr[4][2]; // 4개의 점. 2개는 x, y

void find_dist(double dist[6]){
    dist[0] = sqrt(pow(arr[0][0] - arr[1][0],2) + pow(arr[0][1] - arr[1][1],2)); // 0 ~ 1
    dist[1] = sqrt(pow(arr[0][0] - arr[2][0],2) + pow(arr[0][1] - arr[2][1],2)); // 0 ~2
    dist[2] = sqrt(pow(arr[0][0] - arr[3][0],2) + pow(arr[0][1] - arr[3][1],2)); // 0 ~ 3
    dist[3] = sqrt(pow(arr[1][0] - arr[2][0],2) + pow(arr[1][1] - arr[2][1],2));
    dist[4] = sqrt(pow(arr[1][0] - arr[3][0],2) + pow(arr[1][1] - arr[3][1],2));
    dist[5] = sqrt(pow(arr[2][0] - arr[3][0],2) + pow(arr[2][1] - arr[3][1],2));
}

int main() {
    int num;
    cin>> num;

    double dist[6]; // dist[k][0]은 check 용임

    for (int i=0; i<num;i++){
        for (int j=0; j<4;j++) {
            cin >>arr[j][0]>>arr[j][1];
        } // 점 다 받았음

        find_dist(dist);
        //for (int j=0;j<6;j++){
        //    cout<< dist[j]<<endl;
        //}

        double temp;
        int check;
        for (int j=0; j<6;j++){
            temp = dist[j];
            check=1;
            for(int k=j+1;k<6;k++){
                if (temp==dist[k]) {
                    check += 1;
                }
            }
            if (check==4)
                break;
        }
        // 4개의 변이 같은 거임을 찾음

        if (check!=4){
            cout<<0<<endl;
            continue;
        }
        double k[2];
        int q=0;

        for (int j=0; j<6;j++){
            if (dist[j]!=temp){
                k[q++]=dist[j];
            }
        }
        if (k[0]==k[1])
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
