#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,tp,ls,sum1=0,sum2=0,tmp=0,flg=0,tp2=0,ls2=0,sum=0;
    char ch[100];
    cin>>n;
    cin>>ch;
    sum1=ch[0]-'0';
    sum2=ch[n-1]-'0';
    if(n==2){ if(sum1==sum2){cout<<"YES\n";} else{cout<<"NO\n"; } return 0;}
    tp=0; ls=n-1;
    while(1){
        if(ls-tp==1 && sum1!=sum2){
            if(tmp==0){
                cout<<"NO\n"; return 0;
            }
            break;
        }
        else if(ls-tp==1 && sum1==sum2){cout<<"YES\n"; return 0;}
        if(sum1>sum2){
            ls--;
            sum2=sum2+(ch[ls]-'0');
        }
        else if(sum1<sum2){
            tp++;
            sum1=sum1+(ch[tp]-'0');
        }
        else{
            tmp=sum1; tp2=tp; ls2=ls;
            ls--; tp++; if(ls==tp){ ls++; sum1=sum1+(ch[tp]-'0');}
            else{
            sum2=sum2+(ch[ls]-'0');
            sum1=sum1+(ch[tp]-'0');
            }
        }
    }
        for(int i=tp2+1;i<ls2;i++){
            if(sum==tmp){ sum=0; }
            else if(sum<tmp){ sum+=ch[i]-'0';}
            else{ cout<<"NO\n"; return 0;}
        }
    if(sum==tmp){ cout<<"YES\n";}
    else{cout<<"NO\n";}
    return 0;
}
