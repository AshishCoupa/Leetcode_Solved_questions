//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    vector<long long> nextSmallerElements(long long arr[], long long  n) {
        stack<long long> s;
        s.push(-1);

        vector<long long> ans(n);

        for(long long i=n-1; i>=0; i--) {
            long long curr = arr[i];

            while(s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }

    vector<long long> prevSmallerElements(long long arr[], long long n) {
        stack<long long> s;
        s.push(-1);

        vector<long long> ans(n);

        for(long long i=0; i<n; i++) {
            long long curr = arr[i];

            while(s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long heights[], int n)
    {
        vector<long long> next(n);
        next = nextSmallerElements(heights, n);

        vector<long long> prev(n);
        prev = prevSmallerElements(heights, n);

        long long area = INT_MIN;

        for(long long i=0; i<n; i++) {
            long long l = heights[i];

            if(next[i] == -1) {
                next[i] = n;
            }

            long long b = next[i] - prev[i] - 1;
            long long newArea = l*b;
            area = max(area, newArea);
        }

        return area;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends