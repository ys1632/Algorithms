#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    if (nums.size() < 1) return 0;
    int dp[nums.size()];
    dp[0] = 1;
    int res = 1;
    for(int i=1; i<nums.size(); i++) {
	    dp[i] = 1;
        for(int j=0; j<i; j++) {
            if(nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        res = max(res, dp[i]);
    }
    return res;
 }

 int main() {
 	vector<int> nums(8);
 	nums[0] = 10;
 	nums[1] = 9;
 	nums[2] = 2;
 	nums[3] = 5;
 	nums[4] = 3;
 	nums[5] = 7;
 	nums[6] = 101;
 	nums[7] = 18;
 	cout << lengthOfLIS(nums) << endl;
 	return 0;
 }