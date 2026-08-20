class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> ans1;
        vector<int> ans2;
        ans1.emplace_back(nums[0]);
          ans2.emplace_back(nums[1]);
          for(int i=2;i<nums.size();i++){
            if(ans1.back()>ans2.back()){
                ans1.emplace_back(nums[i]);
            }
            else{
                ans2.emplace_back(nums[i]);
            }
          }
          vector<int> c;
          c.reserve(nums.size());
c.insert(c.end(), ans1.begin(), ans1.end());
c.insert(c.end(), ans2.begin(), ans2.end());
    return c ;
    }
};