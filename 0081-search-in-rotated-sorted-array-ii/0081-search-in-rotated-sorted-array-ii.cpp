class Solution {
public:
        int bsearch(vector<int> nums,int low,int high,int target){
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
            return -1;
    }


    bool search(vector<int>& nums, int target) {
        int low =0,high=nums.size()-1;
        while(low<high && nums[low]==nums[low+1])low++;
        while(low<high && nums[high]==nums[high-1])high--;

        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[high]<nums[mid]){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        int pivot=low;
        int i = bsearch(nums,0,pivot-1,target);
        if(i!=-1)return true;
        else{
            return (bsearch(nums,pivot,nums.size()-1,target)!=-1)?true:false;
        }
        return false;
    }
};
