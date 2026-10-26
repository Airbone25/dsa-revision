class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }

        int res1 = solve(vector<int>(nums.begin(),nums.end()-1));
        int res2 = solve(vector<int>(nums.begin()+1,nums.end()));

        return max(res1,res2);

    }

    int solve(vector<int> arr){
        if(arr.size() == 0){
            return 0;
        }

        if(arr.size() == 1){
            return arr[0];
        }

        int n = arr.size();
        vector<int> dp(n);

        dp[0] = arr[0];
        dp[1] = max(arr[0],arr[1]);

        for(int i=2;i<dp.size();i++){
            dp[i] = max(dp[i-1],dp[i-2]+arr[i]);
        }

        return dp[n-1];
    }
};
