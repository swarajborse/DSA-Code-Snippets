/*
Problem link:- https://codeforces.com/contest/2090/problem/D
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
#define fd(i, s, e) for (ll i = s; i >= e; i--)
#define pb push_back

using namespace std;

bool iprr(int n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void solve()
{
    ll n;
    cin >> n;
    ll npp(0);
    ll c(n / 3);
    if (c < 2)
        c = 2;
    ll llr(c);
    ll hsr(c);
    ll d(1);
    while (!iprr(llr) && (llr >= 2))
        llr--;
    while ((hsr <= n) && !iprr(hsr))
        hsr++;
    if (llr < 2)
        npp = hsr;
    if (hsr > n)
        npp = llr;
    if (abs(c - llr) <= abs(c - hsr))
    {
        npp = llr;
    }
    else
        npp = hsr;

    vll bucket;
    vll usd(n + 1, 0);
    bucket.pb(npp);
    usd[npp] = 1;
    while (1)
    {
        ll xx(npp - d), yy(npp + d);

        if (xx < 1 && yy > n)
            break;
        if (xx >= 1 && !usd[xx])
        {
            bucket.pb(xx);
            usd[xx] = 1;
        }
        if (yy <= n && !usd[yy])
        {
            bucket.pb(yy);
            usd[yy] = 1;
        }
        d++;
    }
    vll ans = bucket;
    fu(i, 1, n)
    {
        if (!usd[i])
            ans.pb(i);
    }
    fi(n) cout << ans[i] << " ";
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