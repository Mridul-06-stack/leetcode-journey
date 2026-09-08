class Solution {
public:
    int countCommas(int n) {
      int commas=0;
      commas=n/1000;
      if(commas){
        return n-999;
      }  
      return commas;
    }
};