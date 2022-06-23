#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<map>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
#define sf(x) scanf("%d",&x);
#define de(x) cout<<x<<" ";
#define Pu puts("");
#define PI pair<int,int>
typedef long long ll;
const int N=2e2+10;
const int inf=0x3f3f3f3f,mod=1e9+7;
// #define int long long
int n,m,ans;
int a[N][N],c[N][N];
//int p[15][15][15];
stack<PI>q[15];
map<int,int>mp;
int vis=0;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
int volid(int x,int y){
    if(x<1||y<1||x>n||y>n) return 0;
    return 1;
}
int cnt;
void po(int x,int y){
    int l,r;
    for(int i=0;i<8;i++){
        l=x,r=y;

        while(1){
            if(a[l][r]==0){
                //de(l)de(r)Pu
                vis=(vis+((l-1)*10+r)*3)*3;
                mp[vis]=1;

                a[l][r]=1;

                PI now;
                now.first=l;
                now.second=r;
                q[cnt].push(now);
            }

            l=l+dx[i];
            r=r+dy[i];

            if(volid(l,r)==0) break;
            //de(l)de(r)Pu
        }
    }
   //de(999)
}
void fun(int dep){
   // de(dep)
    //de(dep)
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==0){

                if(dep==n-1){
                   // de(dep)
                    ans++;
                    return ;
                }
                cnt=dep;
                while(q[dep].size()) q[dep].pop();
                //memcpy(p[dep],a,sizeof(a));
                //de(dep)
                po(i,j);
                fun(dep+1);
                //de(99)

                while(q[dep].size()){
                    PI now=q[dep].top();
                    q[dep].pop();
                    //de(now.first)de(now.second)Pu
                    a[now.first][now.second]=0;
                    vis=(vis/3-((now.first-1)*10+now.second)*3);
                }
                if(mp[vis]==1) return ;
               //memcpy(a,p[dep],sizeof(p[dep]));
            }
            de(dep)Pu
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    de(a[i][j])
                }Pu
            }Pu Pu
        }
    }
    return ;
}
int main(){
    while(cin>>n){
        memset(a,0,sizeof(a));
        fun(0);
        printf("%d\n",ans);
    }
    return 0;
}
