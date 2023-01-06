//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    long long solveTabSO(int d, int faces, int t) {
        
        vector<long long> prev(t+1, 0);
        vector<long long> curr(t+1, 0);
        //after analysig base case
        prev[0] = 1;
        
        for(int dice = 1; dice <= d; dice++) {
            for(int target = 1; target <= t; target++) {
                
                long long ans = 0;    
                for(int i = 1; i <= faces; i++) {
                    if(target - i >= 0) {
                        ans = ans + prev[target - i];
                    }
                }
                curr[target] = ans;
            }
            
            prev = curr;
        }
        
        return prev[t];
    }
  public:
    long long noOfWays(int M , int N , int X) {
        
        return solveTabSO(N, M, X);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends