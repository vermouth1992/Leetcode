
class Solution42 {
    public int trap(int[] height) {
        // O(N) complexity
        if (height.length <= 2) return 0;
        int leftIndex = 0;
        int rightIndex = height.length - 1;
        int leftMax = height[leftIndex];
        int rightMax = height[rightIndex];
        int result = 0;
        while (leftIndex < rightIndex - 1) {
            if (leftMax < rightMax) {
                if (height[leftIndex + 1] < leftMax) {
                    result = result + leftMax - height[leftIndex + 1];
                } else {
                    leftMax = height[leftIndex + 1];
                }
                leftIndex += 1;
            } else {
                if (height[rightIndex - 1] < rightMax) {
                    result = result + rightMax - height[rightIndex - 1];
                } else {
                    rightMax = height[rightIndex - 1];
                }
                rightIndex -= 1;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Solution42 s = new Solution42();
        int[] test = new int[]{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        System.out.println(s.trap(test));
        int[] test2 = new int[]{4, 2, 0, 3, 2, 5};
        System.out.println(s.trap(test2));
    }
}
