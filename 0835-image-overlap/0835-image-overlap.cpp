#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size(), count[64][64] = {0}, ans = 0;
        vector<pair<int, int>> v1, v2;
        
        for (int r = 0; r < n; ++r)
            for (int c = 0; c < n; ++c) {
                if (img1[r][c]) v1.push_back({r, c});
                if (img2[r][c]) v2.push_back({r, c});
            }

        for (auto& [r1, c1] : v1)
            for (auto& [r2, c2] : v2)
                ans = max(ans, ++count[r1 - r2 + 30][c1 - c2 + 30]);

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna