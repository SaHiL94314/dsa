//using kahn's algorithm/bfs
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>dist(V,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minpq;
        minpq.push({0,S});
        dist[S]=0;
        
        while(!minpq.empty()){
            int d=minpq.top().first;
            int node=minpq.top().second;
            minpq.pop();
            
            if(d!=dist[node]) continue;
            for(auto &it:adj[node]){
                int v=it[0];
                int w=it[1];
                if(d+w<dist[v]){
                    dist[v]=d+w;
                    minpq.push({d+w,v});
                }
            }
        }
        return dist;
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
