class Solution {
public:
    int histo(vector<int>& matrix){
        stack<int> st;
        int n=matrix.size();
        
        int maxi=0;
        for(int i=0;i<n;i++){
            while(!st.empty()&&(matrix[st.top()])>=(matrix[i])){
                int element=matrix[st.top()];
                st.pop();
                int pse=st.empty()?-1:st.top();
                int nse=i;
                 maxi=max(maxi,(nse-pse-1)*element);
            }
           
            st.push(i);
        } while(!st.empty()){
                int nse= n;
                  int element=matrix[st.top()];
                  st.pop();
                int pse=st.empty()?-1:st.top();
                  maxi=max(maxi,(nse-pse-1)*element);
            }
        return maxi;
    }



    int maximalRectangle(vector<vector<char>>& matrix) {
       
        int rows=matrix.size();
        int cols=matrix[0].size();
        int sum; 
        vector<vector<int> > presum(rows,vector<int>(cols,0));
        for(int j=0;j<cols;j++ ){sum=0;
            for(int i=0;i<rows;i++){
             sum+=(matrix[i][j]-'0');
             if(matrix[i][j]=='0'){
                sum=0;
             }
             presum[i][j]=sum;
            }
        }
        int maxi=0;
        for(auto i: presum)
          maxi=max(maxi,histo(i));


return maxi;

    }
};