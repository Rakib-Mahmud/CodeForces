#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    long long int n,num=0,ln,sum=0,res,i=0,no1=0,no2=0;
    char str[100],s[100];
    cin>>str;
    if(strlen(str)<2){
        cout<<str<<endl;
    }
    else{
        ln=strlen(str);
        for(i=0 ; i<ln-1 ; i++){
            s[i] = '9';
        } s[i]='\0';
        stringstream geek1(str); geek1>>no1;
        stringstream geek2(s); geek2>>no2;
        num=no1-no2;
        while (num != 0)
       {
        sum = sum + num % 10;
        num = num / 10;
       }
       res=((ln-1)*9)+sum;
       cout<<res<<endl;
    }
    return 0;
}
