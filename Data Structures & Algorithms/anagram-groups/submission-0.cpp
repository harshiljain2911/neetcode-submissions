class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> mp;

        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
            mp[t[i]]--;
        }

        for (int i = 0; i < mp.size(); i++) {
            if (mp[s[i]] != 0) return false;
        }

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_set<string> st;

        for (int i = 0; i < strs.size(); i++) {
            if (st.contains(strs[i]))
                continue;

            else {
                st.insert(strs[i]);
                vector<string> temp;
                temp.push_back(strs[i]);
                for (int j = i + 1; j < strs.size(); j++) {
                    if (isAnagram(strs[i], strs[j])) {
                        temp.push_back(strs[j]);
                        st.insert(strs[j]);
                    }
                }
                ans.push_back(temp);
            }
        }

        return ans;
    }
};
