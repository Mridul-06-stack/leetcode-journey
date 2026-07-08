class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            int maxi=INT_MIN;
            int newidx;
            for(int j=1;j<nums.size();j++){
                newidx=(i+j)%nums.size();
              if(nums[i]<nums[newidx]){
                ans[i]=nums[newidx];
                break;
              }
              
            }
            
        }
    return ans;}
};