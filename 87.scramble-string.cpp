/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 *
 * https://leetcode.com/problems/scramble-string/description/
 *
 * algorithms
 * Hard (36.10%)
 * Likes:    2497
 * Dislikes: 1118
 * Total Accepted:    178.8K
 * Total Submissions: 479.3K
 * Testcase Example:  '"great"\n"rgeat"'
 *
 * We can scramble a string s to get a string t using the following
 * algorithm:
 *
 *
 * If the length of the string is 1, stop.
 * If the length of the string is > 1, do the following:
 *
 * Split the string into two non-empty substrings at a random index, i.e., if
 * the string is s, divide it to x and y where s = x + y.
 * Randomly decide to swap the two substrings or to keep them in the same
 * order. i.e., after this step, s may become s = x + y or s = y + x.
 * Apply step 1 recursively on each of the two substrings x and y.
 *
 *
 *
 *
 * Given two strings s1 and s2 of the same length, return true if s2 is a
 * scrambled string of s1, otherwise, return false.
 *
 *
 * Example 1:
 *
 *
 * Input: s1 = "great", s2 = "rgeat"
 * Output: true
 * Explanation: One possible scenario applied on s1 is:
 * "great" --> "gr/eat" // divide at random index.
 * "gr/eat" --> "gr/eat" // random decision is not to swap the two substrings
 * and keep them in order.
 * "gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both
 * substrings. divide at random index each of them.
 * "g/r / e/at" --> "r/g / e/at" // random decision was to swap the first
 * substring and to keep the second substring in the same order.
 * "r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively,
 * divide "at" to "a/t".
 * "r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both
 * substrings in the same order.
 * The algorithm stops now, and the result string is "rgeat" which is s2.
 * As one possible scenario led s1 to be scrambled to s2, we return true.
 *
 *
 * Example 2:
 *
 *
 * Input: s1 = "abcde", s2 = "caebd"
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: s1 = "a", s2 = "a"
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * s1.length == s2.length
 * 1 <= s1.length <= 30
 * s1 and s2 consist of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution
{
    bool DP_helper(unordered_map<string, bool> &isScramblePair, string s1, string s2)
    {
        int i, len = s1.size();
        bool res = false;
        if (0 == len)
            return true;
        else if (1 == len)
            return s1 == s2;
        else
        {
            if (isScramblePair.count(s1 + s2))
                return isScramblePair[s1 + s2]; // ! checked before, return intermediate result directly
            if (s1 == s2)
                res = true;
            else
            {
                for (i = 1; i < len && !res; ++i)
                {
                    // * check s1[0..i-1] with s2[0..i-1] and s1[i..len-1] and s2[i..len-1]
                    res = res || (DP_helper(isScramblePair, s1.substr(0, i), s2.substr(0, i)) && DP_helper(isScramblePair, s1.substr(i, len - i), s2.substr(i, len - i)));
                    // ^ f no match, then check s1[0..i-1] with s2[len-k.. len-1] and s1[i..len-1] and s2[0..len-i]
                    res = res || (DP_helper(isScramblePair, s1.substr(0, i), s2.substr(len - i, i)) && DP_helper(isScramblePair, s1.substr(i, len - i), s2.substr(0, len - i)));
                }
            }
            return isScramblePair[s1 + s2] = res; // save the intermediate results
        }
    }

public:
    bool isScramble(string s1, string s2)
    {
        unordered_map<string, bool> isScramblePair;
        return DP_helper(isScramblePair, s1, s2);
    }
};
// @lc code=end
