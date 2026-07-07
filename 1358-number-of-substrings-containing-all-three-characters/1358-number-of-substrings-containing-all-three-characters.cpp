class Solution {
    public: 
    int find(string &s,int k){
     int count=0;
     int left=0;
     int right=0;
     unordered_map<char,int> hash;
     int n=s.size();
     while(right<n){
        hash[s[right]]++;
        while(hash.size()>k){
            hash[s[left]]--;
            if(hash[s[left]]==0){
                hash.erase(s[left]);
            }
            left++;
        }
        if(hash.size()<=k){
            count+=right-left+1;
        }
        right++;
     }
   return count; }
public:
    int numberOfSubstrings(string s) {
      return find(s,3)-find(s,2);
      }
};