class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        result = ""
        currentPos = [0,0]
        for char in target:
            targetNum = ord(char) - 97
            targetPos = [int(targetNum/5), targetNum%5]
            result = result + self.alphabetCharPath(currentPos, targetPos) + "!"
            currentPos = targetPos
        return result
    
    def alphabetCharPath(self, currentPos, targetPos):
        result = ""
        if currentPos == targetPos:
            return ""
        [currentX, currentY] = currentPos
        [targetX, targetY] = targetPos
        
        diffX = targetX - currentX
        diffY = targetY - currentY
        
        # z = 5
        if 4 == targetX:
            result = result + self.alphabetCharPath(currentPos, [3,0])
            result = result + "D"
        else:
            result = result + self.moveX(diffX)
            result = result + self.moveY(diffY)
        return result

    def moveY(self, diffY):
        result = ""
        if diffY > 0:
            result = result + diffY*"R"
        elif diffY < 0:
            result = result + (-diffY)*"L"
        return result
        
    def moveX(self, diffX):
        result = ""
        if diffX > 0:
            result = result + diffX*"D"
        elif diffX < 0:
            result = result + (-diffX)*"U"
        return result
        

print("please input :")
n = input()
solution = Solution()
print("result:")
print(solution.alphabetBoardPath(n))
