#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int test_num;

    long long best_location;
    long long sub_location;
    long long best_index;
    long long sub_index;
    long long sum=0;

    cin>>test_num;

    for(int i=0;i<test_num;i++){
        long long house_num;
        cin>>house_num;

        long long arr_house[house_num];
        for(long j=0;j<house_num;j++)
            cin>>arr_house[j];

        if (house_num%2==1) { // odd number
            best_index = house_num/2;
            best_location = arr_house[best_index];
            for(unsigned long j=0;j<house_num;j++){
                long long diff = abs(best_location - arr_house[j]);
                sum += diff;
            }
        }
        else {
            best_index = house_num/2 - 1;
            sub_index = best_index+1;

            best_location = arr_house[best_index];
            sub_location = arr_house[sub_index];

            best_location = (best_location+sub_location)/2;

            for(unsigned long j=0;j<house_num;j++){
                long long diff = abs(best_location - arr_house[j]);
                sum += diff;
            }

        }
        cout<<sum<<endl;
        sum=0;
    }
}
