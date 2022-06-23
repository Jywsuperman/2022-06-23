#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<stack>
#include<cmath>
#include<map>
#include<queue>
using namespace std;
#define PI pair<int,int>
#define de(x) cout<<x<<" ";
#define Pu puts("");
#define sf(x) scanf("%lld",&x);
typedef long long ll;
const int N=1e5+10;
const int inf=0x3f3f3f3f,mod=998244353;
#define int long long
int n,m,ans,t,T;
int vis[N],u[N]={0},yj[N],cn;
int vis_jian[N]={0};
struct node{
    int t,id,f;
}s[N];
bool cmp(node a,node b){
    if(a.t==b.t) return a.f<b.f;
    return a.t<b.t;
}
signed main(){
    cin>>n>>m>>T;
    int t_max=0;//订单没有到T
    for(int i=1;i<=m;i++){
        sf(s[i].t)sf(s[i].id)
        s[i].f=i;
        t_max=max(t_max,s[i].t);
    }
    sort(s+1,s+m+1,cmp);
    int t,id;
    int last=s[1].t;
    for(int i=1;i<=m;i++){

        t=s[i].t;id=s[i].id;

        if(s[i].t>last+1){//有时间间隔
            for(int j=1;j<=cn;j++){
                u[yj[j]]-=(s[i].t-last-1);
                if(u[yj[j]]<0) u[yj[j]]=0;
            }
        }
        
        if(vis[id]==1){//同一时间多个处理都不减少
            u[id]+=2;

            vis_jian[id]=1;

        }else{
            vis[id]=1;
            u[id]+=2;
            yj[++cn]=id;

            vis_jian[id]=1;

        }
        if(i==m||(i+1<=m&&s[i+1].t!=t)){//同一时间点有多个处理
            for(int j=1;j<=cn;j++){
                if(vis_jian[yj[j]]==1) continue;
                u[yj[j]]--;
                if(u[yj[j]]<0) u[yj[j]]=0;
            }
            memset(vis_jian,0,sizeof(vis_jian));
        }
        last=t;
    }
    if(t_max<T){
        for(int i=1;i<=cn;i++){
            u[yj[i]]-=(T-t_max);
            if(u[yj[i]==0]) u[yj[i]]=0;
        }
    }
    for(int i=1;i<=n;i++){
        //de(u[i])Pu
        if(u[i]>3) ans++;
    }
    de(ans)
}