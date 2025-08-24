class Solution {
public:
    bool DFS(int node, int prevColor , vector<int> &color, vector<vector<int>>& graph){
        color[node] = prevColor;
        //cout << "node = " << node <<endl;
        for(auto it : graph[node]){
            //cout << "node = " << node << " it = "<< it << ", ";
            if(color[it] == -1){
              if(DFS(it, !prevColor, color, graph) == false) return false;
            }else if(color[it] == prevColor) return false;
        }
        cout << endl;

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v,-1);

        for(int i = 0; i<v; i++){
            if(color[i] == -1){
                if(DFS(i, 0, color, graph) == false) return false;
            }
        }

        return true;
    }
};