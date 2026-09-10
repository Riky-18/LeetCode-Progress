from functools import cmp_to_key

class Solution:
    def largestNumber(self, nums: list[int]) -> str:
        num_strs = [str(num) for num in nums]
        
        def compare(x: str, y: str) -> int:

            if x + y > y + x:
                return -1
            elif x + y < y + x:
                return 1
            else:
                return 0
        
        num_strs.sort(key=cmp_to_key(compare))
        
        largest_num = "".join(num_strs)
        
        return "0" if largest_num[0] == "0" else largest_num


# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna