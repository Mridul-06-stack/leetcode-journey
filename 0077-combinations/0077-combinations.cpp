class Solution {
public:
    void find(int st,int n,vector<int> &temp,vector<vector<int>> &ans,int k){
       if(temp.size()==k){
        ans.emplace_back(temp);
        
        return;
       }
      
      
     for(int i=st;i<=n;i++){
     temp.emplace_back(i);

     find(i+1,n,temp,ans,k);
     temp.pop_back();
     
     }
    
   

     return;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> ans;
        find(1,n,temp,ans,k);
        return ans;
    }
};