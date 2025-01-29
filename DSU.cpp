class DSU{
    private:
        vector<int> parent,Size;
    public:
        DSU(int n){
            parent.resize(n+1);
            Size.resize(n+1,1);

            for(int i = 0 ; i <=n ; i++){
                parent[i]=i;
            }
        }

        int findParent(int x){
            if(parent[x] == x)return x;
            return parent[x] = findParent(parent[x]);
        }

        void Union(int u , int v){
            int pu = findParent(u);
            int pv = findParent(v);
            if(pu==pv)return ;

            if(Size[pu]> Size[pv]){
                parent[pv] = pu;
                Size[pu] += Size[pv];

            }
            else{
                parent[pu] = pv;
                Size[pv] += Size[pu];
            }
        }

};
