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
const int N=(1<<21)+10;
const int inf=0x3f3f3f3f,mod=998244353;
//#define int long long
//int n,m,ans;
ll d[N][25];
ll a[25][25];
int main(){
    for(int i=1;i<=21;i++){
        for(int j=i+1;j<=21;j++){
            if(__gcd(i,j)==1){
                a[i][j]=a[j][i]=1;
            }
        }
    }
    //memset(d,0,sizeof(d));
    d[1][0]=1;
    for(int i=0;i<(1<<21);i++){
        for(int u=0;u<=20;u++){
            if(((i>>u)&1)==0) continue;
            for(int v=0;v<=20;v++){
                if(((i^(1<<u)>>v)&1)==0) continue;
                //d[i][v]=max(d[i][v],d[i-(1<<v)][u]+a[u][v]);
                if(a[u+1][v+1]){
                    d[i][u]+=d[i-(1<<u)][v];
                    //de(d[i][v])
                }
            }
        }
    }
    ll ans=0;
    for(int i=0;i<=20;i++) ans+=d[(1<<21)-1][i];
    cout<<ans<<endl;
    return 0;
}