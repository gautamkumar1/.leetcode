/*
 * @lc app=leetcode id=2405 lang=cpp
 *
 * [2405] Optimal Partition of String
 *
 * https://leetcode.com/problems/optimal-partition-of-string/description/
 *
 * algorithms
 * Medium (75.10%)
 * Likes:    1503
 * Dislikes: 65
 * Total Accepted:    80.7K
 * Total Submissions: 101.6K
 * Testcase Example:  '"abacaba"'
 *
 * Given a string s, partition the string into one or more substrings such that
 * the characters in each substring are unique. That is, no letter appears in a
 * single substring more than once.
 * 
 * Return the minimum number of substrings in such a partition.
 * 
 * Note that each character should belong to exactly one substring in a
 * partition.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abacaba"
 * Output: 4
 * Explanation:
 * Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
 * It can be shown that 4 is the minimum number of substrings needed.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "ssssss"
 * Output: 6
 * Explanation:
 * The only valid partition is ("s","s","s","s","s","s").
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s consists of only English lowercase letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int partitionString(string s) {
        vector<int> lastSeen(26, -1);
        int start_Sub_string = 0;
        int count = 0;
        for(int i=0; i<s.length(); i++){
            if(lastSeen[s[i]-'a'] >= start_Sub_string){
                count++;
                start_Sub_string = i;
            }
            lastSeen[s[i]-'a'] = i;
        }
        return count+1;
    }
};
// @lc code=end

