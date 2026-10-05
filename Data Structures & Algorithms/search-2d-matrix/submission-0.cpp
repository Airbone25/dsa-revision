class Solution {
    bool bS(int l,int r, int target,vector<int>& nums){
        while(l<=r){
            int m = l+(r-l)/2;
            if(target == nums[m]){
                return true;
            }else if(target > nums[m]){
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        for(auto& arr:matrix){
            if(arr[0] <= target && arr[n-1] >= target){
                return bS(0,n-1,target,arr);
            }
        }
        return false;
    }
};
