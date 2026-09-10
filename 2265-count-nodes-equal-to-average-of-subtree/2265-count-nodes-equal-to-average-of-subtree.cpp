class Solution {
private:
    int matchingNodesCount = 0;
    std::pair<int, int> calculateSubtree(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }
        auto leftSubtree = calculateSubtree(root->left);
        auto rightSubtree = calculateSubtree(root->right);

        int currentSum = root->val + leftSubtree.first + rightSubtree.first;
        int currentCount = 1 + leftSubtree.second + rightSubtree.second;

        if (root->val == (currentSum / currentCount)) {
            matchingNodesCount++;
        }

        return {currentSum, currentCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        matchingNodesCount = 0;
        calculateSubtree(root);
        return matchingNodesCount;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna