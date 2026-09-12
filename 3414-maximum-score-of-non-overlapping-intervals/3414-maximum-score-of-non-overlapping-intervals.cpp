#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    struct Node { int l, r, w, id; };
    struct State {
        long long w = 0;
        vector<int> ids;
    };
    
    int n;
    vector<Node> arr;
    vector<int> starts;
    vector<vector<State>> memo;

    State solve(int i, int k) {
        if (i >= n || k == 0) return {0, {}};
        if (memo[i][k].w != -1) return memo[i][k];

        State skip = solve(i + 1, k);

        int nxt = upper_bound(starts.begin(), starts.end(), arr[i].r) - starts.begin();
        State take = solve(nxt, k - 1);
        take.w += arr[i].w;
        take.ids.push_back(arr[i].id);

        vector<int> s_take = take.ids; sort(s_take.begin(), s_take.end());
        vector<int> s_skip = skip.ids; sort(s_skip.begin(), s_skip.end());

        if (take.w > skip.w || (take.w == skip.w && s_take < s_skip)) {
            return memo[i][k] = take;
        }
        return memo[i][k] = skip;
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();
        arr.resize(n);
        starts.resize(n);
        memo.assign(n, vector<State>(5, {-1, {}}));

        for (int i = 0; i < n; ++i) {
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        
        sort(arr.begin(), arr.end(), [](const Node& a, const Node& b) {
            return a.l != b.l ? a.l < b.l : a.r < b.r;
        });

        for (int i = 0; i < n; ++i) starts[i] = arr[i].l;

        State ans = solve(0, 4);
        sort(ans.ids.begin(), ans.ids.end());
        return ans.ids;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna