class Solution:
    def reverse(self, x):
        # Define the maximum and minimum values for a 32-bit signed integer
        INT_MAX = 2 ** 31 - 1
        INT_MIN = -2 ** 31
        
        # Initialize the result
        result = 0
        
        # Handle the sign of the number
        sign = 1 if x >= 0 else -1
        x = abs(x)
        
        # Reverse the digits of x
        while x != 0:
            digit = x % 10
            result = result * 10 + digit
            x //= 10
        
        # Apply sign and check for overflow
        result *= sign
        if result > INT_MAX or result < INT_MIN:
            return 0
        return result

# # Example usage:
# solution = Solution()
# print(solution.reverse(123))  # Output: 321
# print(solution.reverse(-123))  # Output: -321
# print(solution.reverse(120))  # Output: 21
