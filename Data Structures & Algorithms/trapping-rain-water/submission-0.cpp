class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;

        int l = 0;
        int r = height.size()-1;
        int l_max = height[l];
        int r_max = height[r];

        while(l<r){
            if(l_max < r_max){
                l++;
                l_max = max(l_max,height[l]);
                sum += l_max - height[l];
            }else{
                r--;
                r_max = max(r_max,height[r]);
                sum += r_max - height[r];
            }
        }

        return sum;
    }
};
