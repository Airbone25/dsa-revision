class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size()-1;
        int i = nums.size()-2;
        while(i>=0){
            if(i+nums[i]>=goal){
                goal = i;
            }
            i--;
        }

        return goal == 0;
    }
};
