#include <bits/stdc++.h>
using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Implemented on GFG problem : 
    
    // Implementing using min heap (priority queue)
    vector<int> dist(V,1e6);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    dist[S] = 0;
    pq.push({0,S});
    
    while(!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        
        pq.pop();
        
        for(auto val : adj[node])
        {
            int edge = val[1];
            int adjnode = val[0];
            
            if(dis + edge < dist[adjnode])
            {
                dist[adjnode] = edge + dis;
                pq.push({dist[adjnode] , adjnode});
            }
        }
    }
    
    return dist;
}


vector <int> dijkstra_set(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    
    // Implementation using set data structure
    
    set<pair<int,int>> st;
    vector<int> dist(V,1e9);
    
    st.insert({0,S});
    dist[S] = 0;
    
    while(!st.empty())
    {
        auto it = *(st.begin());
        
        int node = it.second;
        int dis = it.first;
        
        st.erase(it);
        
        for(auto adjNode : adj[node])
        {
            int edgeW = adjNode[1];
            int adjn = adjNode[0];
            
            if( dis + edgeW < dist[adjn])
            {
                if(dist[adjn] != 1e9)
                    st.erase({dist[adjn],adjn});
                    
                dist[adjn] = dis + edgeW;
                st.insert({dist[adjn],adjn});
            }
        }
    }
    
    
    return dist;
}