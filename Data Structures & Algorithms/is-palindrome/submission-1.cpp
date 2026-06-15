class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length();

        while (i < j) {
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;

            if (tolower(s[j]) != tolower(s[i])) return false;

            i++; j--;
        }

        return true;
    }
};
