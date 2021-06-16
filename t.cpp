#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define INF 1e9+7
using namespace std;
typedef long long ll;
int y_move[4] = {0,-1,0,1};
int x_move[4] = {-1,0,1,0};

int shortestPath(int n, int m, vector<vector<int> > &maze){
    int ret = 1;
    pair<int,int> cur;
    vector<vector<bool> > visited(n,vector<bool>(m,false));
    vector<vector<int> > distance(n,vector<int>(m,0));
    queue<pair<int,int>> q;
    cur = {0,0};
    q.push(cur);
    visited[0][0]= true;
    while(!q.empty()){
        cur = q.front();
        cout << '{' << cur.first << ',' << cur.second << '}' << '\n';
        //if(cur.first==n-1 && cur.second==m-1) break;
        for(int i=0; i<4; i++){
            int cur_y = cur.first+y_move[i];
            int cur_x = cur.second+x_move[i];
            if(cur_y>=0 && cur_y<n && cur_x>=0 && cur_x<m){
                if(maze[cur_y][cur_x] && !visited[cur_y][cur_x]) {
                    distance[cur_y][cur_x]= distance[cur.first][cur.second]+1;
                    q.push({cur_y,cur_x});
                    visited[cur_y][cur_x]= true;
                }
            }
        }
        q.pop();
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cout << distance[i][j] << " ";
        cout << '\n';
    }
    return distance[n-1][m-1]+1;
}
int main()
{
    vector<vector<int> > maze(101, vector<int>(101,-1));
    int n,m;
    string input;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> input;
        for(int j=0; j<m; j++)
            maze[i][j]= (int)(input[j]-'0');
    }
    int ans = shortestPath(n,m,maze);
    cout << ans << '\n';
    return 0;
} 