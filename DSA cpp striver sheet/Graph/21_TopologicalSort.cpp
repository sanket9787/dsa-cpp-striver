#include <bits/stdc++.h>
class Solution {
  public:
    void DFS(int node, vector<int> &vis, vector<int> &st, vector<vector<int>>& adj){
        
        vis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                DFS(it, vis, st, adj);
            }
        }
        
        st.push_back(node);
        return;
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        //stack<int> st;
        vector<int> vis(V,0);
        vector<vector<int>> adj(V);
        vector<int> st;
        
        for(int i =0 ; i<edges.size(); i++){
            int first = edges[i][0], second = edges[i][1];
            adj[first].push_back(second);
        }
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                DFS(i, vis, st, adj);
            }
        }
        
        reverse(st.begin(), st.end());
        return st;
        
    }
};