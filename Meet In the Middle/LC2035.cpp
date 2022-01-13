 class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2, ans = 1e9;
        vector<int> l(nums.begin(), nums.begin() + n), r(nums.begin() + n, nums.end());
        vector<int> subset[n + 1];
        
        for(int i = 0; i < (1LL << n); i++){
            int sum = 0, id = __builtin_popcount(i);
            for(int j = 0; j < n; j++){
                if(i & (1LL << j)) sum += l[j];
                else sum -= l[j];
            }
            subset[id].push_back(sum);
        }
        
        for(auto& s : subset) sort(begin(s), end(s));
        
        for(int i = 0; i < (1LL << n); i++){
            int sum = 0, id = n - __builtin_popcount(i);
            for(int j = 0; j < n; j++){
                if(i & (1LL << j)) sum += r[j];
                else sum -= r[j];
            }
            auto it = lower_bound(begin(subset[id]), end(subset[id]), -sum);
            if(it != end(subset[id])) ans = min(ans, abs(sum + *it));
            if(it != begin(subset[id])) ans = min(ans, abs(sum + *prev(it)));
        }
        return ans;
    }
};
