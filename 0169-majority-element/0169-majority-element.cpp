class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // unordered_map<int,int>mp;
        // for(int i=0;i<nums.size();i++){
        //     mp[nums[i]]++;
        // }
        // for(auto itr=mp.begin();itr!=mp.end();++itr){
        //     if(itr->second>nums.size()/2){
        //         return itr->first;
        //     }
        // }
        // return 0;

            int count = 0;
        int res = 0;

        for (const int& num: nums) {
            if (count == 0) {
                res = num;
            } 
            count += (num == res) ? 1 : -1;
        }

        return res;
    
    }
};