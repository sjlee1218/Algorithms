#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

struct Node{
    int x;
    int y;
};

/*
bool operator <= (const Node& a, const Node& b){
    return a.x <= b.x && a.y <= b.y;
}
*/

bool comp_X_Y(const Node& a, const Node& b){
    if (a.x < b.x){
        return true;
    }
    else if (a.x == b.x){
        return a.y <= b.y;
    }
    else
        return false;
}

bool comp_Y(const Node& a, const Node& b){
    return a.y <= b.y;
}

Node arr[300003];
vector<Node> My_vec;

/*
int My_lower_bound(Node cur){
    int cur_y = cur.y;
    int size = My_vec.size();

    int i=1; int j = size-1;
    while(i<j){ // 등호 붙나?
        int mid = (i+j)/2;

        Node temp = My_vec[mid];
        if (temp.y <= cur_y){ // 즉, true
            i = mid + 1;
        }
        else{
            j = mid;
        }
    }

    return j;
}
*/
int main(){
    int t;
    scanf("%d", &t);

    for(int _ = 0 ; _ < t ; _++){
        int N;
        scanf("%d",&N);

        for(int i=0;i<N;i++)
            scanf("%d %d", &arr[i].x, &arr[i].y);

        sort(arr, arr+N, comp_X_Y);
        arr[N].x = 10000001;
        arr[N].y = 10000001;

        /*
        for(int j=0; j<=N; j++)
            cout<<"("<<arr[j].x<<", "<<arr[j].y<<")";
        cout<<"\n";
         */

        Node temp;
        temp.x = -1; temp.y = -1;
        My_vec.push_back(temp); // (-1, -1) 넣은 거임.

        for(int i=0; i<= N; i++){
            Node cur = My_vec.back();
            if (cur.y <= arr[i].y){
                My_vec.push_back(arr[i]);
            }
            else{
                auto itr = lower_bound(My_vec.begin(), My_vec.end(), arr[i], comp_Y);
                //int itr = My_lower_bound(arr[i]);
                //My_vec[itr] = arr[i];
                *itr = arr[i];
            }

            /*
            for(int j=0; j<My_vec.size(); j++)
                cout<<"("<<My_vec[j].x<<", "<<My_vec[j].y<<")";
            cout<<"\n";
             */

        }

        cout << My_vec.size() -2 << "\n";
        My_vec.clear();
    }
}
