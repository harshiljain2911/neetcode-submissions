class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (int i = 0; i < s1.length(); i++) {
            freq1[s1[i] - 'a']++;
        }

        for (int j = 0; j < s1.length(); j++) {
            freq2[s2[j] - 'a']++;
        }

        int l = 0;

        for (int r = s1.length(); r < s2.length(); r++) {
            if (freq2 == freq1)
                return true;
            else {
                freq2[s2[l] - 'a']--;
                l++;
                freq2[s2[r] - 'a']++;
            }
        }
        if (freq1 == freq2) return true;

        return false;
    }
};
