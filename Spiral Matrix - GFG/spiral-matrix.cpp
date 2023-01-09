//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &matrix, int n, int m, int k)
    {
        int ans;
        int counter = 0;
        
        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;

        while(left <= right and top <= bottom)
        {
            
            for(int i=left; i<=right; i++)
            {
                counter++;
                if(counter == k)
                    return matrix[top][i];
            }
            top++;

            for(int i=top; i<=bottom; i++)
            {
                counter++;
                if(counter == k)
                    return matrix[i][right];
            }
            right--;

            if(top <= bottom)
            {
                for(int i=right; i>=left; i--)
                {
                    counter++;
                    if(counter == k)
                        return matrix[bottom][i];
                }
            }
            bottom--;

            if(left <= right)
            {
                for(int i=bottom; i>=top; i--)
                {
                    counter++;
                    if(counter == k)
                        return matrix[i][left];
                }
            }
            left++;
        }
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends