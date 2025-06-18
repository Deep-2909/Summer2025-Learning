class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            std::vector<int> v;
            int n = nums.size();
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i == j)
                        continue;
                    if(nums[i] + nums[j] == target)
                    {
                        v.push_back(i);
                        v.push_back(j);
                        break;
                    }
                }
                if(v.size() == 2)
                    break;
            }
            return v;
        }
    };