class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
            return False
        Hash1={}
        Hash2={}
        for i in range(len(s)):
            Hash1[s[i]]=1+Hash1.get(s[i],0)
            Hash2[t[i]]=1+Hash2.get(t[i],0)
        for j in range(len(s)):w
            if Hash1[j]!=Hash2.get(j,0):
                return False
        return True
S1=Solution()
S1.isAnagram("anagram","nagaram")         
