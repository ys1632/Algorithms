#include <iostream>
#include <vector>

using namespace std;

//sumRange would be called many times

class NumArray {
private:
	//sums[k] is the sum of first k elements in nums
    vector<int> sums;    
public:
    NumArray(vector<int> &nums) {
        if (nums.size() < 1) return;
        sums.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            sums.push_back(sums[i-1] + nums[i]);
        }
    }
    //as there are many calls to sumRange, we use dp otherwise exceeding time limit
    int sumRange(int i, int j) {
        if (i < 0 || j < 0 || j < i || j > sums.size()) return 0;
        if (i == 0) return sums[j];
        return sums[j] - sums[i-1];
    }
};

int main() {
	vector<int> nums(5);
	nums[0] = -1;
	nums[1] = 3;
	nums[2] = 2;
	nums[3] = 8;
	nums[4] = 9;
	NumArray *numarr = new NumArray(nums);
	cout << numarr->sumRange(0,3) << endl;
}