#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T;
    cin >> T;
    while(T--){
        int N,X;
        cin >> N >> X;
        if(X > N) {
            cout << 0 << "\n";
        } else {
            int profit = (N*(N+1))/2 - ((X-1)*X)/2 - X*(N - X + 1);
            cout << profit << "\n";
        }
    }
}
// Code shared for reference only. Unauthorized use or submission under my Username - Starman248 is prohibited.