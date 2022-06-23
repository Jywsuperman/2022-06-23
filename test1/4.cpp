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
typedef long long ll;
const int N=1e6+10;
const int inf=0x3f3f3f3f,mod=1e9+7;
// #define int long long
int n,m;
int a[N];
ll ans;
bool cmp(int a,int b){
    return a>b;
}
void fun(){
    int cnt=1;
    while(cnt*cnt<=m) cnt++;
    cnt--;

    m=m-cnt*cnt;
    for(int i=1;i<=cnt;i++){
        ans+=a[i]*cnt*2;
    }
    if(m==0) return ;

    for(int i=1;i<=cnt;i++){
        ans+=a[i]+a[cnt+1];
        m--;
        if(m==0) return ;

        ans+=a[i]+a[cnt+1];
        m--;
        if(m==0) return ;
    }
    ans+=a[cnt+1]*2;
    m--;
    if(m==0) return ;
}
int main(){
   cin>>n>>m;
   for(int i=1;i<=n;i++){
       scanf("%d",&a[i]);
   }
   sort(a+1,a+n+1,cmp);
   fun();
   de(ans)
}