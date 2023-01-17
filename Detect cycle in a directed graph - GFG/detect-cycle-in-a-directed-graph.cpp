//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool cyclic(int s, vector<bool>&visited, vector<bool>&currvisited, vector<int>adj[]){
        visited[s] = true;
        currvisited[s] = true;
        
        for(auto x : adj[s]){
            if(visited[x] == false){
                 if(cyclic(x, visited, currvisited, adj)) return true;
            }
            else if(visited[x] == true && currvisited[x] == true)return true;
        }
        currvisited[s] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
       
       vector<bool> visited(V,false);
       vector<bool> currvisited(V,false);
       
       for(int i = 0; i < V; i++){
           if(visited[i] == false){
               if(cyclic(i,visited,currvisited,adj))return true;
           }
       }
       return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends