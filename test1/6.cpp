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
const int N=2e5+10;
const int inf=0x3f3f3f3f,mod=1e9+7;
// #define int long long
int n,m,ans;
int lie[N];
int ok(int x){
    for(int i=1;i<x;i++){
        if(abs(x-i)==abs(lie[x]-lie[i])||lie[i]==lie[x]) return 0;
    }
    return 1;
}
void fun(int x){
    if(x>n){
        ans++;
        return ;
    }
    for(int i=1;i<=n;i++){
        lie[x]=i;
        if(ok(x)) fun(x+1);
    }
}
int main(){
    while(cin>>n&&n){
        ans=0;
        fun(1);
        printf("%d\n",ans);
    }
    return 0;
}
