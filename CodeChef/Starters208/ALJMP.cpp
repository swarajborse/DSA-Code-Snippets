#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        if(N%2==1) cout << N/2 + 1 << endl;
        else cout << N/2 << endl;
    }
}
