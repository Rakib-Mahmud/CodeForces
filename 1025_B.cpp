#include<bits/stdc++.h>
#define ll long long int
#define mx 150001
using namespace std;
ll input[2*mx];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,ans1,ans2,flg=0;
    cin>>n;
    for(ll i=0;i<2*n;i++){
        cin>>input[i];
    }
    if(n==1){ cout<<input[0]<<"\n"; return 0;}
    ll result = input[0];
    for (ll i = 2; i < 2*n; ){
        ans1 = __gcd(input[i], result);
        ans2 = __gcd(input[i+1], result);
        if((ans1>ans2 && (ans1%ans2!=0)&&(i+1)!=(2*n-1)) || (ans1<ans2 && (ans2%ans1!=0)&&(i+1)!=(2*n-1))){ result=ans1*ans2; i=i+2; continue; }
        if(ans1>ans2 && ans1!=1){ result=ans1; } else if(ans1>ans2 && ans1==1) result=ans2;
        else if(ans1<ans2 && ans2!=1){ result=ans2; } else if(ans1<ans2 && ans2==1) result=ans1;
        else if(ans1==ans2 && ans1!=1){ result=ans1; } else { flg=1; break;}
        i=i+2;
    }

    if(flg==1){
        result = input[1];
        for (ll i = 2; i < 2*n; ){
        ans1 = __gcd(input[i], result);
        ans2 = __gcd(input[i+1], result);
        if((ans1>ans2 && (ans1%ans2!=0)&&(i+1)!=(2*n-1)) || (ans1<ans2 && (ans2%ans1!=0)&&(i+1)!=(2*n-1))){ result=ans1*ans2; i=i+2; continue; }
        if(ans1>ans2 && ans1!=1){ result=ans1; } else if(ans1>ans2 && ans1==1) result=ans2;
        else if(ans1<ans2 && ans2!=1){ result=ans2; } else if(ans1<ans2 && ans2==1) result=ans1;
        else if(ans1==ans2 && ans1!=1){ result=ans1; } else { result=1; break;}
        i=i+2;
    }
    }

    if(result!=1){
        if(result%2==0){ result=2; }
        else if(result%3==0){ result=3; }
        else if(result%5==0){ result=5; }
        else if(result%7==0){ result=7; }
        cout<<result<<"\n"; return 0;
    }
    else{
        cout<<"-1\n";
    }
    return 0;
}
