#include <vector>
#include <algorithm>

class Solution {
public:
    int maxDistance(std::vector<int>& nums1, std::vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int max_dist = 0;
        int m = nums1.size();
        int n = nums2.size();

        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                max_dist = std::max(max_dist, j - i);
                j++;
            } else {
                i++;
            }
        }

        return max_dist;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna