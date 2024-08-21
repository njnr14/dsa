#include <bits/stdc++.h>
using namespace std;

class SGTree{
    private:
        vector<int> seg , lazy;
        
        
    public:
        
        SGTree(int n){
            seg.resize(4*n+1);
            lazy.resize(4*n + 1);
            
        }
        
        void build(int ind , int low ,int high, vector<int>& arr){
            if(low==high){
                seg[ind]=arr[low];
                return ;
            }
            
            int mid = (low+high)>>1;
            
            build(2*ind + 1 , low,mid,  arr);
            build(2*ind + 2 , mid+1 , high, arr);
            
            seg[ind] = seg[2*ind +1] + seg[2*ind+2];
            return;
        }
        
        
        int query(int ind, int low , int high , int l ,int r){
            
            if(lazy[ind]!=0){
                seg[ind] += (high-low+1)*lazy[ind];
                
                if(low!=high){
                    lazy[2*ind+1] += lazy[ind];
                    lazy[2*ind+2] += lazy[ind];
                    
                }
                
                lazy[ind] = 0;
            }
            
            
            
            
            // no overlap
            if(high< l || r < low)return 0;
            // complete overlap
            if(l<= low && high <= r){ return seg[ind];}

            // partial overlap
            int mid = (low+high)>>1;
            int left = query(2*ind + 1, low , mid , l ,r);
            int right = query(2*ind + 2, mid+1 , high , l ,r);
            
            return left + right;
            
            
        }

	void update(int ind ,int low ,int high ,int l ,int r ,int val){
            
            
            if(lazy[ind]!=0){
                seg[ind] += (high-low+1)*lazy[ind];
                
                if(low!=high){
                    lazy[2*ind+1] += lazy[ind];
                    lazy[2*ind+2] += lazy[ind];
                    
                }
                
                lazy[ind] = 0;
            }
            
            //no overlap 
            if(high < l || low > r)return;
            //complete overlap
            if(l<=low && high<=r){
                seg[ind] += (high-low+1)*val;
                
                if(low!=high){
                    lazy[2*ind+1] += lazy[ind];
                    lazy[2*ind+2] += lazy[ind];
                }
                return;
            }
            
            // partial overlap
            
            int mid = (low+high)>>1;
            
            update(ind*2+1  , low, mid , l ,r ,val);
            update(ind*2+2  , mid+1, high , l ,r, val);
            
            seg[ind]=  seg[2*ind+1] + seg[2*ind+2];
            return;
        }
        
        void printSG(){
            for(auto it:seg){
                cout<<it<<" ";
                
            }
            cout<<endl;
        }
        
};




int main() {

    int n ;
    cin>>n;
    
    vector<int> arr(n);
    for(int i = 0 ; i < n ;i++){
        int temp;
        cin>>temp;
        arr[i]=temp;
    }
    for(int i = 0 ; i < n ;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    SGTree tree(n);
    tree.build(0 , 0 , n-1 ,arr);
    tree.printSG();
    
    int l , r;
    cin>>l>>r;
    
    cout<<tree.query(0 , 0 , n-1 , l ,r)<<endl;
    
    int t;
    cin>>t;
    while(t--){
        int l , r,val;
        cin>>l>>r>>val;
        
        tree.update(0 , 0 , n-1 , l,r ,val);
        
    }
    cout<<endl;
    tree.printSG();
    cout<<endl;
    
    
    
    
    return 0;
    
    
}
