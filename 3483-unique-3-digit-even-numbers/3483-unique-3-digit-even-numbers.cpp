#include <vector>

class Solution {
public:
    int totalNumbers(std::vector<int>& digits) {
        std::vector<int> available(10, 0);
        for (int d : digits) {
            available[d]++;
        }
        
        int unique_count = 0;
        
        for (int i = 100; i <= 998; i += 2) {
            int hundreds = i / 100;
            int tens = (i / 10) % 10;
            int units = i % 10;
            
            std::vector<int> needed(10, 0);
            needed[hundreds]++;
            needed[tens]++;
            needed[units]++;
            
            if (available[hundreds] >= needed[hundreds] &&
                available[tens] >= needed[tens] &&
                available[units] >= needed[units]) {
                unique_count++;
            }
        }
        
        return unique_count;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna