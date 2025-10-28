// Question Details:
// Problem Statement Description: 
// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
// A subarray is a contiguous part of an array.
// Constraints:
// 1 <= nums.length <= 10^5
// -10^4 <= nums[i] <= 10^4

// Input:
// An integer array nums, where 1 <= nums.length <= 10^5, and each element nums[i] is between -10^4 and 10^4.

// Output:
// The largest sum of a contiguous subarray.

#include <iostream>     
#include <vector>
#include <algorithm>
#include <climits> // for INT_MIN
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max2 = INT_MIN;  // This will store the maximum sum encountered
        int sum = 0;         // This stores the current subarray sum
        for(auto x: nums) {
            sum += x;  // Add the current element to the sum
            max2 = max(max2, sum);  // Update the maximum sum
            if(sum < 0)  // If the current sum is negative, reset it to 0
                sum = 0;
        }
        return max2;  // Return the maximum subarray sum
    }
};

int main() 
{ 
    Solution solution;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum: " << solution.maxSubArray(nums) << endl;
    return 0;
}  
