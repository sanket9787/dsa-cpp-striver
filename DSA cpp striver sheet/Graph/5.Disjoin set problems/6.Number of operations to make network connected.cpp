class DisjointSet{
	 vector<int> rank, parent, size;

public:
	DisjointSet(int n){
		rank.resize(n+1, 0); // mark all the nodes rank as zero
		parent.resize(n+1);
		size.resize(n+1);
		for(int i = 0; i<=n ; i++){
			parent[i] = i;
			size[i]= 1; 
		}
	}

	int findUpar(int node){
		if(node == parent[node])  // if the parent of the node is itself then it is the ultimate parent so return it.
			return node;
		return parent[node] = findUpar(parent[node]);  //store the ultimate parent for each node
	}

	void unionByRank(int u, int v){
		int ulp_u = findUpar(u);
		int ulp_v = findUpar(v);

		if(ulp_u == ulp_v) return;  //If both u and v belongs to same component just return it

		if(rank[ulp_u] < rank[ulp_v]){       //if rank of ultimet parent of u is lesser than rank of v then attach u to v and make ultimate parent of u to be ultimate parent of v.
			parent[ulp_u] = ulp_v;
		}
		else if(rank[ulp_v] < rank[ulp_u]) {  // uf rank of ultimet parent of v is lesser than u then attach v to u and make ultimate parent of v to be ultimate parent of u.
			 parent[ulp_v] = ulp_u;
		}
		else{
			parent[ulp_v] = ulp_u;  // if both parent same attach u to v 
			rank[ulp_u]++;			// now as both parent are same rank will increase
		}
	}

	void unionBySize(int u , int v){
		int ulp_u = findUpar(u);
		int ulp_v = findUpar(v);

		if(size[ulp_u] < size[ulp_v]){
			parent[ulp_u] = ulp_v;
			size[ulp_v] = size[ulp_v] + size[ulp_u];
		}else{
			parent[ulp_v] = ulp_u;
			size[ulp_u] += size[ulp_v];
		}

	}
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet dis(n);
        int extra = 0;
        for(int i = 0 ;i <connections.size(); i++){
            int u = connections[i][0], v = connections[i][1];
            if(dis.findUpar(u) == dis.findUpar(v)) extra++;
            else{
                dis.unionBySize(u, v);
            }
        }
        int compo = 0;
        for(int i = 0; i< n; i++){
            if(dis.findUpar(i) == i) compo++;
        }

        if(extra >= compo - 1) return compo - 1;
        return -1;
    }
};