#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <stack>
#define INF 1e9+7
typedef long long ll;
using namespace std;
int y_move[4] = {0,-1,0,1};
int x_move[4] = {-1,0,1,0};
int meet(vector<vector<char> > &map, int n, int m){
    queue<pair<int,int>> q;
    int ret = 0;
    vector<vector<bool> > visited(n, vector<bool>(m,false));
    //first find the location of the first 'I'
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            if(map[i][j]=='I'){
                q.push({i,j});
                visited[i][j]-true;
            }
    }
    //then bfs through all the map. if person, person++
    while(!q.empty()){
        pair<int,int> cur_l = q.front();
        cout << cur_l.first << ' ' << cur_l.second << '\n';
        for(int i=0; i<4; i++){
            int cur_y = cur_l.first; int cur_x = cur_l.second;
            for(int i=0; i<4; i++){
                int yy= cur_y+y_move[i]; int xx= cur_x+x_move[i];
                if(yy<0 || yy>=n || xx<0 || xx>=m) continue;
                else if(map[yy][xx]=='O' && !visited[yy][xx]){
                    q.push({yy,xx});
                    visited[yy][xx]=true;
                    if(map[yy][xx]=='P') ret++; 
                }  
            }
        }
        q.pop();
    }
    return ret;
}
int main()
{
    vector<vector<char> > map(601, vector<char>(601));
    int n,m;
    string input;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> input;
        for(int j=0; j<m; j++)
            map[i][j]=char(input[j]);
    }
    int ans = meet(map,n,m);
    cout << ans << '\n';
    return 0;
}