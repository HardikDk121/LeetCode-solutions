class Solution:
    def longestConsecutive(self, nums):
        '''i know spelling of index is wrong i had to do it so i can use function'''
   
        Indx=0
        
        Length=0
        MaxLength=0
        while len(nums)>0:
            if len(nums)>Indx:
                current=nums[Indx]
            else:
                break
            Left=current-1
          
            if Left  in nums:
                Length+=1
               
                nums.pop(Indx)
                Indx=nums.index(Left)
                
            else:
                if Length>MaxLength:
                    MaxLength=Length
                Length=1
                nums.pop(Indx)
                Indx=0
        return MaxLength  

        
S1=Solution()
print(S1.longestConsecutive([0,3,7,2,5,8,4,6,0,1]))