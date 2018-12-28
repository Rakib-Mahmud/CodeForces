#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,r,crnt_point=0,res=0,rang=0,total_one=0,flg=0,h=0,l=0;
    int input[1001],ara[1001];
    cin>>n>>r;
    for(int i=0;i<n;i++){
         cin>>input[i];
         if(input[i]==1){
            ara[total_one]=i+1;
            total_one++;
         }
    }
    rang=r-1;
    if(total_one==0 || (ara[0]-rang>1) || (ara[total_one-1]+rang<n)){
        cout<<-1<<endl; return 0;
    }
    else{
        if(total_one==1){ cout<<1<<endl; return 0; }
        if(total_one==2){
              if(ara[0]+rang>=n || ara[1]-rang<=1){ cout<<1<<endl; }
              else if(ara[1]-ara[0]<=2*rang){ cout<<2<<endl; }
              else { cout<<-1<<endl; } return 0;
        }
    }
    while(1){
        if(crnt_point==n){ cout<<1<<endl; return 0; }
        if(ara[crnt_point]-rang<=1 ){ crnt_point++; }
        else{ crnt_point--; break; }
    }
        if(total_one-(crnt_point+1)<2){
            if(ara[crnt_point]+rang>=n){ cout<<1<<endl; }
            else if(total_one-(crnt_point+1)>=1 && ara[crnt_point+1]+rang>=n){ cout<<2<<endl; }
            return 0;
        }
        res++; l=crnt_point; h=crnt_point+1;
    while(1){
        if((ara[crnt_point]+rang)>=n){ break; }
        else{
            if(flg>0){ l++; h++; }
        }
        if(ara[h]-ara[l]>(2*rang+1) && h<total_one){
            cout<<-1<<endl; return 0;
        }
        flg+=ara[h]-ara[l];
        if(flg==2*rang+1){
            res++;
            crnt_point=h; l=crnt_point; h=crnt_point+1;
            flg=0;
        }
        else if(flg>2*rang+1){
            res++;
            crnt_point=l; l=crnt_point; h=crnt_point+1;
            flg=0;
        }
    }
    cout<<res<<endl;
    return 0;
}
