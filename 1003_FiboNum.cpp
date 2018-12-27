#include <iostream>

using namespace std;

int memo[41]={0,1};
int func(int n);

static int num_zero_one[2]={0,0};
int fibo(int n);
int object;

int arr_zero_one[41][2]; // 다 0으로 초기화됨

/*
 * arr_zero_one[0][0] 이 0을 입력했을 때의 0이 출력되는 횟수
 * arr_zero_one[0][1] 이 0을 입력했을 때의 1이 출력되는 횟수
 * arr_zero_one[3][0] 은 3을 입력했을 때의 0이 출력되는 횟수
 * arr_zero_one[3][1] 은 3을 입력했을 때의 1이 출력되는 횟수
 */

int main(int argc, const char * argv[]) {
    int test;
    int temp;

    cin >> test;
    arr_zero_one[0][0]=1;
    arr_zero_one[1][1]=1;
    while (test){

        cin>> object;

        temp = fibo(object);

        cout << arr_zero_one[object][0]<<" "<< arr_zero_one[object][1]<<endl;

        num_zero_one[0]=0;
        num_zero_one[1]=0;
        test--;
    }
}


int fibo(int n){
    if(n<=1){
        (num_zero_one[n])++;
        return memo[n];
    }

    if (memo[n]!=0){
        num_zero_one[0] +=arr_zero_one[n][0];
        num_zero_one[1] += arr_zero_one[n][1];
        return memo[n];
    }

    memo[n]= fibo(n-1) +fibo(n-2);
    arr_zero_one[n][0]= arr_zero_one[n-1][0] + arr_zero_one[n-2][0];
    arr_zero_one[n][1] = arr_zero_one[n-1][1] + arr_zero_one[n-2][1];

    return memo[n];
}

