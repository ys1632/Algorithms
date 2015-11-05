public class LIS_300 {
    public static void main(String[] args) {
        int[] nums = new int[]{10,9,2,5,3,7,101,18};
        LIS_300 lis = new LIS_300();
        System.out.println(lis.lengthOfLIS(nums));
    }
    public int lengthOfLIS(int[] nums) {
            int res = 1;
            if (nums == null || nums.length < 1) return 0;
            int[] dp = new int[nums.length];
            dp[0] = 1;
            for (int i = 1; i < nums.length; i++) {
                dp[i] = 1;
                for (int j = 0; j < i; j++) {
                    if (nums[j] < nums[i]) {
                        dp[i] = Math.max(dp[i], dp[j] + 1);
                    }
                }
                res = Math.max(res, dp[i]);
            }
            return res;
    }
}