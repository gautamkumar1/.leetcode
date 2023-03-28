/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 */

// @lc code=start
class Solution {
public:
    // This function takes an input string 's' and returns the number of segments in it.
    int countSegments(string s) {
        if (s.size() == 0) { // If the string is empty, return 0.
            return 0;
        }
        
        int cnt = 0; // Initialize a counter variable to count the number of segments.
        
        for (int i = 0; i < s.size(); i++) { // Loop through each character of the string 's'.
            char ch = s[i]; // Store the current character in 'ch'.
            
            // Check if this character is not a space AND the next character is either a space or the end of the string.
            if (s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0')) {
                cnt++; // If the above condition is true, increment the counter variable 'cnt'.
            }
        }
        
        return cnt; // Return the final count of segments in the string.
    }
    
};
// @lc code=end

