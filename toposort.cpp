//using kahn's algorithm/bfs
class Solution
{
	public:
	
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>indegree(n);
        for(int u=0;u<n;u++){
            for(int &v:adj[u]){
                indegree[v]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int>res;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(int &neigh:adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0) q.push(neigh);
            }
        }
        return res;
    }
};


//using dfs
class Solution
{
    private:
    void dfs(int node,vector<bool>&vis,vector<int> adj[],stack<int>&st){
        vis[node]=1;
        
        for(int &neigh:adj[node]){
            if(!vis[neigh]) dfs(neigh,vis,adj,st);
        }
        
        st.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool>vis(V);
	    stack<int>st;
	    for(int i=0;i<V;i++){
	        if(vis[i]==0){
	            dfs(i,vis,adj,st);
	        }
	    }
	    vector<int>res;
	    while(!st.empty()){
	        res.push_back(st.top());
	        st.pop();
	    }
	    return res;
	}
};
