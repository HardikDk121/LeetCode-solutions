class Solution:
    def topKFrequent(self,nums,k):
        count={}
        freq=[[] for i in range(len(nums)+1)]
        result=[]
        for num in nums:
            count[num]=count.get(num,0)+1
        
        for num,c in count.items():
            freq[c].append(num)
        
        for i in range(len(freq)-1,0,-1):
            for n in freq[i]:
                result.append(n)
                if len(result)==k:
                    return result
S1=Solution()
print(S1.topKFrequent([1,1,2,5,5,6],2))