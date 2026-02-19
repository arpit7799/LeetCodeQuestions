from typing import List

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        
        def canFinish(speed):
            hours = 0
            for bananas in piles:
                hours += (bananas + speed - 1) // speed 
            return hours <= h
        
        low = 1
        high = max(piles)
        answer = high
        
        while low <= high:
            mid = (low + high) // 2
            
            if canFinish(mid):
                answer = mid
                high = mid - 1
            else:
                low = mid + 1 
        
        return answer