class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //create adj list
        vector<vector<pair<int,int>>> adj(n+1);
        
        
        for(int i = 0; i<times.size();i++){
            int start = times[i][0], end = times[i][1], weight = times[i][2];
            adj[start].push_back({end,weight});
        }
        q.push({0,k});
        //As nodes are labeled from 1 to n.
        vector<int> time(n+1,1e9);
        //time taken to reach from k to k is 0
        time[k] = 0;

        int maxi = INT_MIN;
        //We are just finding out minimum time taken to reach signla from source node k to each other node via the following dijkstras algorightm.
        while(!q.empty()){
            int node = q.top().second;
            int mintimeUntilCurrentNode = q.top().first;
            q.pop();
            for(auto it:adj[node]){
                int node_it = it.first;
                int timeof_node_to_it = it.second;
                if(mintimeUntilCurrentNode + timeof_node_to_it < time[node_it]){
                    time[node_it] = mintimeUntilCurrentNode + timeof_node_to_it;
                    q.push({mintimeUntilCurrentNode + timeof_node_to_it, node_it});
                    
                }
            }
        }
        //Minimum time it takes for all the n nodes to receive the signal is time taken to reach
        //the farthest node from starting node k.
        //that is the maximum value of time from the vector of minimum time taken to all nodes 
        //If we found out that time taken to certain node is 1e9 it means we were not able to reach to that node
        //As that initial assighn value 1e9 did not got updated.
        for(int i = 1; i <= n; i++){
            //cout << time[i] << " ";
            if(time[i] == 1e9) return -1;
            if(maxi<time[i]) maxi = time[i];
        } 

        return maxi;

    }
};