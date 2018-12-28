#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m,x1,y1,x2,y2,x3,y3,x4,y4,t,blk,whit,total,l,r,u,b,L,R,T,B;
    cin>>t;
    while(t--){
        blk=0; whit=0; total=0; l=0; b=0; u=0; r=0; L=0; R=0; T=0; B=0;
        cin>>n>>m;
        cin>>x1>>y1>>x2>>y2;
        cin>>x3>>y3>>x4>>y4;
        blk=(n*m)/2; whit=(n*m)-blk;
        total=((x2-x1+1)*(y2-y1+1));
        if((x1%2==0 && y1%2==0)||(x1%2!=0 && y1%2!=0)){
            blk-=(total/2); whit+=(total/2);
        }
        else{
            whit+=(total%2==0?(total/2):((total/2)+1)); blk-=(total%2==0?(total/2):((total/2)+1));
        }
        l=max(x1,x3); r=min(x2,x4); u=max(y1,y3); b=min(y2,y4);
        if(l<=r && u<=b){
            total=(r-l+1)*(b-u+1);
            L=(l-x3)*(y4-y3+1); B=(u-y3)*(x4-x3+1);
            T=(y4-b)*(x4-x3+1); R=(x4-r)*(y4-y3+1);
            if(L!=0){ B=(B==0?B:(B-(max(y1,y3)-min(y1,y3))*(max(x1,x3)-min(x1,x3)))); T=(T==0?T:(T-(max(y2,y4)-min(y2,y4))*(max(x1,x3)-min(x1,x3)))); }
            if(R!=0){ B=(B==0?B:(B-(max(y1,y3)-min(y1,y3))*(max(x2,x4)-min(x2,x4)))); T=(T==0?T:(T-(max(y2,y4)-min(y2,y4))*(max(x2,x4)-min(x2,x4)))); }
            if(L!=0){
               if((x3%2==0 && y3%2==0)||(x3%2!=0 && y3%2!=0)){
                    whit-=(L%2==0?(L/2):((L/2)+1)); blk+=(L%2==0?(L/2):((L/2)+1));
                }
                else{
                    whit-=(L/2); blk+=(L/2);
                }
                if(B!=0){
                    if((x1%2==0 && y3%2==0)||(x1%2!=0 && y3%2!=0)){
                    whit-=(B%2==0?(B/2):((B/2)+1)); blk+=(B%2==0?(B/2):((B/2)+1));
                    }
                    else{
                        whit-=(B/2); blk+=(B/2);
                    }
                }
                if(T!=0){
                    if((x1%2==0 && (y2+1)%2==0)||(x1%2!=0 && (y2+1)%2!=0)){
                    whit-=(T%2==0?(T/2):((T/2)+1)); blk+=(T%2==0?(T/2):((T/2)+1));
                    }
                    else{
                        whit-=(T/2); blk+=(T/2);
                    }
                }
            }
            else{
                if(B!=0){
                if((x3%2==0 && y3%2==0)||(x3%2!=0 && y3%2!=0)){
                    whit-=(B%2==0?(B/2):((B/2)+1)); blk+=(B%2==0?(B/2):((B/2)+1));
                    }
                    else{
                        whit-=(B/2); blk+=(B/2);
                    }
                }
                if(T!=0){
                 if((x3%2==0 && y4%2==0)||(x3%2!=0 && y4%2!=0)){
                    whit-=(T%2==0?(T/2):((T/2)+1)); blk+=(T%2==0?(T/2):((T/2)+1));
                    }
                    else{
                        whit-=(T/2); blk+=(T/2);
                    }
                }
            }
            if(R!=0){
                if(((x2+1)%2==0 && (y3%2)==0)||(((x2+1)%2!=0 && (y3%2)!=0))){
                    whit-=(R%2==0?(R/2):((R/2)+1)); blk+=(R%2==0?(R/2):((R/2)+1));
                    }
                    else{
                        whit-=(R/2); blk+=(R/2);
                    }
            }
            blk+=total; whit-=total;
        }
    else{
        total=((x4-x3+1)*(y4-y3+1));
        if((x3%2==0 && y3%2==0)||(x3%2!=0 && y3%2!=0)){
            whit-=(total%2==0?(total/2):((total/2)+1)); blk+=(total%2==0?(total/2):((total/2)+1));
        }
        else{
            whit-=(total/2); blk+=(total/2);
        }
        }
    cout<<whit<<" "<<blk<<endl;
    }
    return 0;
}
