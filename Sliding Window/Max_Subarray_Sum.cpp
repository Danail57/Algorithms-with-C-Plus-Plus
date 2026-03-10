#include <iostream>
#include <vector>
using namespace std;

int max_subarray_sum(vector <int>& nums, int k)
{
    int max_sum = INT_MIN;
    int window_sum = 0;
    for (int i = 0; i < k; i++)
    {
        window_sum += nums[i];
    }
    for (int i = k; i < nums.size(); i++) {
        window_sum += nums[i] - nums[i - k];
        max_sum = max(max_sum, window_sum);
    }
    return max_sum;
}

int main() {
    vector <int> nums = {2, 6, 5, 1, 3, 2};
    int window_size = 3;
    int result = max_subarray_sum(nums, window_size);
    cout << "Max subarray sum = " << result << endl;
    return 0;
}
