class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddsum=0;
        int evensum=0;
        for(int i=1;i<=2*n;i++){
            if(i&1){

              oddsum+= i; 
            }
            else{
                evensum+=i;
            }
        
        }
        int gcd=1;
      for(int i=1;i<=max(oddsum,evensum);i++ ){
      if(oddsum%i==0&&evensum%i==0){
        gcd=max(gcd,i);
      }


      }


return gcd;

    }
};