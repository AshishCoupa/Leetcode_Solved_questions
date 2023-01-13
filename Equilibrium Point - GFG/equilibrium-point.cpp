//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {

        if(n == 1)
            return 1;
        
        int i = 0;
        int j = n-1;
        int sum1 = 0;
        int sum2 = 0;
        
        sum1 += a[0];
        sum2 += a[n-1];
        
        while(i < j) {
            
            if((sum1 == sum2) && (i+1 == j-1)) {
                return i + 2;
            }
            
            if(sum1 == sum2) {
                i++;
                j--;
                sum1 += a[i];
                sum2 += a[j];
                
                //cout <<"1->" << sum1 << "   " << sum2 << endl;
            }
            else if(sum1 < sum2) {
                i++;
                sum1 += a[i];
                //cout <<"2->" <<sum1 << "   " << sum2 << endl;
            }
            else {
                j--;
                sum2 += a[j];
                //cout << "3->"<<sum1 << "   " << sum2 << endl;
            }
        }
        
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends