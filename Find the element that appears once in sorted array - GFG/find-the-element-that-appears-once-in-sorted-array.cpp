//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        if(n == 1)
            return arr[0];
            
        int count = 1;
        for(int i=1; i<n; i++) {
            if(arr[i] == arr[i-1]) {
                count++;
            }
            else {
                if(count == 1)
                    return arr[i-1];
                count = 1;
            }
        }
        
        return arr[n-1];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends