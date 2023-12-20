class Solution:
    def productExceptSelf(self, nums):
        answer=[]
        for index in range(len(nums)):
            before=nums[0:index]
            after=nums[index+1:len(nums)]
            a_ans=1
            b_ans=1
            if before:    
                for beforeindex in range(len(before)):
                    b_ans*=before[beforeindex]
                
            if after:
                for afterindex in range(len(after)):
                    a_ans*=after[afterindex]
            answer.insert(index,a_ans*b_ans)
        return answer
S1=Solution()
print(S1.productExceptSelf([1,2,3,4]))            