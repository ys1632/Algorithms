public class Solution_303{
    private int[] sums;
    public static void main(String[] args) {
        int[] arr = new int[]{-2,3,4,7,-1,3};
        Solution_303 sol = new Solution_303(arr);
        System.out.println(sol.sumRange(0,2));
    }

    public Solution_303(int[] nums) {
        if (nums.length < 1 || nums == null) return; 
        sums = new int[nums.length];
        sums[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            sums[i] = nums[i] + sums[i-1];
        }
    }

    public int sumRange(int i, int j) {
        if (i < 0 || j < i || j > sums.length || j < 0) return 0;
        if (i == 0) return sums[j];
        return sums[j] - sums[i-1];
    }
}