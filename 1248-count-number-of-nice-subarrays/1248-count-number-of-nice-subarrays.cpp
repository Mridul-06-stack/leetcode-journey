class Solution {
    public:
    int count(vector<int>& nums, int k){
        int left=0;
        int right=0;
        int count=0;
        int number=0;
        while(right<nums.size()){
            if(nums[right]&1){
                number++;
            }
            while(number>k){
                if(nums[left]&1){
                    number--;
                }
                left++;
            }
            if(number<=k){
                count+=right-left+1;
            }
            right++;
        }
   return count;}
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int anss=count(nums,k)-count(nums,k-1); 
        return anss;}
};