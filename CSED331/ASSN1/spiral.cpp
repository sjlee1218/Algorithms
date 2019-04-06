#include <iostream>

using namespace std;

int compare(long target){
    int k=0;

    while(1){
        long comp = (2*k+1)*(2*k+1);
        if (target <= comp)
            return k;
        else
            k++;
    }
}

void loop(long k, long target, long x_y[2]){
    long x, y;
    x=-k+1;
    y=k;

    long min_val = (2*(k-1)+1) * (2*(k-1)+1) +1; // (-k+1,k)

    long sub = target - min_val;
    // 0 ~ 2k-1
    // 2k ~ 4k-1
    // 4k ~ 6k-1
    // 6k ~ 8k-1

    if (sub<2*k){
        x += sub;
    }
    else if(sub<4*k){
        x=k;
        y-= sub-(2*k-1);
    }
    else if (sub<6*k){
        x=k;
        //y-=2*k;
        y=-k;
        x-=sub-(4*k-1);
    }
    else{ // 6k ~ 8k-1
        x=-k;
        y=-k;
        y+=sub - (6*k-1);
    }

    x_y[0]=x;
    x_y[1] = y;

    return;

}

int main() {
    int test_num;

    cin>>test_num;

    for(int i=0; i<test_num;i++){
        long target;
        long x_y[2];

        cin>>target;

        int k=compare(target);

        //cout << k<<endl;

        // max(|x| ,|y|) == k
        // value of (-k+1,k) is the smallest value of this k th square

        loop(k,target,x_y);

        cout<<x_y[0]<<" "<<x_y[1]<<endl;

    }

}
