//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int leftMost(int arr[], int n, int k) {
    
    int index = -1;
    
    int s = 0;
    int l = n-1;
    int mid = s + (l - s)/2;
    
    while(s <= l)
    {
        if(arr[mid] == k) {
            index = mid;
            l = mid - 1;
        }
        else if(arr[mid] < k) {
            s = mid + 1;
        }
        else {
            l = mid - 1;
        }
        
        mid = s + (l - s)/2;
    }
    
    return index;
}

int rightMost(int arr[], int n, int k) {
    
    int index = -1;
    
    int s = 0;
    int l = n-1;
    int mid = s + (l - s)/2;
    
    while(s <= l)
    {
        if(arr[mid] == k) {
            index = mid;
            s = mid + 1;
        }
        else if(arr[mid] < k) {
            s = mid + 1;
        }
        else {
            l = mid - 1;
        }
        
        mid = s + (l - s)/2;
    }
    
    return index;
}
vector<int> find(int arr[], int n , int k )
{
    vector<int> result(2);
    
    result[0] = leftMost(arr, n, k);
    result[1] = rightMost(arr, n, k);
    
    return result;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends