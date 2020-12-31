import java.util.*;

/*
 * @lc app=leetcode id=407 lang=java
 *
 * [407] Trapping Rain Water II
 *
 * https://leetcode.com/problems/trapping-rain-water-ii/description/
 *
 * algorithms
 * Hard (43.67%)
 * Total Accepted:    48.1K
 * Total Submissions: 110.1K
 * Testcase Example:  '[[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]'
 *
 * Given an m x n matrix of positive integers representing the height of each
 * unit cell in a 2D elevation map, compute the volume of water it is able to
 * trap after raining.
 *
 * Example:
 *
 *
 * Given the following 3x6 height map:
 * [
 * ⁠ [1,4,3,1,3,2],
 * ⁠ [3,2,1,3,2,4],
 * ⁠ [2,3,3,2,3,1]
 * ]
 *
 * Return 4.
 *
 *
 *
 *
 * The above image represents the elevation map
 * [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]] before the rain.
 *
 *
 *
 *
 *
 * After the rain, water is trapped between the blocks. The total volume of
 * water trapped is 4.
 *
 *
 * Constraints:
 *
 *
 * 1 <= m, n <= 110
 * 0 <= heightMap[i][j] <= 20000
 *
 *
 */
class Solution407 {
    class Pair {
        int x;
        int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Pair pair = (Pair) o;
            return x == pair.x && y == pair.y;
        }

        @Override
        public int hashCode() {
            return 31 * x + y;
        }
    }

    private boolean isBoundary(Pair pair, int[][] heightMap) {
        return pair.x == 0 || pair.x == heightMap.length || pair.y == 0 || pair.y == heightMap[0].length;
    }

    private int bfs(int[][] heightMap, Set<Pair> globalExplored, Pair currentPair) {
        int minBoundaryHeight = heightMap[currentPair.x][currentPair.y];
        Deque<Pair> frontier = new LinkedList<Pair>();
        frontier.add(currentPair);
        Set<Pair> localExplored = new HashSet<Pair>();
        while (!frontier.isEmpty()) {
            Pair p = frontier.pop();
            // expand up, down, left, right
            globalExplored.add(p); // add to global explored set
            localExplored.add(p);
            if (isBoundary(p, heightMap)) return 0; // if the boundary is in the area. Then 0
            // neighbors
            Deque<Pair> neighbors = new LinkedList<Pair>();
            neighbors.add(new Pair(p.x, p.y + 1));
            neighbors.add(new Pair(p.x, p.y - 1));
            neighbors.add(new Pair(p.x + 1, p.y));
            neighbors.add(new Pair(p.x - 1, p.y));
            while (!neighbors.isEmpty()) {
                Pair n = neighbors.pop();
                if (!localExplored.contains(n)) {
                    if (heightMap[n.x][n.y] > heightMap[p.x][p.y]) {
                        // if neighbor is higher, update minBoundaryHeight
                        if (heightMap[n.x][n.y] > minBoundaryHeight) {
                            minBoundaryHeight = heightMap[n.x][n.y];
                        }
                    } else {
                        frontier.add(n);
                    }
                }
            }
        }
        // This is a valid area. The result is minBoundaryHeight - everything in localExplored
        int result = 0;
        for (Pair p : localExplored) {
            result = result + minBoundaryHeight - heightMap[p.x][p.y];
        }
        return result;
    }

    public int trapRainWater(int[][] heightMap) {
        // run BFS/DFS starting from inner location to create a set of area.
        // The height of each area is the minimum height of its surroundings.
        if (heightMap.length <= 2) return 0;
        if (heightMap[0].length <= 2) return 0;

        Set<Pair> globalExplored = new HashSet<Pair>();

        Deque<Pair> allPairs = new LinkedList<Pair>();

        // add all the inner points. O(mn)
        for (int i = 1; i < heightMap.length - 1; i++) {
            for (int j = 1; j < heightMap[0].length - 1; j++) {
                allPairs.add(new Pair(i, j));
            }
        }
        while (!allPairs.isEmpty()) {
            // randomly pop one element that is not explored
            Pair currentPair = allPairs.pop();
            while (globalExplored.contains(currentPair)) {
                currentPair = allPairs.pop();
            }
            // start BFS or DFS. If it connects to the boundary
            int result = bfs(heightMap, globalExplored, currentPair);
        }
        return 0;
    }
}
