#include <iostream>

using namespace std;

int memo[1000001]={0,0,1,1};
int func(int n);

int main(int argc, const char * argv[]) {

    int num;

    cin >> num;
    cout << func(num);

    return 0;
}

int func(int n){

    if (memo[n]==0){
        for(int i=4; i<n+1; i++){
            memo[i]=1+memo[i-1];
            if ( (i%3) ==0)
                memo[i]=min(memo[i], (1+memo[i/3]));
            if ( (i%2) == 0)
                memo[i]=min(memo[i], (1+memo[i/2]));
        }
    }
    return memo[n];
}
