/*
Author :

███████╗████████╗ █████╗ ██████╗  ███╗   ███╗ █████╗ ███╗   ██╗
██╔════╝╚══██╔══╝██╔══██╗██╔══██╗ ████╗ ████║██╔══██╗████╗  ██║
███████╗   ██║   ███████║██████╔╝ ██╔████╔██║███████║██╔██╗ ██║
╚════██║   ██║   ██╔══██║██║  ██║ ██║╚██╔╝██║██╔══██║██║╚██╗██║
███████║   ██║   ██║  ██║██║  ██║ ██║ ╚═╝ ██║██║  ██║██║ ╚████║
╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝  STARMAN248
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<long long> a(N);
        for(int i=0;i<N;i++){
            cin >> a[i];
        }
        
        vector<pair<long long,int>> b(N);
        for(int i=0;i<N;i++){
            b[i] = {a[i], i};   
        }
        sort(b.begin(), b.end());
        vector<long long> ans(N);
        for(int i=0;i<N;i++){
            if(i==0 || i==N-1){
                ans[b[i].second] = -1; 
            } else {
                long long left = (b[i-1].first + b[i].first)/2;
                long long right = (b[i].first + b[i+1].first)/2;
                ans[b[i].second] = right - left;
            }
        }
        for(int i=0;i<N;i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        
    }
}
// Code shared for reference only. Unauthorized use or submission under my Username - Starman248 is prohibited.