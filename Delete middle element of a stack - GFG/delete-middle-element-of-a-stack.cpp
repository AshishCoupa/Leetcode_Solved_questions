//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    
    void solve(stack<int>&inputStack, int count, int size) {
        if(count == size/2) {
            inputStack.pop();
            return;
        }
        
        int num = inputStack.top();
        inputStack.pop();
        
        solve(inputStack, count+1, size);
        
        inputStack.push(num);
    }
    
    void deleteMid(stack<int>&inputStack, int N)
    {
        int count = 0;
        solve(inputStack, count, N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends