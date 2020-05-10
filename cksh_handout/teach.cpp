#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
#define pb push_back
const int maxn = 10;

vector<int> edge[maxn];
int vis[maxn];

void dfs(int n){
    vis[n]=1;
    cout<<n<<' ';
    for(int x:edge[n]){
        if(vis[x]==false)
        dfs(x);
    }

}

int main(){
    int n,m;
    cin>>n>>m;
    rep(i,m){
        int a,b;cin>>a>>b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    dfs(0);
    cout<<endl;
    return 0;
}