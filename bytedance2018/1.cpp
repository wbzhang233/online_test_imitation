#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Point
{
    int x;
    int y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

int main()
{
    int N;
   	scanf("%d",&N);
    vector<Point> pts;

	int x, y;

	for (int i = 0; i < N; i++)
    {
        // cin >> x >> y;
        scanf("%d%d",&x,&y);
        Point pt(x, y);
        pts.push_back(pt);
    }

    // 按x由小到大排序，相同时，则按y小到大排序
    sort(pts.begin(), pts.end(), [](Point pt1, Point pt2) {
         return pt1.x<pt2.x ? true: (pt1.x==pt2.x)&&(pt1.y<pt2.y);
    });

    stack<Point> maxPts;
    // 从x最大点开始，记录后方最大的y值
    int ymax = INT_MIN;
    for(int i= pts.size()-1;i>=0;i--)
    {
        if(pts[i].y >= ymax){
            maxPts.push(pts[i]);
            ymax = pts[i].y;
        }
    }

	cout<<"answer"<<endl;
	while (!maxPts.empty() )
    {
        printf("%d %d\n",maxPts.top().x,maxPts.top().y);
        maxPts.pop();
    }
    
    return 0;
}

/*
 5
 1 3
 2 6
 3 4
 4 3
 5 2
  */



/*
 10
 298498081 747278511
 427131847 460128162
 939984059 817455089
 911902081 683024728
 474941318 6933274
 140954425 607811211
 336122540 629431445
 208240456 458323237
 646203300 469339106
 106410694 436340495
 */

