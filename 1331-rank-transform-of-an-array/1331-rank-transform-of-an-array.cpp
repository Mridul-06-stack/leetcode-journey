class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> hash;
        for(auto i: arr){
            hash[i]++;

        }
        int i=1;
        for(auto &it:  hash){
            it.second=i;
            i++;
        }

        vector<int> ans(arr.size(),0);
        for(int i=0;i<arr.size();i++){
            ans[i]=hash[arr[i]];
        }
      return ans;  }

};