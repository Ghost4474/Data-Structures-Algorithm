// Optimized approach to find if a subarray
// with a given sum exists (for non-negative arrays).
// Time Complexity: O(n)
#include <iostream>
#include <vector>
using namespace std;

bool subcheck(vector<int> &v, int sum)
{
    int n = v.size();
    int crr = 0;
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        crr += v[i];

        while (crr > sum && r <= i)
        {
            crr -= v[r];
            r++;
        }

        if (crr == sum)
            return true;
    }
    return false;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 6, 7, 9};
    int sum = 5;

    if (subcheck(v, sum))
        cout << "Subarray with sum " << sum << " exists." << endl;
    else
        cout << "No subarray with sum " << sum << " found." << endl;

    return 0;
}
