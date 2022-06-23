#include<cstring>
#include<cstdio>
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
//#define int long long
// int n,m,ans;
int vis[30];
vector<int>v[30];
int ans=0;
void fun(int st,int dep){
    //de(st)
    if(dep==1){
        ans++;
        //de(ans)
        return ;
    }
    for(int i=0;i<v[st].size();i++){
        int p=v[st][i];
        if(vis[p]==1) continue;

        vis[p]=1;
        fun(p,dep-1);
        vis[p]=0;
    }
    return ;
}
int main(){
    int n;n=21;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(__gcd(i,j)==1){
                v[i].push_back(j);
                v[j].push_back(i);
                //de(i)de(j)Pu
            }
        }
    }
    vis[1]=1;
    fun(1,n);
    cout<<ans<<endl;
}