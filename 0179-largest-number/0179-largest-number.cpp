#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string largestNumber(std::vector<int>& nums) {
        std::vector<std::string> num_strs;
        num_strs.reserve(nums.size());
        for (int num : nums) {
            num_strs.push_back(std::to_string(num));
        }
        
        std::sort(num_strs.begin(), num_strs.end(), [](const std::string& a, const std::string& b) {
            return a + b > b + a;
        });
        
        if (num_strs[0] == "0") {
            return "0";
        }
        
        std::string largest_num = "";
        for (const std::string& str : num_strs) {
            largest_num += str;
        }
        
        return largest_num;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna