/*
 * @lc app=leetcode id=2439 lang=cpp
 *
 * [2439] Minimize Maximum of Array
 *
 * https://leetcode.com/problems/minimize-maximum-of-array/description/
 *
 * algorithms
 * Medium (34.47%)
 * Likes:    1282
 * Dislikes: 312
 * Total Accepted:    34.1K
 * Total Submissions: 79K
 * Testcase Example:  '[3,7,1,6]'
 *
 * You are given a 0-indexed array nums comprising of n non-negative integers.
 * 
 * In one operation, you must:
 * 
 * 
 * Choose an integer i such that 1 <= i < n and nums[i] > 0.
 * Decrease nums[i] by 1.
 * Increase nums[i - 1] by 1.
 * 
 * 
 * Return the minimum possible value of the maximum integer of nums after
 * performing any number of operations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,7,1,6]
 * Output: 5
 * Explanation:
 * One set of optimal operations is as follows:
 * 1. Choose i = 1, and nums becomes [4,6,1,6].
 * 2. Choose i = 3, and nums becomes [4,6,2,5].
 * 3. Choose i = 1, and nums becomes [5,5,2,5].
 * The maximum integer of nums is 5. It can be shown that the maximum number
 * cannot be less than 5.
 * Therefore, we return 5.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [10,1]
 * Output: 10
 * Explanation:
 * It is optimal to leave nums as is, and since 10 is the maximum value, we
 * return 10.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 2 <= n <= 10^5
 * 0 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPossible(vector<int>&nums,int Expected_Max,int n){
        vector<long long> arr(nums.begin(),nums.end());
        for(int i=0; i<n-1; i++){
            if(arr[i] > Expected_Max) return false;
            long long buffer = Expected_Max-arr[i];
            arr[i+1] = arr[i+1]-buffer;
        }
        return arr[n-1]<=Expected_Max;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = *max_element(nums.begin(),nums.end());
        int result = -1;
        while(low<=high){
            int Expected_Max = low+(high-low)/2;
            if(isPossible(nums,Expected_Max,n)){
                result = Expected_Max;
                high = Expected_Max-1;
            }
            else{
                low = Expected_Max+1;
            }
        }
        return result;
    }
};
// @lc code=end

