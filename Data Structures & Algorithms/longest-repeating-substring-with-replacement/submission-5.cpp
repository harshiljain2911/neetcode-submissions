class Solution {
   public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int size = 0;
        int maxfreq = 0;

        unordered_map<char, int> mp;

        for (int r = 0; r < s.size(); r++) {
            mp[s[r]]++;
            maxfreq = max(maxfreq,mp[s[r]]);

            while ((r-l+1)-maxfreq>k) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }
                l++;
            }

            size = max(size, r - l + 1);
        }

        return size;
    }
};
