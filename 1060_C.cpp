#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll row[2001][2001],column[2001][2001];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,one[2001],two[2001],x1=0,y1=0,x2,y2;
    ll x,sum=0,tmp1,tmp2,tmp3,tmp4;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>one[i];
    for(int i=0;i<m;i++)cin>>two[i];
    cin>>x; x2=n-1; y2=m-1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            sum+=one[j]*two[i];
            row[i][j]=sum;
        }
    } sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sum+=one[i]*two[j];
            column[j][i]=sum;
        }
    }
    while(sum>x){
        tmp1=row[x2][y2-1]; tmp2=sum-row[x2][y1];
        tmp3=column[x2-1][y2]; tmp4=sum-column[x1][y2];
        if(tmp1<tmp2&&tmp1<tmp3&&tmp1<tmp4){
            y2--; sum=tmp1;
        }
        else if(tmp2<tmp1&&tmp2<tmp3&&tmp2<tmp4){
            y1++; sum=tmp2;
        }
        else if(tmp3<tmp1&&tmp3<tmp2&&tmp3<tmp4){
            x2--; sum=tmp3;
        }
        else{
            x1++; sum=tmp4;
        }
    }
    int res=(x2-x1+1)*(y2-y1+1);
    cout<<res<<endl;
    return 0;
}
