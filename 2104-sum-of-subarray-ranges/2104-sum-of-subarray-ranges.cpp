class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans=0;
        long long larg;
        long long small;
        int n=nums.size();
        for(int i=0;i<n;i++){
            larg=nums[i];
            small=nums[i];
            for(int j=i;j<n;j++){
                larg=max(larg,(long long)nums[j]);
                small=min(small,(long long)nums[j]);
                ans=ans+(larg-small);
            }
        }
   return ans; }
};