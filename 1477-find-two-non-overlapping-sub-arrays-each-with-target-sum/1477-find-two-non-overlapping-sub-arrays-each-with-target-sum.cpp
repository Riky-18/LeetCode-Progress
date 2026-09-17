#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minSumOfLengths(std::vector<int>& arr, int target) {
        int n = arr.size();
        int ans = INT_MAX;
        int sum = 0;
        int l = 0;
        
        std::vector<int> best(n, INT_MAX);
        
        for (int r = 0; r < n; ++r) {
            sum += arr[r];
            
            while (sum > target) {
                sum -= arr[l++];
            }
            
            if (sum == target) {
                if (l > 0 && best[l - 1] != INT_MAX) {
                    ans = std::min(ans, best[l - 1] + (r - l + 1));
                }
                best[r] = std::min(best[r], r - l + 1);
            }
            
            if (r > 0) {
                best[r] = std::min(best[r], best[r - 1]);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna