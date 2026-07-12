class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        int n=num.size();
       
        for(int i=0;i<n;i++){
            while(!st.empty()&&k>0&&st.top()>num[i]-'0'){
                st.pop();
                k--;
            }
            st.push(num[i]-'0');
        }
       while(!st.empty()&&k>0){
        st.pop();
        k--;
       }
       string ans;
       while(!st.empty()){
        ans.push_back(st.top()+'0');
        st.pop();
       }
       
       while(ans.size()>0&&ans.back()=='0'){
        ans.pop_back();
       }if(ans.empty()){
        return "0";
       }
reverse(ans.begin(),ans.end());

return ans;
    }
};