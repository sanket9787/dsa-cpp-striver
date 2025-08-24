class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int,int>>> adj(n);
        for(int i =0; i< roads.size(); i++){
            int first = roads[i][0], second = roads[i][1], time = roads[i][2];
            adj[first].emplace_back(second, time);
            adj[second].emplace_back(first, time);
        }

        // Use long long for distances , pq is used to store the priority wise minimum distances at the top of the queue, so that we can take those minimum distances first as we want to find the 
        //minimum distance for each node.
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
        // dis, node
        q.emplace(0, 0);
        //Stores the minimum time taken for each node to reach
        vector<long long> dist(n, 1e18);
        //Stores how many ways we can arrive at the perticular node with the minimum time.
        vector<int> count(n, 0);

        dist[0] = 0;
        count[0] = 1; //IMP
        
        while(!q.empty()){
            long long currDist = q.top().first;
            int node = q.top().second;
            q.pop();

           // if (currDist > dist[node]) continue; // Optional optimization

            for(auto& it : adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;
                long long newDist = currDist + edgeWt;

                if(newDist == dist[adjNode]){
                    //To avoid overflow
                    count[adjNode] = (count[adjNode] + count[node]) % MOD;
                }
                else if(newDist < dist[adjNode]){
                    dist[adjNode] = newDist;
                    count[adjNode] = count[node];
                    q.emplace(newDist, adjNode);
                }
            }
        }

        return count[n-1];
    }
};
