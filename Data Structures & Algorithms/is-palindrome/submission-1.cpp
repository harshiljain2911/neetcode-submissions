class Solution {
public:
    bool isPalindrome(string s) {
        int first = 0;
        int last = s.length() - 1;

        while (first <= last) {

            while (first < last && !isalnum(s[first]))
                first++;

            while (first < last && !isalnum(s[last]))
                last--;

            if (tolower(s[first]) != tolower(s[last]))
                return false;

            first++;
            last--;
        }

        return true;
    }
};