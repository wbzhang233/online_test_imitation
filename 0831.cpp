//
// Created by wbzhang on 2020/8/31.
//
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:

	// 直接dfs
	void dfs(vector<vector<int> > rooms,int cur,bool *visited)
	{
		visited[cur] = true;
		// 对于当前位置的每把钥匙，都依次进行尝试
		for(auto key:rooms[cur]){
			if(!visited[key]) dfs(rooms,key,visited); //如果这扇门没进去过，则进去
		}
	}

	void dfs2(vector<vector<int> > rooms,int cur,bool visited[])
	{
		visited[cur] = true;
		// 对于当前位置的每把钥匙，都依次进行尝试
		for(auto key:rooms[cur]){
			if(!visited[key]) dfs2(rooms,key,visited); //如果这扇门没进去过，则进去
		}
	}

	void dfs0(vector<vector<int> > rooms,int cur,vector<bool> &visited)
	{
		visited[cur] = true;
		// 对于当前位置的每把钥匙，都依次进行尝试
		for(auto key:rooms[cur]){
			if(!visited[key]) dfs0(rooms,key,visited); //如果这扇门没进去过，则进去
		}
	}

	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		int N = rooms.size();
//		bool *visited = new bool[N];
		// for(int i=0;i<N;i++) visited[i] = false;

		vector<bool > visited(N,false);
		dfs0(rooms,0,visited);

		// 如果存在没有打开的房间，则失败
		bool res = true;
		for(int i=0;i<N;i++){
			res = res && visited[i];
			cout<<visited[i]<<"\t";
		}
//		delete[] visited;
		return res;
	}
};


int main()
{
//	vector<vector<int> >  rooms = {{1},{2},{3},{} };
	vector<vector<int> >  rooms = {{1,3},{3,0,1},{2},{0} };

	Solution solution;
	bool res = solution.canVisitAllRooms(rooms);
	cout<<"res: "<<res<<endl;
	return 0;
}