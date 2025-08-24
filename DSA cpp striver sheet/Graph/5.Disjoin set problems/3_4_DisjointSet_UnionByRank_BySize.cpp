#include <bits/stdc++.h>
using namespace std;

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

int main(){
	#ifindef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	#endif
		DisjointSet ds(7);
		ds.unionByRank(1,2);
		ds.unionByRank(2,3);
		ds.unionByRank(4,5);
		ds.unionByRank(6,7);
		ds.unionByRank(5,6);
		//if 3 and 7 same component or not
		if(ds.findUpar(3) == ds.findUpar(7)){
			cout << "Same\n";
		}
		else cout << "Not same\n";

		ds.unionByRank(3,7);

		if(ds.findUpar(3) == ds.findUpar(7)){
			cout << "Same\n";
		}
		else cout << "Not same\n";
}

