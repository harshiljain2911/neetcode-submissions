class Solution {
public:
    string minWindow(string s, string t) {

        if (t.empty() || s.empty()) {
            return "";
        }

        vector<int> need(128, 0);
        vector<int> window(128, 0);

        // Frequency required from t
        for (char c : t) {
            need[c]++;
        }

        int required = t.length();
        int have = 0;

        int l = 0;

        int minLen = INT_MAX;
        int start = 0;

        for (int r = 0; r < s.length(); r++) {

            // Add s[r] to the window
            char c = s[r];
            window[c]++;

            // This occurrence satisfies a requirement
            if (window[c] <= need[c]) {
                have++;
            }

            // Window contains everything required
            while (have == required) {

                // Current window is a candidate answer
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                // Remove s[l]
                char leftChar = s[l];
                window[leftChar]--;

                // Did removing it break a requirement?
                if (window[leftChar] < need[leftChar]) {
                    have--;
                }

                l++;
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};