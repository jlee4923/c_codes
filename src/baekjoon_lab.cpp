#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <memory.h>
#include <cmath>
#include <utility>
#include <cassert>
#include <numeric>
#define INF 1e9+7
#define INF_L (-1)*(1e9+7)
typedef long long ll;
typedef unsigned long long ull;
typedef long int li;
using namespace std;
int comp = -30000000;
int cnt=0;
const int mov[4][2]= {
	{-1,0},{0,-1},{0,1},{1,0}
}; //y,x(up,left,right,down)
void printMap(vector<vector<int>>& map);
int safetyZone(vector<vector<int>>& map){
	int blanks = 0;
	queue<pair<int,int>> q;
	vector<vector<int>> tmp(map.size(),vector<int>(map[0].size(),0));
	for(int i=0; i<map.size(); i++){
		for(int j=0; j<map[i].size(); j++){
			tmp[i][j]= map[i][j]; //복사
		}
	}
	for(int i=0; i<tmp.size(); i++){
		for(int j=0; j<tmp[i].size(); j++){
			if(tmp[i][j]==2){
				int dy = i, dx = j;
				q.push({dy,dx});
				while(!q.empty()){
					int qy = q.front().first;
					int qx = q.front().second;
					q.pop();
					for(int k=0; k<4; k++){	
						int ty= qy + mov[k][0];
						int tx= qx + mov[k][1];
						if(ty<0 || tx<0 || tmp.size()<=ty || tmp[0].size()<=tx) continue;
						else if(tmp[ty][tx]) continue;
						tmp[ty][tx]=2;
						q.push({ty,tx});
					}
				} 
			}
		}
	}
	//cout << "polluted map : " << '\n';
	//printMap(tmp);
	for(int i=0; i<tmp.size(); i++)
		for(int j=0; j<tmp[i].size(); j++)
			if(tmp[i][j]==0) blanks++;
	return blanks;
}
void printMap(vector<vector<int> >& map){
	for(int i=0; i<map.size(); i++){
		for(int j=0; j<map[i].size(); j++){
			cout << map[i][j] << " ";
		}
		cout << '\n';
	}
}
int setWalls(vector<vector<int> >& map, int walls_left, vector<pair<int,int>> pos){
	int ret;
	if(walls_left==0){
		//cout << "Map : " << '\n';
		//printMap(map);
		//cnt++;
		//cout << '\n' << "cnt : " << cnt << '\n';
		int safe = safetyZone(map);
		//cout << "safe : " << safe << '\n';
		comp = max(comp, safe);
		return comp;
	}
	ret = 0;
	for(int i=0; i<map.size(); i++){
		for(int j=0; j<map[i].size(); j++){
			if(map[i][j]==0 && (pos.empty() || (pos.back().first==i && pos.back().second<j) || pos.back().first<i)){
				map[i][j]=1;
				pos.push_back({i,j});	
				setWalls(map, walls_left-1, pos);
				map[i][j]=0;
				pos.pop_back();
			}
		}
	}
	return comp;
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int n, m, ans;
	cin >> n >> m;
	vector<vector<int> > map(n, vector<int>(m, 0));
	vector<pair<int,int> > pos;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> map[i][j];
	cout << setWalls(map, 3, pos) << '\n';
	return 0;
}