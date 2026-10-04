class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        std::unordered_map<string, vector<string>> map;
        for (const auto &s : strs){
            std::string key = s;
            std::sort(key.begin(), key.end());
            map[key].push_back(s);
        }
        for (auto& pair : map){
            ret.push_back(std::move(pair.second));
        }

        return ret;
    }
};
