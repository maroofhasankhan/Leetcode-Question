class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        unordered_map<char,int>mp;

        for(auto i : s){
            mp[i]++;
        }

        for(auto i :t ){
            if(mp[i]){
                mp[i]--;
            }
            else{
                return false;
            }
        }
        for(auto i: mp){
            if(i.second>0)return false;
            
        }
        return true;
    }
};