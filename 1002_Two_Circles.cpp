#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long test_num;
    long x1, y1, x2, y2, r1, r2, max_rad,sum;
    double dist;

    cin>>test_num;

    while (test_num > 0){

        cin >> x1>>y1>>r1 >>x2>>y2>>r2;

        dist = sqrt(pow(x1-x2,2) + pow(y1-y2,2));

        if (x1==x2 && y1==y2){
            if (r1==r2)
                cout << -1 << endl;
            else
                cout << 0<<endl;

            test_num--;
            continue;
        }

        max_rad= max(r1, r2);

        if ( dist> max_rad){ //case 1

            sum = r1+r2;
            if (dist>sum)
                cout<<0<<endl;
            else if(dist==sum)
                cout<<1<<endl;
            else
                cout<<2<<endl;
        }
        else{ // case 2
            sum=dist+min(r1,r2);
            if (max_rad>sum)
                cout<<0<<endl;
            else if(max_rad ==sum)
                cout<<1<<endl;
            else
                cout<<2<<endl;
        }

        test_num--;
    }

    return 0;
}
