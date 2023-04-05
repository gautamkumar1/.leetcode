/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (50.09%)
 * Likes:    3263
 * Dislikes: 2385
 * Total Accepted:    491.2K
 * Total Submissions: 979.8K
 * Testcase Example:  '"hello"'
 *
 * Given a string s, reverse only all the vowels in the string and return it.
 * 
 * The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both
 * lower and upper cases, more than once.
 * 
 * 
 * Example 1:
 * Input: s = "hello"
 * Output: "holle"
 * Example 2:
 * Input: s = "leetcode"
 * Output: "leotcede"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 3 * 10^5
 * s consist of printable ASCII characters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "";
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
                vowels+=ch;
            }
        }
        reverse(vowels.begin(),vowels.end());
        int j=0;
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
                s[i] = vowels[j++];
            }
        }
        return s;
    }
};  
// @lc code=end

