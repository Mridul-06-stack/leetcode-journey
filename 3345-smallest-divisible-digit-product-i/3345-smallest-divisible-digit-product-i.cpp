class Solution {
public:
    bool helper(int n,int t){
        int product=1;
        while(n){
            product*=n%10;
            n=n/10;

        }
        if(product%t==0){
            return true;
        }
        return false;
    }
    int smallestNumber(int n, int t) {
        bool flag=false;
       int number=n;
        while(!flag){
           flag=helper(number,t);
           if(flag){
            return number;
           }
           number=number+1;
        }
return number;
    }
};