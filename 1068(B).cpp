#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    long long b,res=0,r;
    cin>>b;
    r=sqrt(b);
    for(long long i=1;i<=r;i++){
        if(b % i==0){
            if(b/i==i){ res++; }
            else{ res+=2; }
        }
    }
    cout<<res<<endl;
    return 0;
}
