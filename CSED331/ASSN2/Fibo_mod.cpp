#include <iostream>
#include <math.h>
#define MY_MAX 2147483647

using namespace std;
int arr[31];

void mod(long long x[][2]){
    x[0][0] = x[0][0] %MY_MAX;
    x[0][1] = x[0][1] %MY_MAX;
    x[1][0] = x[1][0] %MY_MAX;
    x[1][1] = x[1][1] %MY_MAX;
}

void matmul(long long x[][2], long long y[][2]){
    long long a = x[0][0]*y[0][0] + x[0][1]*y[1][0];
    long long b = x[0][0]*y[0][1] + x[0][1]*y[1][1];
    long long c = x[1][0]*y[0][0] + x[1][1]*y[1][0];
    long long d = x[1][0]*y[0][1] + x[1][1]*y[1][1];

    y[0][0]=a;
    y[0][1]=b;
    y[1][0]=c;
    y[1][1]=d;
}

long long Fibo(int num){

    if(num==0)
        return 0;
    if ((num==1)||(num==2))
        return 1;

    long long mat[2][2] = {1,1,1,0};
    long long insane[2][2]={2,1,1,1};
    long long temp[2][2] = {1,1,1,0};
    long long result[2][2] = {1,1,1,0};
    int j=0;
    int check=0;

    num=num-1; // 1 빼줌.

    int x=num;
    int mul_mat_power=0;

    while(x>0){
        arr[j++] = x&1;
        x=x>>1;
    }

    for(int i=2; i<=j-1;i++){ // j-1 이 최대 자리수
        if (!(arr[i]))
            continue;

        for(int q=mul_mat_power;q<i;q++){
            matmul(temp,temp);
            mod(temp);
            mul_mat_power++;
        }// 이걸로, 곱해줄 행렬 먼저 구함


        if (check==0){
            check=1;
            result[0][0] = temp[0][0];
            result[0][1] = temp[0][1];
            result[1][0] = temp[1][0];
            result[1][1] = temp[1][1];
        }
        else{
            matmul(temp,result);
            mod(result);
        }
    }

    if(arr[1]) {
        if (check==0) {
            check = 1;
            result[0][0] = insane[0][0];
            result[0][1] = insane[0][1];
            result[1][0] = insane[1][0];
            result[1][1] = insane[1][1];
        }
        else {
            matmul(insane, result);
            mod(result);
        }
    }
    if (arr[0]) {
        if (check==0) {
            check = 1;
            result[0][0] = temp[0][0];
            result[0][1] = temp[0][1];
            result[1][0] = temp[1][0];
            result[1][1] = temp[1][1];
        }
        else {
            matmul(mat, result);
            mod(result);
        }
    }
    return result[0][0];
}

int main(){
    int test_num;
    cin>>test_num;

    for(int i=0; i<test_num;i++){
        int num;
        cin>>num;
        cout<<Fibo(num)<<endl;
    }
}
