class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        int n = words.size();
        //create adj list which will store the graph from 0 to 25
        //as we are converting the small a to z to integers 
        // a - 'a' = 0
        // b - 'a' = 1 ...
        vector<vector<int>> adj(26);
        unordered_set<int> st;
        
        //store the all unique elements from the give words list
        for(int i = 0; i< n; i++){
            for(auto it : words[i]){
                st.insert(it - 'a');
            }
        }
        
        // for(auto it: st){
        //   // cout << it << " ";
        // }
        //cout << endl;
        
        //basically this v or set size is the number of nodes in our graph
        int v = st.size();
        
        
        //Now in adj list check for difference in current and next word
        //If we found different letter then  eg. abcd  abde
        //c != d.   then c comes before d in our dictionary.
        //hence now store d in adj at c.(there is an edge from c -> d)
        // adj[c - 'a'].push_back(d-'a');
        
        //2 edgecases :
        // abc  abcd -> this is fine in this case code will not have anyone in a
        // abcd abc  -> not right have to return empty string
        bool found = 0;
        for(int i = 0; i< n-1; i++){
            
            string first = words[i];
            string second = words[i+1];
            
            int l1 = first.length();
            int l2 = second.length();
            
            int s = 0,  t = 0;
            
            while(s < l1 && t < l2){
                //if found difference push in adj
                if(first[s] != second[t]){
                    adj[first[s] - 'a'].push_back(second[t]-'a');
                    found = 1;
                    break;
                }
                s++;
                t++;
            }
            //Edge caes : if the difference is not found and s != l1 it means that second 
            //word is smaller than first eg. abcd  abc
            //here we cannot decide as abc is similer and 2nd word getting exhausted 
            //so just return "" as stated in question.
            if(s != l1 && found == 0) return "";
        }
        
        // for(int i = 0; i< adj.size(); i++){
        //     for(auto it: adj[i]){
        //         cout << it << " ";
        //     }
        //     cout << endl;
        // }
        
        
        // will perform next topo sort using dfs 
        //if elements in topo sort == all the unique elements in dictornary(or set we created)
        // then we can return true else false
        // if not then it means it has a cycle and dictionary cannot be created.
        
        //make sure size of indegree is 26 as we will be looping 
        //only for elements in set which can be anywhere from 0 to 25
        vector<int> indegree(26,0);
        queue<int> q;
        
        for(auto i: st){
            for(auto j: adj[i]){
                indegree[j]++;
            }
        }
        
        for(auto i:st){
            if(indegree[i] == 0){
                //cout << i << " ";
                q.push(i);
            } 
        }
        
        //BFS starts
        string ans = "";
        while(!q.empty()){
            
            auto front = q.front();
            q.pop();
            //Before inserting into ans convert it into character
            char insert = front + 'a';
            ans = ans + insert;
            for(auto it: adj[front]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
       // cout<< ans << endl;
        if(ans.length() != st.size()) return "";
        return ans;
    }
};