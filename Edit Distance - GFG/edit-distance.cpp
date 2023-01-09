//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int solveTabSO(string& a, string& b) {
        
        vector<int> curr(b.length() + 1, 0);
        vector<int> next(b.length() + 1, 0);

        for(int j = 0; j < b.length(); j++) {
            next[j] = b.length() - j;
        }

        for(int i = a.length()-1; i >= 0; i--) {
            for(int j = b.length()-1; j >= 0; j--) {

                //catch here -> base case se mila ye
                curr[b.length()] = a.length() - i;

                int ans = 0;
                if(a[i] == b[j]) {
                    ans = next[j+1];
                }
                else {
                    //insert
                    int insertAns = 1 + curr[j+1];
                    //delete
                    int deleteAns = 1 + next[j];
                    //replace
                    int replaceAns = 1 + next[j+1];

                    ans = min(insertAns, min(deleteAns, replaceAns));
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    
  public:
    int editDistance(string word1, string word2) {
        if(word1.length() == 0)
            return word2.length();

        if(word2.length() == 0)
            return word1.length();
        
        return solveTabSO(word1, word2);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends