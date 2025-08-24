class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int stopCnt = 0;
        int l = flights.size();
        int m = flights[0].size();
        queue<pair<int, pair<int,int>>> q;
        vector<vector<pair<int,int>>> adj(n);
        vector<int> dis(n,1e9);

        //create adj list from flights
        for(int i = 0 ; i < flights.size(); i++){
            int start = flights[i][0], end = flights[i][1], price = flights[i][2];
            adj[start].push_back({end, price});
        }

        //{stopCnt, {Flightprice, sourceNode}}
        q.push({0,{0,src}});

        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int stopCnt = front.first;
            int TotalFlightPriceUntilCurrentNode = front.second.first;
            int startNode = front.second.second;
            
            for(auto it: adj[startNode]){
                // endNode = it.first, flightPrice between start node to endNode = it.second
                int endNode = it.first;
                int totalFlightPriceUntilNode_it = it.second + TotalFlightPriceUntilCurrentNode;

                if(totalFlightPriceUntilNode_it < dis[endNode] && stopCnt + 1 <= k+1){
                    dis[endNode] = totalFlightPriceUntilNode_it;
                    q.push({stopCnt+1,{totalFlightPriceUntilNode_it,endNode}});
                }
            }
        }
        if(dis[dst] == 1e9) return -1;
        return dis[dst];
    }
};