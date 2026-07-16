class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
// we will break the problem into three parts //
//number 1 that is the left part in whcih no overlaping happens in whcih last interval is less than the start of the new interval

//2 in  whcih the end of the interval is greater than the start of the new interval we merege them 
// if the  end of the new interval is greater then  start of the old interval we just place the  new interval after that the remainging intervals 
   vector<vector<int>> ans;
   int n=intervals.size();
    int i=0;
   while(i<n&&intervals[i][1]<newInterval[0]){
    ans.push_back(intervals[i]);
    i++;
   }
   while(i<n&& intervals[i][0]<=newInterval[1]){
    newInterval[0]=min(intervals[i][0],newInterval[0]);
    newInterval[1]=max(intervals[i][1],newInterval[1]);
   i++;
   }
   
    ans.push_back(newInterval);
 
   while(i<n){

    ans.push_back(intervals[i]);
    i++;

   }
  
  
  return ans;
    }
};