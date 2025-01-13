
#include "LeetCode.h"
using namespace std;

int lengthOfLongestSubstring(string s) {
    int maxLenSubStr = 0;  // To store the maximum length of the substring
    int n = s.size();
    
    // Array to store the last index of each character (assuming ASCII characters)
    int hash[256];  
    fill(hash, hash + 256, -1);  // Initialize all to -1 to indicate not seen
    
    int i = 0;  // Left pointer of the sliding window
    
    // Loop through the string with the right pointer
    for (int j = 0; j < n; j++) {
        // If the character has appeared before and is inside the window, adjust i
        if (hash[s[j]] != -1 && hash[s[j]] >= i) {
            i = hash[s[j]] + 1;  // Move the left pointer after the last occurrence of s[j]
        }
        
        hash[s[j]] = j;
   
        int len = j - i + 1;
        if (len > maxLenSubStr) {
            maxLenSubStr = len;  // Update maxLenSubStr if the current window is longer
        }
    }

    return maxLenSubStr;
}
