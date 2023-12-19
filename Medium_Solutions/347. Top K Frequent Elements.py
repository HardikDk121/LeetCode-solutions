from collections import OrderedDict
class Solution:
    def topKFrequent(self,nums,k):
        HashMap={}
        result=[]
        
        for num in range(len(nums)):
             HashMap[nums[num]]=1+HashMap.get(nums[num],0)
        SortedHash = OrderedDict(sorted(HashMap.items(), key=lambda x: x[1],reverse=True))
        KeyList=list(SortedHash.keys())
        for order in range(k):
           result.append(KeyList[order])
        return result
S1=Solution()
print(S1.topKFrequent([1,1,2,5,5,6],2))