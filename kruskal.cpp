class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<vector<int>>edges;
        for(int i=0;i<V;i++){
            for(auto &it:adj[i]){
                int u=i,v=it[0],w=it[1];
                edges.push_back({w,u,v});
            }
        }
        sort(edges.begin(),edges.end());
        DisjointSet ds(V);
        int res=0;
        for(auto &it:edges){
            int w=it[0],u=it[1],v=it[2];
            if(ds.findUPar(u)!=ds.findUPar(v)){
                res+=w;
                ds.unionBySize(u,v);
            }
            else{
                
            }
        }
        
        return res;
    }
};
