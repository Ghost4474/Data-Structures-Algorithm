#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> result;
        for (int i = 0; i < nums.size(); i++) {
            result.insert(nums[i]);
        }
        if (result.size() < nums.size()) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3, 1};  // Example input

    if (obj.containsDuplicate(nums)) {
        cout << "Contains duplicate elements." << endl;
    } else {
        cout << "No duplicates found." << endl;
    }

    return 0;
}
