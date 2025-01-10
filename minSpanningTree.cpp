//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    typedef pair<int,int>p;
    // Function to find sum of weights of edges of the Minimum Spanning Tree.'
     // tc-O(ElogE+ElogE) = O(ElogE)
     // sc=O(E+V)
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,0});
        vector<bool>vis(V);
        
        int sum=0;
        while(!pq.empty()){
            int w=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            if(vis[node]) continue;
            vis[node]=1;
            sum+=w;
            
            for(auto &neigh:adj[node]){
                int v=neigh[0];
                int wt=neigh[1];
                if(vis[v]==0) pq.push({wt,v});
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
