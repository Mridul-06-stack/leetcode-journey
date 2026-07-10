class Solution {
public:
vector<int> NSE(vector<int> &nums){
    stack<int> st;
    int n=nums.size();
    vector<int> ans(n,n);
    for(int i=n-1;i>=0;i--){
       while (!st.empty() && nums[st.top()] >= nums[i]){
            st.pop();
        }
        if(!st.empty()){
       ans[i]=st.top();
        }
        st.push(i);
    }
return ans;
}
public:
vector<int> PSE(vector<int> &nums){
    stack<int> st;
    int n=nums.size();
    vector<int> ans(n,-1);
    for(int i=0;i<nums.size();i++){
        while (!st.empty() && nums[st.top()] > nums[i]){
            st.pop();
        }
        if(!st.empty()){
       ans[i]=st.top();
        }
        st.push(i);
    }
return ans;
}
public:
vector<int> PGE(vector<int> &nums){
    stack<int> st;
    int n=nums.size();
    vector<int> ans(n,-1);
    for(int i=0;i<nums.size();i++){
        while (!st.empty() && nums[st.top()] <= nums[i]){
            st.pop();
        }
        if(!st.empty()){
       ans[i]=st.top();
        }
        st.push(i);
    }
return ans;
}
public:
vector<int> NGE(vector<int> &nums){
    stack<int> st;
    int n=nums.size();
    vector<int> ans(n,n);
    for(int i=n-1;i>=0;i--){
        while (!st.empty() && nums[st.top()] < nums[i]){
            st.pop();
        }
        if(!st.empty()){
       ans[i]=st.top();
        }
        st.push(i);
    }
return ans;
}

public:
    long long subArrayRanges(vector<int>& nums) {
        vector<int> nse=NSE(nums);
        vector<int>pse=PSE(nums);
        vector<int> nge=NGE(nums);
        vector<int> pge=PGE(nums);
        int n=nums.size();
        long long smallest=0;
        long long largest=0;
        long long left;
        long long right;
        for(int i=0;i<n;i++){
         left=i-pse[i];
         right=nse[i]-i;
         smallest=smallest+(1LL* right*left*nums[i]);
        }
         for(int i=0;i<n;i++){
         left=i-pge[i];
         right=nge[i]-i;
         largest=largest+(1LL* right*left*nums[i]);
        }

return largest-smallest;
    }
};