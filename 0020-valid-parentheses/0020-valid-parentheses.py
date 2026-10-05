class Solution:
    def isValid(self, s: str) -> bool:
        st=[]
        close=")]}"
        for x in s:
            if(x=='('):
                st+=')'
            elif(x=='['):
                st+=']'
            elif(x=='{'):
                st+='}'
            elif((x in close  )):
                if not st:
                    return False
                if st.pop()!=x:
                    return False
                 
        return len(st)==0     
            
            