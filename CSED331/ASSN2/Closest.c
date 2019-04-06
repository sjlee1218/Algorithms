#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define INT_MAX 2147483647L

long long min(long long dist1, long long dist2){
    return dist1> dist2 ? dist2 : dist1;
}

typedef struct{
    long long x;
    long long y;
} Point;

Point vec[200000];
Point third[200000];
/*
int compX(const Point p1, const Point p2){
return p1.x<=p2.x;
}
int compY(const Point p1, const Point p2){
return p1.y<=p2.y;
}
 */
long long distance(const Point a,const Point b){
return llabs(a.x - b.x) + llabs(a.y - b.y);
}

int compareX (Point *first, Point *second)
{
    if (first->x > second->x)
        return 1;
    else if (first->x < second->x)
        return -1;
    else
        return 0;
}

int compareY (Point *first, Point *second)
{
    if (first->y > second->y)
        return 1;
    else if (first->y < second->y)
        return -1;
    else
        return 0;
}


long long MinDist(int start, int end){
    if(start ==end){ // 점이 1개 일단 이거 때문에 위험함.
        return INT_MAX;
    }
    else if((end-start)==1) // 점이 2개
        return distance(vec[end],vec[start]);

    //점이 3개 이상
    int mid=(start+end)/2;
    long long medianX = vec[mid].x;

    long long dist1 = MinDist(start, mid); // 왼쪽,
    long long dist2 = MinDist(mid+1, end); // 오른쪽
    long long delta = min(dist1,dist2);

    int k=0;

    for(int i=start; i <= end; i++){
        if (abs(vec[i].x - medianX)<delta){ // vec[mid]는 무조건 들어감
            third[k].x=vec[i].x;
            third[k++].y=vec[i].y;
        }
    }

    long long minVal = delta;
    qsort(third, k, sizeof(Point), compareY);
    for (int i=0;i<k;i++){
        for (int j=i+1; (j<k)&& ((third[j].y-third[i].y)<minVal)&& (j<=i+6) ;j++){
            if (distance(third[j], third[i])<minVal)
                minVal = distance(third[j], third[i]);
        }
    }

    return minVal;

}

int main(){
    int test_num;
    scanf("%d",&test_num);

    for (int i=0;i<test_num;i++){
        int point_num;
        scanf("%d",&point_num);

        long long x,y;
        for(int j=0;j<point_num;j++){
            scanf("%lld %lld",&x,&y);
            vec[j].x = x;
            vec[j].y = y;
        }
        qsort(vec, point_num, sizeof(Point), compareX);
        /*for(int j=0;j<point_num;j++){
            printf("%lld %lld\n",vec[j].x, vec[j].y);
        }*/

        long long result = MinDist(0, point_num-1);
        printf("%lld\n",result);
    }

}
