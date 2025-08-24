int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start == end) return 0;
        int mod = 1e5;
        //assign steps taken to all nodes to maximum as 1e9.
        //as mod 100000 i.e 1e5 operation is done to get the new start so range of nodes
        //we cannot set size of steps as end becuse even if newNode % mod > end 
        // we may think if we have to reach end the node which is greater than end wont help you reach end 
        // this is not true, as mod operation is not linear, the number greater than end with mod operation can
        //coems down to lesser than end.eg. 
        // arr[7] start = 2, end = 3, mod = 10
        // 2*7 = 14 % 10 = 4 
        // here 4 > 3  so we cannot discard 4, becuase
        //(4 * 7) % 10 = 28 % 10 = 8
        //(8 * 7) % 10 = 56 % 10 = 6
        //(6 * 7) % 10 = 42 % 10 = 2
        //You see? It cycles around! you can eventually hit any number in 0 to 9. Including 3, eventually.
        //Hence need to declare array of size 1e5 
        vector<int> steps(1e5,1e9);
        
        queue<pair<int,int>> q;
        //steps, node
        q.push({0,start}); // 0 steps to reach start node
        
        while(!q.empty()){
            int stepsUntilNode = q.front().first;
            int node = q.front().second;
            q.pop();
            
            for(int i = 0; i<arr.size(); i++){
                int newNode = node * arr[i];
                //make the modulo operation as given in problem statement
                newNode = newNode % mod;
               
                //if stepsUntilNode + 1 is lesser than the previous steps taken to newNode 
                //then only insert the newNode with the latest steps which are lesser.
                if(stepsUntilNode + 1 < steps[newNode]){
                    steps[newNode] = stepsUntilNode + 1;
                    q.push({stepsUntilNode+1, newNode});
                }
            }
        }
        
        if(steps[end] == 1e9) return -1;
        return steps[end];
    }