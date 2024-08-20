#include <bits/stdc++.h>
using namespace std;

class SGTree{
    private:
        vector<int> seg;
        
        
    public:
        
        SGTree(int n){
            seg.resize(4*n+1);
            
        }
        
        void build(int ind , int low ,int high, vector<int>& arr){
            if(low==high){
                seg[ind]=arr[low];
                return ;
            }
            
            int mid = (low+high)>>1;
            
            build(2*ind + 1 , low,mid,  arr);
            build(2*ind + 2 , mid+1 , high, arr);
            
            seg[ind] = min(seg[2*ind +1] , seg[2*ind+2]);
            return;
        }
        
        
        int query(int ind, int low , int high , int l ,int r, vector<int>& arr){
            // no overlap
            if(high< l || r < low)return INT_MAX;
            // complete overlap
            if(l<= low && high <= r) return seg[ind];

            // partial overlap
            int mid = (low+high)>>1;
            int left = query(2*ind + 1, low , mid , l ,r,  arr);
            int right = query(2*ind + 2, mid+1 , high , l ,r, arr);
            
            return min(left,right);
            return 0;
            
        }
        
        void printSG(){
            for(auto it:seg){
                cout<<it<<" ";
                
            }
            cout<<endl;
        }
        
};




int main() {
	// your code goes here
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
    
    int t;
    cin>>t;
    while(t--){
        int l , r;
        cin>>l>>r;
        
        cout<<tree.query(0 , 0 , n-1 , l,r ,arr)<<endl;
        
    }
    
    tree.printSG();
    return 0;
    
    
}
