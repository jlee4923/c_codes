#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#define INF 1e9+7
using namespace std;
int d[51][51];
int inven[6]; //keys
int v[51][51][64];
pair<int,int> moving[4] = {
    {0,-1}, {-1,0}, {0,1}, {1,0}
};
bool canVisit(int y, int x){
    //v as a 3-d array: the third dimension means visiting a vertex
    //with keys a~f. All possible ways of keys in inventory equals 
    //2^6, which is 64.
}
int bfs(vector<vector<char> >&map, int n, int m){
    queue<pair<int,int> > q;
    int flag = 0, ones = 0;
    int reached = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j]=='0'){
                q.push({i,j});
                flag = 1;
            }
        }
        if(flag) break;
    }
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(map[i][j]=='1') ones++;
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        cout << "current_y : " << cur.first << " current_x : " << cur.second << '\n';
        for(int i=0; i<4; i++){
            int y = cur.first+moving[i].first;
            int x = cur.second+moving[i].second;
            if(y>=0 && y<n && x>=0 && x<m && canVisit(y,x)){
                cout << "valid!!\ny,x : " << y << ' ' << x << '\n';
                if(map[y][x]=='#') continue;
                else if(map[y][x]=='.'){
                    q.push({y,x});
                }
                else if(map[y][x]>='a' && map[y][x]<='f'){
                    inven[map[y][x]-'a']=1;
                    q.push({y,x});
                }
                else if(map[y][x]>='A' && map[y][x]<='F'){
                    for(int j=0; j<6; j++){
                        cout << "inven : " << inven[j] << '\n';
                        cout << "expr : " << ('a'+j)-map[y][x] << '\n';
                        if(inven[j] && ('a'+j)-map[y][x]==('a'-'A')){
                            q.push({y,x});
                            break;
                        }
                    }
                }
                d[y][x] = d[cur.first][cur.second]+1;
            }
        }
    }
    vector<pair<int,int> > not_zero;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j]=='1' && d[i][j]) not_zero.push_back({i,j});
        }
    }
    if(!not_zero.size()) return -1;
    int smallest = INF;
    for(int i=0; i<not_zero.size(); i++)
        smallest = min(smallest,d[not_zero[i].first][not_zero[i].second]);
    return smallest;
}
int main()
{
    int n, m;
    string str;
    vector<vector<char> > map(51, vector<char>(51,'.'));
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> str;
        for(int j=0; j<m; j++){
            map[i][j]= str[j];
        }
    }
    cout << bfs(map,n,m) << '\n';
    return 0;
}
