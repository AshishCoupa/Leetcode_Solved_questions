//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define MOD 1000000007

class Solution {
  public:
    long long int nthFibonacci(long long int n){
        long long int prev1 = 1;
        long long int prev2 = 0;
        
        for(long long int i=2; i<=n; i++) {
            long long int curr = ((prev1 % MOD) + (prev2 % MOD)) % MOD;
            prev2 = prev1;
            prev1 = curr;
        }
        
        if(n == 0) {
            return prev2;
        }
        else {
            return prev1;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends