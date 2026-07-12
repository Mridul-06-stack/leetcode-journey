class Solution {
public:
    bool isBalanced(string num) {
    int n=num.size();
   
    int sum=0;
    for(int i=0;i<n;i++){
        if(i%2==1){
        sum-=num[i]-'0';
        }
        else{
            sum+=num[i]-'0';
        }
       

    }
  if(sum==0){return true;}
  
  return false;  }
};