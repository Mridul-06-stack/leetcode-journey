class Solution {
public:
     vector<int>  PSE(vector<int> &heights){
        stack <int> st;
        int n=heights.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[st.top()]  >=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
     }
      vector<int>  NSE(vector<int> &heights){
        stack <int> st;
        int n=heights.size();
        vector<int> ans(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&heights[st.top()]  >=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
     }


    int largestRectangleArea(vector<int>& heights) {
        int maxi=0;
        int n=heights.size();
        vector<int> pse=PSE(heights);
        vector<int> nse=NSE(heights);
        for(int i=0;i<n;i++){

            maxi=max(maxi,(nse[i]-pse[i]-1)*heights[i]);

        }


   return maxi; }
};