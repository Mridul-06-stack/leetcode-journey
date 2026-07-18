class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;

        for(int i:nums){
            maxi= max(maxi,i);
            mini=min(mini,i);
        }
      while(mini>0 and maxi>0 ){
        if(maxi>mini) maxi=maxi%mini;
        else{
            mini=mini%maxi;
        }
      }
      return maxi==0?mini:maxi;



    }
};