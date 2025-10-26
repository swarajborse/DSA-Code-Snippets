/*
Problem link:- https://codeforces.com/contest/2078/problem/B
*/

#include <bits/stdc++.h>
// #ifdef LOCAL
// #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
// #else
// #define dbg(...)
// #endif
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define wh(t) while (t--)
#define fi(n) for (ll i = 0; i < n; i++)
#define fj(n) for (ll j = 0; j < n; j++)
#define fu(i, s, e) for (ll i = s; i <= e; i++)
using namespace std;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vll a(n + 1, 0);
    a[n - 1] = n;
    a[n] = n - 1;
    fu(i, 1, n - 2)
    {
        if (k % 2 == 1)
            a[i] = n;
        else
            a[i] = n - 1;
    }
    // cout << "Ans: ";
    fi(n)
    {
        cout << a[i + 1] << " ";
    }
    cout << "\n";
}

int main()
{
    ll t;
    t = 1;
    cin >> t;
    wh(t)
    {
        solve();
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}