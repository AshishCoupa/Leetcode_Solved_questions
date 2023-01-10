//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    class node {
        public:
            int data;
            int row;
            int col;
            
            node(int data, int row, int col) {
                this->data = data;
                this->row = row;
                this->col = col;
            }
    };
    
    class compare {
      public:
        bool operator() (node* a, node* b) {
            return a->data > b->data;
        }
    };
    
    
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> &kArrays, int k)
    {
        priority_queue<node*, vector<node*>, compare> minHeap;
    
        //step1: saare array k first elements insert hain
        for(int i=0; i<k; i++) {
            node* tmp = new node(kArrays[i][0], i, 0);
            minHeap.push(tmp);
        }
        
        vector<int> ans;
        
        //step2:
        while(!minHeap.empty()) {
            node* tmp = minHeap.top();
            minHeap.pop();
            
            ans.push_back(tmp->data);
            
            int row = tmp->row;
            int col = tmp->col;
            
            if(col+1 < kArrays[row].size()) {
                node* next = new node(kArrays[row][col+1], row, col+1);
                minHeap.push(next);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends