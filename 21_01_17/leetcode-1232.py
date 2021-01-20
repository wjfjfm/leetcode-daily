class Solution(object):
    def checkStraightLine(self, coordinates):
        """
        :type coordinates: List[List[int]]
        :rtype: bool
        """
        diffy = coordinates[1][1] - coordinates[0][1]
        diffx = coordinates[1][0] - coordinates[0][0]
        orix = coordinates[0][0]
        oriy = coordinates[0][1]

        for x, y in coordinates[2:]:
            print(x, y)
            if (y - oriy) * diffx != diffy * (x - orix):
                return False
        return True

def test_leetcode_1232():
    solution = Solution()
    coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
    answer = True
    assert solution.checkStraightLine(coordinates) == answer
    coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
    answer = False
    assert solution.checkStraightLine(coordinates) == answer

if __name__ == '__main__':
    test_leetcode_1232()
