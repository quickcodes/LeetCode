/*
14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings. 
If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.

*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        for(int i=0; i<strs[0].length(); i++) // iterate over first element (String) of array
            for(int j=1; j<strs.size(); j++)  // iterate over rest of the strings in array
                if(i == strs[j].length() || strs[j][i] != strs[0][i])  
                    // 1. if current index of first string (i) reaches length of new element
                    // 2. if new character of new string no longer match with 1st index string
                    return strs[0].substr(0, i);

        return strs[0];
    }
};
