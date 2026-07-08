class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        list<int> ls;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
         if(asteroids[i]>0){
            ls.push_back(asteroids[i]);
         }
         else{
         while(!ls.empty()&&ls.back()>0){
            if(abs(asteroids[i])>abs(ls.back())){
            ls.pop_back();
            }
            else{
                break;
            }
         }
         if(!ls.empty()&&ls.back()==abs(asteroids[i])){
            ls.pop_back();
         }
         else if(ls.empty()&&asteroids[i]<0){
            ls.push_back(asteroids[i]);
         }
         else if(!ls.empty()&&ls.back()<0){
            ls.push_back(asteroids[i]);
         }
         }
        }
   vector<int> ans;
   for(auto i:ls) {
    ans.push_back(i);
   }
   return ans;}
};