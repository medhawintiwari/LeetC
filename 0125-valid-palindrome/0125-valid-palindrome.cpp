
class Solution {
public:
    bool isPalindrome(string s) {
        string filtered = "";
        
        // Step 1: Filter and lowercase
        for (char c : s) {
            if (isalnum(c)) {
                filtered += tolower(c);
            }
        }
        
        // Step 2: Compare with its reversed version
        string reversed_str = filtered;
        reverse(reversed_str.begin(), reversed_str.end());
        
        return filtered == reversed_str;
    }
};