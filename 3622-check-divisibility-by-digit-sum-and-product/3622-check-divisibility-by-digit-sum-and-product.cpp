class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        long long prod = 1;
        int temp = n;
        
        while (temp > 0) {
            int digit = temp % 10;
            sum += digit;
            prod *= digit;
            temp /= 10;
        }
        
        long long total = sum + prod;
        if (total == 0) return false;
        
        return n % total == 0;
    }
};



// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna