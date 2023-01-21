//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int pairCubeCount(int n) {
        
        int count = 0;
        for(int i = 1; i <= cbrt(n); i++) {
            
            int cb = i*i*i;
    
            int diff = n - cb;
    
            int cbDiff = cbrt(diff);
    
            if(cbDiff*cbDiff*cbDiff == diff)
                count++;
        }
    
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.pairCubeCount(N) << endl;
    }
    return 0;
}
// } Driver Code Ends