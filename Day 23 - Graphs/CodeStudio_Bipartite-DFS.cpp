#include<bits/stdc++.h>
void convertor(unordered_map<int,list<int>>&adj,vector<vector<int>>& edges){
    for(int i = 0 ;i<edges.size();i++){
        for(int j = 0 ;j<edges[0].size();j++)
       {     if(edges[i][j] == 1)
              {
               adj[i].push_back(j);
               }
        }
//         adj[v].push_back(u);
    }
}

bool dfs(int node,unordered_map<int,list<int>>&adj,vector<int>&color ){
     if(color[node] == -1)
     {
         color[node] = 1;
     }
  for(auto x : adj[node] ){
      if(color[x] == -1){
          color[x] = 1 - color[node];
          if(dfs(x,adj,color) == false){
              return false;
          }
      }
      if(color[x] == color[node]){
          return false;
      }
  }

    return true;
}


bool isGraphBirpatite(vector<vector<int>> &edges) {
	unordered_map<int,list<int>> adj;
    convertor(adj,edges);
    vector<int>color(edges.size(),-1);
    for(int i = 0 ;i<edges.size() ;i++){
        if(color[i] == -1){

            if(dfs(i,adj,color) == false){
                return false;
            }
        }

    }
    return true;

}
