//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    int solveTab(int weight[], int value[], int n, int capacity) {
    
    //step1:
    vector<int> curr(capacity+1, 0);
    
    //step2: Analyse Base Case
    for(int w = weight[0]; w <= capacity; w++) {
        if(weight[0] <= capacity)
            curr[w] = value[0];
        else
            curr[w] = 0;
    }
    
    //step3: take care of remaining recursive calls    
    for(int index = 1; index < n; index++) {
        for(int w = capacity; w >= 0; w--) {
            int include = 0;
            if(weight[index] <= w)
                include = value[index] + curr[w-weight[index]];

            int exclude = curr[w];

            curr[w] = max(include, exclude);
        }
    }
    return curr[capacity];                                           
}
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       return solveTab(wt, val, n, W);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends