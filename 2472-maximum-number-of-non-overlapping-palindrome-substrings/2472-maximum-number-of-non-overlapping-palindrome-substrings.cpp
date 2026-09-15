#include <string>
#include <algorithm>

class Solution {
public:
    int maxPalindromes(std::string s, int k) {
        int n = s.length();
        int count = 0;
        int last_end = -1; 

        for (int i = 0; i < n; ++i) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 >= k) {
                    if (l > last_end) {
                        count++;
                        last_end = r;
                    }
                    break;
                }
                l--;
                r++;
            }

            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 >= k) {
                    if (l > last_end) {
                        count++;
                        last_end = r;
                    }
                    break;
                }
                l--;
                r++;
            }
        }

        return count;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna