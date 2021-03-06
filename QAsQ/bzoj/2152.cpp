#include<bits/stdc++.h>
using namespace std;

const int maxn = 21234;
vector<pair<int,int> >edge[maxn];

void init(int n){
    for(int i=0;i<=n;i++){
        edge[i].resize(0);
    }
}

void Link(int st,int ed,int v){
    v %= 3;
    edge[st].push_back(make_pair(ed,v));
    edge[ed].push_back(make_pair(st,v));
}

int dp[maxn][3];
int cnt[maxn];

void dfs(int st,int fa){
    cnt[st] = 1;
    dp[st][0] = 1;
    for(vector<pair<int,int> >::iterator it = edge[st].begin();it!=edge[st].end();it++){
        int x = it->first;
        int v = it->second;
        if(x!=fa){
            dfs(x,st);
            cnt[st] += cnt[x];
            for(int i=0;i<3;i++) cnt[st] += dp[st][i]*dp[x][(6-i-v)%3];
            for(int i=0;i<3;i++) dp[st][(i+v)%3] += dp[x][i];
        }
    }
}

int main(){
    int n;
    while(~scanf("%d",&n)){
        init(n);
        int x,y,v;
        for(int i=1;i<n;i++){
            scanf("%d %d %d",&x,&y,&v);
            Link(x,y,v);
        }
        memset(dp,0,sizeof(dp));
        dfs(1,0);
        int ans = cnt[1] * 2 - n;
        int d = __gcd(ans,n*n);
        printf("%d/%d\n",ans/d,n*n/d);
    }
    return 0;
}
