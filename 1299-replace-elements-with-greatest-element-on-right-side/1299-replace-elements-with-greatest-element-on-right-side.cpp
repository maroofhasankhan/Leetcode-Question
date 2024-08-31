class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int>n(arr.size());

        if(arr.size()==1){
            n[0]=-1;
            return n;
        }
        n[arr.size()-1]=-1;

        for(int i = arr.size()-2;i>=0;i--){
            n[i]=max(arr[i+1],n[i+1]);


        }

     

        return n;
    }
};