#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    map <int , int> mp;
    int x,y,p=0;
    int out_x[100001],out_y[100001],in_x[4],in_y[4];
    cin>>in_x[0]>>in_y[0]>>in_x[1]>>in_y[1]>>in_x[2]>>in_y[2];
    mp[in_x[0]]=in_y[0]; mp[in_x[1]]=in_y[1]; mp[in_x[2]]=in_y[2];
    sort(in_x,in_x+3); sort(in_y,in_y+3);
    x=in_x[0]; y=mp[in_x[0]];
    while(x<in_x[1]){
        out_x[p]=x; out_y[p]=y;
        p++; x++;
    }
    x=in_x[1]; y=in_y[0];
    while(y<=in_y[2]){
        out_x[p]=x; out_y[p]=y;
        p++; y++;
    }
    x=in_x[2]; y=mp[in_x[2]];
    while(x>in_x[1]){
        out_x[p]=x; out_y[p]=y;
        p++; x--;
    }
    cout<<p<<endl;
    for(int i=0;i<p;i++){
        cout<<out_x[i]<<" "<<out_y[i]<<endl;
    }
    return 0;
}
