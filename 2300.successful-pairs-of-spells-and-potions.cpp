/*
 * @lc app=leetcode id=2300 lang=cpp
 *
 * [2300] Successful Pairs of Spells and Potions
 *
 * https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/
 *
 * algorithms
 * Medium (32.53%)
 * Likes:    1357
 * Dislikes: 29
 * Total Accepted:    53.4K
 * Total Submissions: 136.1K
 * Testcase Example:  '[5,1,3]\n[1,2,3,4,5]\n7'
 *
 * You are given two positive integer arrays spells and potions, of length n
 * and m respectively, where spells[i] represents the strength of the i^th
 * spell and potions[j] represents the strength of the j^th potion.
 * 
 * You are also given an integer success. A spell and potion pair is considered
 * successful if the product of their strengths is at least success.
 * 
 * Return an integer array pairs of length n where pairs[i] is the number of
 * potions that will form a successful pair with the i^th spell.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
 * Output: [4,0,3]
 * Explanation:
 * - 0^th spell: 5 * [1,2,3,4,5] = [5,10,15,20,25]. 4 pairs are successful.
 * - 1^st spell: 1 * [1,2,3,4,5] = [1,2,3,4,5]. 0 pairs are successful.
 * - 2^nd spell: 3 * [1,2,3,4,5] = [3,6,9,12,15]. 3 pairs are successful.
 * Thus, [4,0,3] is returned.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: spells = [3,1,2], potions = [8,5,8], success = 16
 * Output: [2,0,2]
 * Explanation:
 * - 0^th spell: 3 * [8,5,8] = [24,15,24]. 2 pairs are successful.
 * - 1^st spell: 1 * [8,5,8] = [8,5,8]. 0 pairs are successful. 
 * - 2^nd spell: 2 * [8,5,8] = [16,10,16]. 2 pairs are successful. 
 * Thus, [2,0,2] is returned.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == spells.length
 * m == potions.length
 * 1 <= n, m <= 10^5
 * 1 <= spells[i], potions[i] <= 10^5
 * 1 <= success <= 10^10
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int GetLower_Bound(vector<int>&arr,int low,int high,int target){
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid] >= target){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = spells.size();
        int m = potions.size();
        int maxValue = potions[m-1];
        vector<int> ans;
        for(int i=0; i<n; i++){
            int spell = spells[i];
            /*
            minPosition * spells[i]>=success
            so minPosition = ceil((1.0*success)/spells[i]);
            ! why we conevrt int to float bcz we want to ceil value .
            ceil value means = 5.33 ~ 6 
            */
            long long minPosition = ceil((1.0*success)/spell);
            // ! Agar MinPos hi bada ho gya max Value se to mtlb yah hai ki isse aage koii bhi bada value nahi hoga success se.
            if(minPosition > maxValue){
                ans.push_back(0);
                continue;
            }
            int low = 0;
            int high = m-1;
            // ^ Finding the lower bound of minPostion
            int index = GetLower_Bound(potions,low,high,minPosition);
            int count = m-index;
            ans.push_back(count);
        }
        return ans;
    }
};
// @lc code=end

