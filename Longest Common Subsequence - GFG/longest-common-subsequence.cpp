//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    int solveTabSO(string& a, string& b) {
        
        vector<int> curr(b.length() + 1, 0);
        vector<int> next(b.length() + 1, 0);

        for(int i = a.length()-1; i >= 0; i--) {
            for(int j = b.length()-1; j >= 0; j--) {
                int ans = 0;
                if(a[i] == b[j]) {
                    ans = 1 + next[j+1];
                }
                else {
                    ans = max(next[j], curr[j+1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }

        return next[0];
    }    
    
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        return solveTabSO(s1, s2);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends