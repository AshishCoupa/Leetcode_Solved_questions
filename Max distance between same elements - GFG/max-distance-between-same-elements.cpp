//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    // your task is to complete this function
    int maxDistance(int arr[], int n)
    {
        unordered_map<int, pair<int, int> > um;
        
        for(int i=0; i<n; i++) {
            
            if(um.find(arr[i]) == um.end()) {
                um[arr[i]] = make_pair(i, 0);
            }
            else {
                um[arr[i]].second = i;
            }
        }

        int maxi = INT_MIN;
        
        for(auto i : um) {
            int diff = i.second.second - i.second.first;
            maxi = max(maxi, diff);
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.maxDistance(arr,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends