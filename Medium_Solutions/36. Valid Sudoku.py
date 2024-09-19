from collections import Counter
class Solution:
    def isValidSudoku(self, board):
        for box in board:
            for cell in box:
                count=Counter(box)
                if count[cell] == ".":
                    break
                elif  count[cell]>1:
                    return False
                else :
                    return True
                    

            
S1=Solution()
print(S1.isValidSudoku([["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]))