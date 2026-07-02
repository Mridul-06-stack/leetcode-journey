class Solution {
    public:
    int cnt(vector<int>& nums, int k){
         int left=0;
         int right=0;
         int n=nums.size();
         unordered_map<int ,int> hash;
         int count=0;
         
         while(right<n){
            hash[nums[right]]++;
           
           int rem=0;
            while(left<=right&&hash.size()>k){
                hash[nums[left]]--;
                
                if(hash[nums[left]]==0){
                  
                    hash.erase(nums[left]);
                     
            
                    
                }
                left++;
                

            }
            if(hash.size()<=k){
            count+=right-left+1;
            }
            right++;
         }
         return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
     
         
      

//     set<int> container;
// for(int i=0;i<n;i++){

//     container.clear();
//     for(int j=i;j<n;j++){
//       container.insert(nums[j]);
//       if(container.size()==k){
//         count++;
//       }
//       if(container.size()>k){
//         break;
//       }
//     }
// }
    return cnt(nums,k)-cnt(nums,k-1);}
};