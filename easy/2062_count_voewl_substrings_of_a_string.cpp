/*
2062. Count Vowel Substrings of a String
A substring is a contiguous (non-empty) sequence of characters within a string.

A vowel substring is a substring that only consists of vowels ('a', 'e', 'i', 'o', and 'u') and has all five vowels present in it.

Given a string word, return the number of vowel substrings in word.

 

Example 1:

Input: word = "aeiouu"
Output: 2
Explanation: The vowel substrings of word are as follows (underlined):
- "aeiouu"
- "aeiouu"
Example 2:

Input: word = "unicornarihan"
Output: 0
Explanation: Not all 5 vowels are present, so there are no vowel substrings.
Example 3:

Input: word = "cuaieuouac"
Output: 7
Explanation: The vowel substrings of word are as follows (underlined):
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
 

Constraints:

1 <= word.length <= 100
word consists of lowercase English letters only.

*/

class Solution {

private:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
     }

private:
    // count all the substring with 1 vowel, 2 vowel, 3 vowel,... k vowels
    int countAtmostKVowel(string s, int k){
        int i = 0;
        int n = s.size();
        int cnt = 0;
        unordered_map<char, int> vowelMap;
        
        for(int j=0; j<n; j++){
            if(!isVowel(s[j])){
                // clear the map as the new substring will start
                vowelMap.clear();
                i = j + 1;
                continue;
            }
            
            vowelMap[s[j]]++;
            while(vowelMap.size() > k){
                vowelMap[s[i]]--;
                if(vowelMap[s[i]] == 0){
                    vowelMap.erase(s[i]);
                }
                i++;
            }
            
            cnt += (j - i + 1);
        }
        return cnt;
    }
    
public:
    int countVowelSubstrings(string word) {
        // count atmost k elements and atmost k-1 element then substract it 
        return countAtmostKVowel(word, 5) - countAtmostKVowel(word, 4); 
        
        
    }
    
    // Brute force solution
    // int countVowelSubstrings(string word) {
    //     int cnt = 0;
    //     int n = word.size();
    //     for(int i=0; i<n; i++){
    //         set<char> st;
    //         for(int j=i; j<n; j++){
    //             if(!isVowel(word[j])) break;
    //             st.insert(word[j]);
    //             if(st.size() == 5) cnt++;
    //         }
    //     }
    //     return cnt;
    // }
};
