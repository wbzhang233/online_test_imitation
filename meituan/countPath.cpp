//
// Created by wbzhang on 2020/9/20.
//

class Visit {
public:
	int countPath(vector<vector<int> > map, int n, int m) {
		// write code here
		int xm=0,ym=0;//经理位置
		int xc=0,yc=0;//商家位置
		for(int i=0;i<map.size();i++)
		{
			for(int j=0;j<map[0].size();j++)
			{
				if(map[i][j] == 1)
				{
					xm=i;
					ym=j;
				}
				else if(map[i][j] == 2)
				{
					xc=i;
					yc=j;
				}
			}
		}
		int dirx = xm > xc ? -1 :1;//上下移动
		int diry = ym > yc ? -1 : 1;//左右移动
		vector<vector<int> > res(n,vector<int>(m,0));
		for(int i=xm;i!=xc+dirx;i+=dirx)
		{
			for(int j=ym;j!=yc+diry;j+=diry)
			{
				if(i==xm && j==ym)//初始化起点
					res[i][j]=1;
				else if(i == xm)
					res[i][j]= (map[i][j] == -1)? 0 : res[i][j-diry];//只在一个方向上移动，方案等于上次方案
				else if(j == ym)
					res[i][j]= (map[i][j] == -1)? 0 : res[i-dirx][j];//只在一个方向上移动，方案等于上次方案
				else
					res[i][j]= (map[i][j] == -1)? 0 : res[i-dirx][j]+res[i][j-diry];//两个方向之和为总方案数
			}
		}
		return res[xc][yc];
	}
};