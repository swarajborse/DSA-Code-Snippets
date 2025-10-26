/*
Problem link:- https://codeforces.com/contest/2069/problem/B
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
#define pb push_back
#define mll map<ll, ll>
using namespace std;

bool helper(const vvll &a, ll i, ll j, ll n, ll m)
{
    if (j + 1 < m && a[i][j] == a[i][j + 1])
        return true;
    if (i + 1 < n && a[i][j] == a[i + 1][j])
        return true;
    return false;
}
void funksolve()
{

    ll n, m;
    cin >> n >> m;

    vvll a(n, vll(m, 0));
    map<ll, bool> vis;
    mll cnt;
    fi(n)
    {
        fj(m)
        {
            cin >> a[i][j];
            cnt[a[i][j]]++;
        }
    }

    if (n == 1 && m == 1)
    {
        cout << "0\n";
        return;
    }

    fi(n)
    {
        fj(m)
        {
            if (helper(a, i, j, n, m))
                vis[a[i][j]] = true;
        }
    }

    ll tot(0), ans(0);

    for (const auto &x : cnt)
    {
        ll temp;
        if (vis[x.first])
            temp = 2;
        else
            temp = 1;
        tot += temp;
        ans = max(ans, temp);
    }

    cout << tot - ans << "\n";
}

int main()
{
    ll t;
    t = 1;
    cin >> t;
    wh(t)
    {
        funksolve();
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}