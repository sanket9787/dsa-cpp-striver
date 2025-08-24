class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& nums) {
        //In this problem to check if we can finish all course we have to check if there is 
        //cycle present or not like 1 depend on 2 , 2 depend on 3 and 3 depend on 1. So in this 
        //case we cant decide which course to take first. If this cycle is there then we cannot finish all courses.
        //To detect cycle there is DFS / BFS(kahn's algorithm)
        // with BFS is basically a topological sort.
        // IF we are able to push all the elements into the toposort vector i.e. toposrt.size() == V(number of nodes).
        // IT means that there is no cycle present and we can do topo sort on all nodes given,
        //and hence can finish all courses.

        int v = numCourses;
        vector<int>indegree(v,0);
        queue<int> q;

        vector<vector<int>> adj(v);
        //First create the adj list and incerease the indegree of dependent node.
        //like for ex. [1,0] here 0 should be finished first before 1, so 0 -> 1
        // hence 1 is dependent on 0 to be finished hence incresase the indegree of 1.
        //likewise calculate the indegree of all nodes.
        for(int i = 0 ; i<nums.size(); i++){
            int first = nums[i][0], sec = nums[i][1];
            adj[sec].push_back(first);
            indegree[first]++;
        }
        
        //If any nodes indegree is zero then push it into q. All those nodes are independent
        //And we can start from all those node simultanously(BFS) it wont be an issue.
        
        for(int i = 0; i<v; i++){
            if(indegree[i] == 0) q.push(i);
        }

        int cnt = 0;
        //BFS
        //Perfom the BFS on all the nodes whose indegree zero who are pushed into queue.
        //now reduce the indegree of the adjacent nodes
        ///If indegree becomes zero then we push that adj node into queue.
        //IF not found and q becomes empty and cnt == v , it means no cycle was there.
        //IF cnt < V it means after reducing the indegree of that node it did not able to become
        //zero as it was connected to another cyclic node hence was not able to push it to q, and q became empty.
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            cnt++;
            for(auto it:adj[front]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        //if cnt == v no cycle detected, we can finish all the courses.
        if(cnt == v) return true;
        return false;

    }
};