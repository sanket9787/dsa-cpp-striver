class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& nums) {
       //basically we have to reutrn the topo sort in this problem

       int v = numCourses;
       vector<int> indegree(v,0);
       queue<int> q;
       vector<vector<int>> adj(v);

       for(int i = 0; i < nums.size(); i++){
            int first = nums[i][0], sec = nums[i][1];
            adj[sec].push_back(first);
            indegree[first]++;
       }

       for(int i = 0; i<v; i++){
            if(indegree[i] == 0) q.push(i);
       }

       vector<int> ans;
       while(!q.empty()){
            auto node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
       }
        if(ans.size() != v) return {};
        return ans;
    }
};
