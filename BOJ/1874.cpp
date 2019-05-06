#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
typedef long long ll;

int arr[100002];
bool popped[100002];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;

    stack<int> st;
    vector<char> vec;

    for(int i = 0; i<t; i++){
        cin >> arr[i];
    }

    int num = 1;
    int check = 0;

    for(int i = 0; i < t;i++){
        int cur = arr[i];
        if (popped[cur]){
            check = 1;
            break;
        }
        if (st.empty() || cur > st.top()){
            st.push(num++);
            vec.push_back('+');
            while(cur > st.top()){
                st.push(num++);
                vec.push_back('+');
            } // 이거 끝나면  같아짐.
            popped[st.top()] = true;
            st.pop();
            vec.push_back('-');
        }
        else if(cur == st.top()){
            popped[cur] = true;
            st.pop();
            vec.push_back('-');
        }
        else{ // cur < st.top()
            while(cur < st.top()){
                popped[st.top()] = true;
                st.pop();
                vec.push_back('-');
            }
            popped[st.top()] = true;
            st.pop();
            vec.push_back('-');
        }
    }

    if (check)
        cout << "NO";
    else {
        for (char c : vec)
            cout << c << '\n';
    }

}
