#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<pair<int, int>> players; 

        for (int i = 1; i <= N; i++) {
            players.push_back({i, __gcd(i, N)});
        }
        sort(players.begin(), players.end(), [](auto &a, auto &b) {
            if (a.second != b.second)
                return a.second > b.second; 
            return a.first < b.first;
        });

        for (auto &p : players)
            cout << p.first << " ";
        cout << "\n";
    }
    return 0;
}
