/*
20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

class Solution {
public:
    unordered_map<char, int> symbols = {{'(',-1}, {'{',-2}, {'[',-3}, {')',1}, {'}',2}, {']',3}};

    bool isValid(string &s){
        stack<char> st;
        for(char bracket: s){
            if(symbols[bracket] < 0){
                st.push(bracket);
            }else{
                if(st.empty()) return false;
                char top = st.top();
                st.pop();
                if(symbols[bracket] + symbols[top] != 0) return false;
            }
        }
        if (st.empty()) return true;
        return false;
    }
};
