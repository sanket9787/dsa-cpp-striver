class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<vector<int>> newAdj(graph.size());
        for(int i = 0; i< graph.size(); i++){
            for(auto it : graph[i]){
                newAdj[it].push_back(i);
            }
        }

        // for(int i =0; i< newAdj.size(); i++){
        //     for(auto it: newAdj[i]){
        //         cout << it<< " ";
        //     }
        //     cout<< endl;
        // }

        vector<int> indegree(v,0);
        for(int i = 0; i<v; i++){
            for(auto it: newAdj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0; i< v ;i++){
            if(indegree[i] == 0){
                //cout<< i << " ";
                q.push(i);
            } 
        }

        vector<int> topo;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            topo.push_back(front);
            for(auto it: newAdj[front]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        sort(topo.begin(), topo.end());
        return topo;
        
    }
};