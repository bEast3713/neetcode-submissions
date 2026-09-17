class Solution {
public:
    bool isAnagram(string s, string t) {
        multiset<char> hash(s.begin(),s.end());
        if (t.size() != s.size()) return false;
        for (int i = 0; i < t.size(); i++) {
            auto it = hash.find(t[i]);
            if (it != hash.end()) hash.erase(it); 
            else return false;
        }
        return true;
    }
};
