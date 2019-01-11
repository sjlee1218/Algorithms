#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

queue<int> visit_queue;
//stack<int> visit_stack;

class Node{
public:
    int num; // 자기 자신이 어떤 친구인지 인식하기 위한 숫자
    vector<int> adj_vec; // 얘가 연결되어 있는 곳들에 대한 벡터
    int check;

    Node(int _num){ // constructor
        num=_num;
        check=0;
    }

};

vector<Node*> vector_of_nodes;

/*
 *      1
 *    2  3
 *      4 5
 *
 */

void DFS(vector<Node*> vector_of_nodes, int node_num){ // 스택 또는 재귀함수로 구
    //visit_stack.push(root_node_num-1);
    vector_of_nodes[node_num-1]->check=1;
    Node* ref=vector_of_nodes[node_num-1];
    cout<< node_num<< " ";

    sort(ref->adj_vec.begin(), ref->adj_vec.end());


    for (vector<int>::iterator itr = ref->adj_vec.begin(); itr != ref->adj_vec.end(); itr++) {
        int i=vector_of_nodes[*itr]->num+1;
        int check=vector_of_nodes[*itr]->check;

        if (check==0)
            DFS(vector_of_nodes, i);

    }

    //ref->adj_vec.begin()+i

    /*while(!visit_stack.empty()){

        while(ref!=NULL){
            sort(ref->adj_vec.begin(), ref->adj_vec.end());

            for (int i=0; i<ref->adj_vec.size();i++){
                if (ref->check == 0){
                    ref = vector_of_nodes[*(ref->adj_vec.begin()+i)];
                    ref->check = 1;
                    visit_stack.push(ref->num);
                    cout<< ref->num + 1<< " ";
                    continue;
                }

            }
            visit_stack.pop();
            ref= vector_of_nodes[visit_stack.top()];
        }
    }
     */

}

void BFS(vector<Node*> vector_of_nodes,int root_node_num,queue<int> visit_queue) {
    visit_queue.push(root_node_num-1);
    vector_of_nodes[root_node_num-1]->check = 2;
    cout << root_node_num << " ";

    while (!visit_queue.empty()) {
        Node *temp = vector_of_nodes[visit_queue.front()];
        visit_queue.pop(); // 맨 앞의 거를 temp 설정, 그리고 맨 앞 꺼 pop

        sort(temp->adj_vec.begin(), temp->adj_vec.end());// 가장 작은 거 부터 들어가보려고 하는 거임.

        for (vector<int>::iterator itr = temp->adj_vec.begin(); itr != temp->adj_vec.end(); itr++) {
            if (vector_of_nodes[*itr]->check == 1) {
                visit_queue.push(*itr);
                vector_of_nodes[*itr]->check = 2;
                cout << *itr+1 << " ";
            }
        }

    }
    //cout<<endl;
}

int main() {

    int node_num, edge_num, root_node;
    int node_1, node_2;

    cin>> node_num >> edge_num >> root_node;

    for (int i=0; i<node_num; i++){
        Node* tmp= new Node(i);
        vector_of_nodes.push_back(tmp);
    }
    /*
    cout<< vector_of_nodes[0]->num<<endl;
    cout<< vector_of_nodes[1]->num<<endl;
*/
    for (int i=0; i<edge_num;i++){
        cin>> node_1 >> node_2; // 1 2면, vector_of_nodes[0], [1] 임
        vector_of_nodes[node_1-1]->adj_vec.push_back(node_2-1);
        vector_of_nodes[node_2-1]->adj_vec.push_back(node_1-1); // 양방향 연결
    }

    DFS(vector_of_nodes, root_node); // this make check 1
    cout<<endl;
    BFS(vector_of_nodes,root_node, visit_queue); // this make check 2

}
