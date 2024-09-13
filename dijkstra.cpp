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
