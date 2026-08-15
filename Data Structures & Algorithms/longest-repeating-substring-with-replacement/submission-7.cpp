class Solution {
   public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int ans = 0;

        vector<int> frq(26, 0);

        for (int r = 0; r < s.length(); r++) {
            frq[s[r] - 'A']++;

            int maxfrq = *max_element(frq.begin(), frq.end());

            while (r - l + 1 - maxfrq > k) {
                frq[s[l] - 'A']--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
