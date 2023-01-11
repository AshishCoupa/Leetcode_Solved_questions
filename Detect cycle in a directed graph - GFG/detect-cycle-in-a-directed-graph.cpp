//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> edges[]) {
        //create adj list
        unordered_map<int, list<int> > adj;
        for(int i=0; i<n; i++) {
            int u = i;
            for(int j=0; j<edges[i].size(); j++) {
                int v = edges[i][j];
                adj[u].push_back(v);
            }
        }
        
        //find all indegrees
        vector<int> indegree(n);
        for(auto i : adj) {
            for(auto j : i.second) {
                indegree[j]++;
            }
        }
        
        //0 indegree walon ko push karo
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        //do bfs
        int count = 0;
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            
            //increase count
            count++;
            
            //neighbour indegree update
            for(auto neighbour : adj[front]) {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }
        if(count == n)
            return false;
        else
            return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends