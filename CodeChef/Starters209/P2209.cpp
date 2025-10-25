#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T;
    cin >> T;
    while(T--){
        int X,Y;
        cin >> X >> Y;
        vector<int>divisors;
        for(int i=X;i<=Y;i++){
            if(i%X==0) divisors.push_back(i);
        }
        int evenCount = 0 , oddCount = 0;
        for(int num : divisors){
            if(num%2==0) evenCount++;
            else oddCount++;
        }
        if(evenCount >= oddCount) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
}
