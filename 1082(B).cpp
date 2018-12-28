#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,G=-1,S=-1,mx=-1,pos=0,flag=0,i=0,k=0;
    string ch; cin>>n; cin>>ch;
    for(int o=0,q=n-1;o<n;o++,q--){ if(ch[o]=='G'&&G==-1)G=o; if(ch[q]=='G'&&S==-1)S=q; if(G!=-1&&S!=-1)break;}
    for(int l=S;l>G;l--){
        if(ch[l]=='S'){ k++; }
        if(k>1){ flag=1; break; }
    }G=0; S=0;
    if(n==2){
        for(i=0;i<n;i++){if(ch[i]=='G')G++;}
        cout<<G<<endl; return 0;
    }
    while(i<n-1){
        G=0; S=0;
        for(i=pos;i<n;i++){
            if(ch[i]=='S') { S++; if(S==1){ pos=i+1; } }
            if(ch[i]=='G' || S<2 ){ G++; }
            if(S>1){ break; }
        }
        if((flag==0&&S!=0) || G==1){
            G--;
        }
        if(G>mx){ mx=G; }
    }
    cout<<mx<<endl;
    return 0;
}
