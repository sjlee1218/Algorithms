#include <iostream>
#include <stack>
#include <list>
#include <queue>

using namespace std;

class Node{
public:
    int visited;
    list<int> path_list;
};

Node arr[1200];

void DFS(int Node_num, int start_num){
    for(int k=1;k<=Node_num;k++){
        arr[k].visited =0;
        arr[k].path_list.sort();
    }

    stack<int> DFS_stack;
    DFS_stack.push(start_num);
    arr[start_num].visited=1;
    cout<<start_num<<" ";

    while(!DFS_stack.empty()){
        int current = DFS_stack.top();
        DFS_stack.pop();

        for(list<int>::iterator itr=arr[current].path_list.begin(); itr != arr[current].path_list.end();itr++){
            int ref = *itr;

            if(!arr[ref].visited){
                cout<<ref<<" ";
                arr[ref].visited=1;
                DFS_stack.push(current);
                DFS_stack.push(ref);
                break;
            }
        }
    }

}

void BFS(int Node_num, int start_num){
    for(int k=1;k<=Node_num;k++){
        arr[k].visited =0;
    }

    queue<int> BFS_queue;
    arr[start_num].visited=1;
    BFS_queue.push(start_num);
    cout<<start_num<<" ";

    while(!BFS_queue.empty()){
        int current = BFS_queue.front();
        BFS_queue.pop();

        for(list<int>::iterator itr=arr[current].path_list.begin(); itr != arr[current].path_list.end();itr++){
            int ref = *itr;

            if(!arr[ref].visited){
                cout<<ref<<" ";
                arr[ref].visited=1;
                BFS_queue.push(ref);
            }
        }
    }
}

int main(){
    int Node_num, Edge_num, start_num;
    cin>>Node_num>>Edge_num>>start_num;

    for(int i=0;i<Edge_num;i++){
        int node1, node2;
        cin>>node1>>node2;

        arr[node1].path_list.push_back(node2);
        arr[node2].path_list.push_back(node1); // 연결 끝
    }

    DFS(Node_num, start_num);
    cout<<endl;
    BFS(Node_num , start_num);

}
