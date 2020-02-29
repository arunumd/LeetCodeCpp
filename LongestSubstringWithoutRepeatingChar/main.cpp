/*
 * Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

#include <iostream>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> elements;
        int max = 0, diff = 0, current = 0;
        if (s.size() == 1)
            return 1;
        for (int i = 0; i < s.size(); i++) {
            if (elements.find(s[i]) == elements.end()) {
                elements.insert(std::make_pair(s[i], i));
                current > max ? max = current : max;
            } else {
                diff = i - elements[s[i]];
                if (diff > max) {
                    max = diff;
                }
                current = current - (i - 1);
                elements[s[i]] = i;
            }
            current++;
        }
        if (current > max)
            max = current;
        return max;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
