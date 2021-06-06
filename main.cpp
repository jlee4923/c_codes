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
//#define A 1001
//#define B 1001
//defined for BFS/DFS
#define INF 1e9+7
#define INF_L (-1)*(1e9+7)
typedef long long ll;
typedef unsigned long long ull;
typedef long int li;
using namespace std;
//int mat[A][B];
int visited[20];
stack<int> s;
queue<int> q;
void printPicked(vector<int>& picked){
	int n= picked.size();
	cout << "nCm : ";
	for(int i=0; i<n; i++){
		cout << picked[i] << " ";
	}
	cout << "\n";
}
int pick(int n, vector<int>& picked, int toPick){
	if(toPick==0) {
		printPicked(picked);
		return 1;
	}
	int ret = 0;
	int smallest= picked.empty()? 0: picked.back()+1;
	for(int next= smallest; next<n; ++next){
		picked.push_back(next);
		ret += pick(n,picked,toPick-1);
		picked.pop_back();
	}
	return ret;
}
int main()
{
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int num, select;
	vector<int> picked;
	cin >> num >> select;
	int ans= pick(num, picked, select);
	cout << "ans : " << ans;
	return 0;
}