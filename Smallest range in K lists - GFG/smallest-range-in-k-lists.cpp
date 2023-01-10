//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    
    class node {
      public:
        int data;
        int row;
        int col;
        
        node(int d, int r, int c) {
            data = d;
            row = r;
            col = c;
        }
    };
    
    class compare {
      public:
        bool operator() (node* a, node* b) {
            return a->data > b->data;
        }
    };
    
    public:
    pair<int,int> findSmallestRange(int a[][N], int n, int k)
    {
        int mini = INT_MAX, maxi = INT_MIN;
        priority_queue<node*, vector<node*>, compare> minHeap;
        
        //step1: create a min heap for starting element of each list and tracking mini/maxi value
        for(int i=0; i<k; i++) {
            int element = a[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);
            minHeap.push(new node(element, i, 0));
        }
        
        int start = mini, end = maxi;
        
        //process ranges
        while(!minHeap.empty()) {
            
            node* tmp = minHeap.top();
            minHeap.pop();
            
            mini = tmp->data;
            
            //range or answer updation
            if(maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }
            
            //next element exists
            if(tmp->col + 1 < n) {
                maxi = max(maxi, a[tmp->row][tmp->col + 1]);
                minHeap.push(new node(a[tmp->row][tmp->col + 1], tmp->row, tmp->col + 1));
            }
            else {
                //next element does not exist
                break;
            }
        }
        
        //returning the difference of range values
        pair<int, int> ans{start, end};
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends