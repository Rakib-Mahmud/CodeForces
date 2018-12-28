#include<bits/stdc++.h>

using namespace std;

int x[5] , y[5];
map <int , int> m;

int main()
{
	for(int i = 0 ; i < 3 ; i++)
	{
		cin >> x[i] >> y[i];
		m[x[i]] = y[i];
	}
	sort(x , x + 3);
	sort(y , y + 3);
	cout << y[2] - y[0] + x[2] - x[0] + 1 << endl;
	for(int i = x[0] ; i < x[1] ; i++)
		cout << i << " " << m[x[0]] << endl;
	for(int i = x[2] ; i > x[1] ; i--)
		cout << i << " " << m[x[2]] << endl;
	for(int i = y[0] ; i <= y[2] ; i++)
		cout << x[1] << " " << i << endl;
}
