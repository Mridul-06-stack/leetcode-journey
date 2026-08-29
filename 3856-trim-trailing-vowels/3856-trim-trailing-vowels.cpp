class Solution {
public:
    string trimTrailingVowels(string s) {
         int end=s.size()-1;
         string ans;
         while(end>=0&&(s[end]=='a'||s[end]=='e'||s[end]=='i'||s[end]=='o'||s[end]=='u')){
            end--;
         }
         for(int i=0;i<=end;i++){
            ans+=s[i];
         }
return ans;
    }
};