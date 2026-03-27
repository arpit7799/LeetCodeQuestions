class Solution:
    def rowAndMaximumOnes(self, mat: List[List[int]]) -> List[int]:
        
        max_count = 0
        index = 0
        
        for i in range(len(mat)):
            count = sum(mat[i])
            
            if count > max_count:
                max_count = count
                index = i
        
        return [index, max_count]