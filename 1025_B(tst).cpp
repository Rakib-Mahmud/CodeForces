#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[150001];
int b[150001];
ll lcm (ll a, ll b) {
    return (a*b) / __gcd(a, b);
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    ll gc;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if (i == 0) {
            gc = lcm (a[i], b[i]);
            continue;
        }
        gc = __gcd (gc, lcm(a[i], b[i]));
    }
    for (int i = 0; i < n; i++) {
        ll p = __gcd (gc, (ll)a[i]);
        ll q = __gcd (gc, (ll)b[i]);
        if (p > 1) gc = p;
        else gc = q;
    }
    if (gc > 1) cout << gc;
    else cout << "-1";

}
