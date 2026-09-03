class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool flag=true;
        for(auto it:nums1){
            if(it&1) {flag=false;
            break;}
        }
        if(flag) return true;
        int number=1e9;
        for(auto it:nums1){
       
        number=min(number,it);}
       
        if(number&1) return true;
        
        return false;
    }
};