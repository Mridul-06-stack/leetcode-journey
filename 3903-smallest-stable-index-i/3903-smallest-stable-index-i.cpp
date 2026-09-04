class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

       int n=nums.size();
        vector<int> mini(n);
       vector<int>maxi(n); 
       int currmin=INT_MAX;
       int currmax=INT_MIN;
       for(int i=0;i<nums.size();i++){
       maxi[i]=max(currmax,nums[i]);
       currmax=max(currmax,nums[i]);
       mini[n-i-1]=min(currmin,nums[n-i-1]);
       currmin=min(currmin,nums[n-i-1]);

       }
      int score=0;
      for(int i=0;i<n;i++){
        score=maxi[i]-mini[i];
        if(score<=k) return i;

      }

     return -1;
    }
};