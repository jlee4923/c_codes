#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <stack>
#define INF 1e9+7
typedef long long ll;
using namespace std;
int y_move[4] = {0,-1,0,1};
int x_move[4] = {-1,0,1,0};
string smupc = "SMUPC";
//s= subtraction, m= multiplication, u=division, p= plus(addition), c=returns the value calced.
ll convert_str_to_ll(string num){
    ll ret = 0;
    ll weight;
    for(int i=0; i<num.size(); i++){
        weight = (ll)pow(10,num.size()-i-1);
        ret += (ll)(num[i]-'0')*weight;
    }
    return ret;
}
// 3SC2M3U1P2CCC
// 
void calc(string input){ 
    ll res;
    int first;
    char op;
    string str= "";
    for(int i=0; input[i]>='0' && input[i]<='9'; i++){
        str += input[i];
        first = i;
    } //first one
    res = convert_str_to_ll(str);
    char op_now = input[first+1];
    char op_before;
    if(first==input.size()-2 && op_now=='C') cout << res;
    //cout << op_now << " " << res << "\n";
    str = "";
    for(int i=first+2; i<input.size(); i++){
        if(input[i]>='0' && input[i]<='9'){
             str += input[i];
             continue;
        }
        else{
            op_before = op_now; op_now = input[i];
            //cout << "res : " << res << '\n';
            //cout << "op_before : " << op_before << " op_now : " << op_now << '\n';
            //cout << "str: " << convert_str_to_ll(str) << '\n';
        }
        if(op_before=='C'){
            cout << res << " ";
        }else if(op_before=='P'){
            res += convert_str_to_ll(str);
        }else if(op_before=='M'){
            res *= convert_str_to_ll(str);
        }else if(op_before=='S'){
            res -= convert_str_to_ll(str);
        }else if(op_before=='U'){
            if(res<0){
                res*=(-1); res/=convert_str_to_ll(str); res*=(-1);
            }
            else res/=convert_str_to_ll(str);
        }
        if(i==input.size()-1 && op_now=='C') cout << res;
        str= "";
    }
}
int main()
{
    string input;
    int n, flag=0;
    cin >> n;
    cin >> input;
    int len = input.size();
    for(int i=0; i<len; i++)
        if(input[i]=='C') flag=1;
    if(!flag) cout << "NO OUTPUT" << '\n';
    else{
        calc(input);
        cout << '\n';
    }
    return 0;
}