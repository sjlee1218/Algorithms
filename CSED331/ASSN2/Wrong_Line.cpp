#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
/*
https://briangordon.github.io/2014/08/the-skyline-problem.html
https://stackoverflow.com/questions/55027452/are-there-any-efficient-algorithm-for-top-hull
*/
using namespace std;

class Event{
public:
    long long x;
    int start_or_end; //start 면 1, end 면 0
    long long y;

    bool operator > (const Event& temp) const
    {
        if (y<temp.y)
            return true;
        else if(y>temp.y)
            return false;
        else{ // 같으면
            return !start_or_end;
        }
    }
};

bool compx(const Event& e1, const Event& e2){
    if(e1.x<e2.x) // 냅둬야 하는 거지
        return true; // 이게 점점 커지는 거.
    else if (e1.x > e2.x)
        return false;
    else{ // 같을 때
        return e1.start_or_end;
    }
}


Event event_Arr[30000];
Event result_Arr[60000];
/*
2
1
4 7 3
6
0 3 3
2 4 4
1 5 2
7 8 6
7 10 3
6 9 5

4 7 3
0 2 3
2 4 4
4 5 2
6 7 5
7 8 6
8 9 5
9 10 3


 */
int main() {
    int test_num;
    scanf("%d",&test_num);

    for(int i=0;i<test_num;i++){
        int line_num;
        scanf("%d",&line_num);
        //    priority_queue<rect, vector<rect>, greater<rect> > q;
        //My_priority_queue q;//<Event, vector<Event>, greater<Event>> q;
        set<long long,greater<>> s;

        Event start;
        Event end;
        long long x1,x2, y;
        int start_or_end;

        for(int j=0;j<2*line_num;j+=2){
            scanf("%lld %lld %lld",&(event_Arr[j].x),&(event_Arr[j+1].x),&(event_Arr[j].y)); // x1, x2, y
            event_Arr[j].start_or_end=1;
            event_Arr[j+1].y=event_Arr[j].y;
            event_Arr[j+1].start_or_end=0;
        }
        sort(event_Arr,event_Arr+2*line_num,compx); // x같다면, start가 먼저 오게 소팅 다 했음.

        long long prior_y=-1;
        int result_index = 0;

        for(int j=0;j<2*line_num;j++){ // 2*line_num -1 인가?
            //printf("%lld %lld\n", event_Arr[j].x, event_Arr[j].y);
            Event temp = event_Arr[j];
            if(!s.empty()){
                prior_y = *s.begin();
            }
            else{ // 비었으면,
                prior_y=-1;
            }
            if (temp.start_or_end){ // 시작이면, 큐에 넣음
                //q.push(temp);
                s.insert(temp.y);
            }
            else{ // 아니면, 빼
                // 지금 거의 것과 인덱스가 같은 것을 빼야함
                s.erase(temp.y); // 뺐을 때 뭐라면??
                /*if(!s.empty()){
                    prior_y = *s.begin();
                }
                else{ // 비었으면,
                    prior_y=-1;
                }
                 */
            }
            if (prior_y != *s.begin()){ // 다르면, 뭔가를 넣거나 뺀거나 한거임
                result_Arr[result_index].x = temp.x;
                result_Arr[result_index].y = temp.y;
                result_Arr[result_index].start_or_end = temp.start_or_end;
                result_index++;
            }
        }


        for(int qw=0;qw<result_index-1;qw++){
            Event temp = result_Arr[qw];
            Event next = result_Arr[qw+1];
            if(temp.start_or_end && next.start_or_end){ // 붙여서 출력
                printf("%lld %lld %lld\n",temp.x, next.x,temp.y);
            }
            else if (temp.start_or_end && !next.start_or_end){ // s e
                printf("%lld %lld %lld\n",temp.x, next.x,temp.y);
            }
            else if (!temp.start_or_end && !next.start_or_end){ // e e
                printf("%lld %lld %lld\n",temp.x, next.x,next.y);
            }/*
            else{ // 다 end
            }
            */
        }

        //s.clear();

    }

    return 0;
}
