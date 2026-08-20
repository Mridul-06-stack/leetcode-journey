class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
         int left=0;
         int right=k-1;
        
        if(k==nums.size()){
            int ans=INT_MIN;
            for(auto it:nums){
            ans=max(ans,it);
            }
            return ans;
        }
        map<int,int> hash;
        for(auto it:nums){
            hash[it]++;
        }
       auto end = prev(hash.end());
         if( k==1){
            while(true){
                if((*end).second==1){
                    return (*end).first;
                }
                else{
                     if(end==hash.begin()){
                        return -1;
                     }
                    end--;
                }
               
            }
         }
         int n=nums.size()-1;
         if(k>1&&k<=n){
         if(hash[nums[0]]>1&&hash[nums[nums.size()-1]]>1)
            return -1;
        
         if(hash[nums[0]]==1&&hash[nums[n]]==1) return max(nums[0],nums[n]);

         if(hash[nums[0]]==1) return nums[0];
          if(hash[nums[n]]==1) return nums[n];

         }







return -1;

    }
};