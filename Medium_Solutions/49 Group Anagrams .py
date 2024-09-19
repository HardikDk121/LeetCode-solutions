class Solution:

    def groupAnagrams(self, strs):
        
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s)==len(t):
            Hash1={}
            Hash2={}
            for i in range(0,len(s)):
               
                if  s[i] in Hash1:
                    Hash1[s[i]]+=1
                    
                else:
                    Hash1[s[i]]=1
                        
                if t[i] in Hash2:
                    Hash2[t[i]]+=1 
                
                else:
                    Hash2[t[i]]=1
                
 
            Hash1 = dict(sorted(Hash1.items()))
            Hash2 = dict(sorted(Hash2.items()))
            
            if Hash1==Hash2:
                return True
            else: 
                return False
        else:
            return False        

            
            
        
S1=Solution()
print(S1.groupAnagrams(["eat","tea","tan","ate","nat","bat"]))