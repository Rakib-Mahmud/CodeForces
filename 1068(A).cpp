#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    long long res;
    long double x,N,M,K,L;
    cin>>N>>M>>K>>L;
    x=((K+L)/M);
    res=ceil(x);
    if((N<M && L!=0) || ((res*M)>N) || (N==L && K!=0)){
        cout<<-1<<endl;
    }
    else{
        cout<<res<<endl;
    }
    return 0;
}
