/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 *
 * https://leetcode.com/problems/detect-capital/description/
 *
 * algorithms
 * Easy (57.00%)
 * Likes:    3149
 * Dislikes: 443
 * Total Accepted:    385.7K
 * Total Submissions: 676.7K
 * Testcase Example:  '"USA"'
 *
 * We define the usage of capitals in a word to be right when one of the
 * following cases holds:
 *
 *
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital, like "Google".
 *
 *
 * Given a string word, return true if the usage of capitals in it is right.
 *
 *
 * Example 1:
 * Input: word = "USA"
 * Output: true
 * Example 2:
 * Input: word = "FlaG"
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 1 <= word.length <= 100
 * word consists of lowercase and uppercase English letters.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int cnt = 0; // counter to store the number of capital letters in the word
        for (int i = 0; i < word.size(); i++)
        {
            if (isupper(word[i]))
                cnt++; // increase counter if letter at index i is uppercase
        }
        if (cnt == word.size())
        { // if all letters are uppercase, return true
            return true;
        }
        else if (cnt == 0)
        { // if no letters are uppercase, return true
            return true;
        }
        else if (cnt == 1 && isupper(word[0]))
        { // if only the first letter is uppercase, return true
            return true;
        }
        return false; // otherwise, return false
    }
};
// @lc code=end
