class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
       nums.erase(unique(nums.begin(), nums.end()), nums.end());
        
        if(nums.size()==0) return 0;
        int count=1;
        int maxcount=1;
        for(int i=1;i<nums.size();i++){
        if(nums[i]-nums[i-1]==1){
            count++;  
            maxcount=max(count,maxcount);
        }    
      
        else{
            count=1;
        }
        }
    return maxcount;}
};