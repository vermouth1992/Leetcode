from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        output = [[1]]
        for i in range(1, numRows):
            output.append([1])
            for j in range(i - 1):
                output[i].append(output[i - 1][j] + output[i - 1][j + 1])
            output[i].append(1)
        return output

if __name__ == '__main__':
    print(Solution().generate(5))