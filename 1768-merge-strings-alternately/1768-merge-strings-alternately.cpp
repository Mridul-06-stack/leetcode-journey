class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int ptr1=0;
        int ptr2=0;
        string ans;
        while(ptr1<word1.size()&& ptr2<word2.size()){
        ans.push_back(word1[ptr1]);
        ans.push_back(word2[ptr2]);
        ptr1++;
        ptr2++;

        }
       
        while(ptr2<word2.size()){
            ans.push_back(word2[ptr2]);
            ptr2++;
        }

        while(ptr1<word1.size()){
            ans.push_back(word1[ptr1]);
            ptr1++;
        }
  return ans;  }
};