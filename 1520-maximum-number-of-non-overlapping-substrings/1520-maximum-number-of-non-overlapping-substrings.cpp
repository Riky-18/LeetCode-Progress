#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> leftmost(26, n);
        vector<int> rightmost(26, -1);
        
        for (int i = 0; i < n; ++i) {
            leftmost[s[i] - 'a'] = min(leftmost[s[i] - 'a'], i);
            rightmost[s[i] - 'a'] = i;
        }
        
        vector<string> ans;
        int last_right = -1;
        
        for (int i = 0; i < n; ++i) {
            if (i == leftmost[s[i] - 'a']) {
                int new_right = checkValidSubstring(s, i, leftmost, rightmost);
                
                if (new_right != -1) {
                    if (i > last_right) {
                        ans.push_back("");
                    }
                    ans.back() = s.substr(i, new_right - i + 1);
                    last_right = new_right;
                }
            }
        }
        return ans;
    }

private:
    int checkValidSubstring(const string& s, int i, const vector<int>& leftmost, const vector<int>& rightmost) {
        int right = rightmost[s[i] - 'a'];
        for (int j = i; j <= right; ++j) {
            if (leftmost[s[j] - 'a'] < i) {
                return -1;
            }
            right = max(right, rightmost[s[j] - 'a']);
        }
        return right;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna