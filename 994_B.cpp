#include<bits/stdc++.h>
#define mx 100001
#define ll long long int
using namespace std;

struct node{
    ll coin;
    ll indx;
};
struct Compare {
    bool operator()(pair<ll, ll> const & a,
                              pair<ll, ll> const & b)
    { return a.first < b.first; }
};


bool myComparison(const pair<ll,node> &a,const pair<ll,node> &b)
{
       return a.first>b.first;
}

bool myComparison2(const pair<ll,node> &a,const pair<ll,node> &b)
{
       return a.second.indx<b.second.indx;
}

bool myComparison3(const pair<ll,node> &a,const pair<ll,node> &b)
{
       return a.second.coin>b.second.coin;
}

int main()
{
    ll n,c,k,powr[mx],coin[mx],nxt=0;
    vector<pair<ll,node> >vec1,vec2;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,Compare> Q,tmp;
    scanf("%lld%lld",&n,&k);
    for(ll i=0;i<n;i++){
        scanf("%lld",&powr[i]);
    }
    for(ll i=0;i<n;i++){
        scanf("%lld",&coin[i]);
    }
    for(ll i=0;i<n;i++){
        node nd; nd.coin=coin[i]; nd.indx=i;
        vec1.push_back(make_pair(powr[i],nd));
        vec2.push_back(make_pair(powr[i],nd));
    }
    if(k==0){
        for(ll i=0;i<n;i++){
        i==0?printf("%lld",vec1[i].second.coin):printf(" %lld",vec1[i].second.coin);
    }
    printf("\n");return 0;
    }
    sort(vec1.begin(),vec1.end(),myComparison);ll kk=0;
    sort(vec2.begin(),vec2.end(),myComparison3);
    for(ll q=0;;q++){if(nxt==k){nxt=q-1; break;} if(vec2[q].first!=vec1[0].first){Q.push(make_pair(vec2[q].first,vec2[q].second.coin));nxt++;}}
    for(ll i=0;i<n-2;i++){
        if(vec1[i].first<=Q.top().first){
            while(!Q.empty()&&vec1[i].first<=Q.top().first){Q.pop();} nxt++;
            while(vec1[i].first<=vec2[nxt].first&&nxt<n){ nxt++; }
            while(Q.size()<k&&nxt<n){
            if(vec1[i].first<=vec2[nxt].first){nxt++; continue;}
            Q.push(make_pair(vec2[nxt].first,vec2[nxt].second.coin));nxt++;}
            if(Q.size()==k){nxt--;}
        }
        for(ll j=0;j<k&&!Q.empty();j++){
            vec1[i].second.coin+=Q.top().second;
            pair<ll,ll> m;
            m=Q.top(); tmp.push(make_pair(m.first,m.second)); Q.pop();
        }
        for(ll j=0;j<k&&!tmp.empty();j++){
            pair<ll,ll> m;
            m=tmp.top(); Q.push(make_pair(m.first,m.second)); tmp.pop();
        }
    }
    k==0? :vec1[n-2].second.coin+=vec1[n-1].second.coin;
    sort(vec1.begin(),vec1.end(),myComparison2);
    for(ll i=0;i<n;i++){
        i==0?printf("%lld",vec1[i].second.coin):printf(" %lld",vec1[i].second.coin);
    }
    printf("\n");
    return 0;
}
