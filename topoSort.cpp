vector<int> topo(int N , vector<int> adj[]){
        vector<int> in(N,0);
        
        for(int i = 0; i < N ;i++){
            for(auto it : adj[i]){
                in[it]++;
            }
        }
        
        
        queue<int> que;
        
        for(int i = 0 ; i < N ;i++){
            if(in[i]==0){
                que.push(i);
            }
        }
        
        vector<int> ans;
        
        while(!que.empty()){
            int node = que.front();
            que.pop();
            ans.push_back(node);
            
            for(auto it : adj[node]){
                in[it]--;
                if(in[it]==0)que.push(it);
            }
        }
        
        return ans;
    }
