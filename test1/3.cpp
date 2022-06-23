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
const int N=1e3+10;
const int inf=0x3f3f3f3f,mod=1e9+7;
// #define int long long
ll n,m,ans;
ll a[N];
void init(){
    a[1]=0;
    a[2]=9;
    for(ll i=3;i<=20;i++){
        a[i]=(i-1+a[i-1])*9;
        //de(a[i])
    }
}
string fun(string a,string b){
    string c="",tt="";
    int l=a.size(),r=b.size();
    if(l>r){
        for(int i=1;i<=abs(l-r);i++){
            tt+='0';
        }
        b=tt+b;
    }else if(l<r){
        for(int i=1;i<=abs(l-r);i++){
            tt+='0';
        }
        a=tt+a;
    }
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int yv=0,tmp;
    for(int i=0;i<max(l,r);i++){
        tmp=(a[i]-'0')+(b[i]-'0')+yv;
        c+=(tmp%10)+'0';
        yv=tmp/10;
    }
    while(yv){
        c+=(yv%10)+'0';
        yv/=10;
    }
    reverse(c.begin(),c.end());
    return c;
}
int main(){
    cin>>n;
    init();
    string s1,s2;
    s2="0";
    if(n%2==1){
        printf("0\n");
        return 0;
    }else{
        string s;
        s=to_string(n);
        ll len=s.size(),tmp,k;
        // string s1,s2;
        for(ll i=0;i<len;i++){
            k=(s[i]-'0');
            tmp=(len-i-1+a[len-i-1])*k;
            s1=to_string(tmp);
            s2=fun(s1,s2);
        }
    }
    de(s2)
}