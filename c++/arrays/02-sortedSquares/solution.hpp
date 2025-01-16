#include <cmath>
#include <vector>
namespace solution {

class Solution {
public:
  std::vector<int> sortedSquares(std::vector<int> &nums) {
    int n = nums.size();
    int i = 0, j = n - 1;
    for (int p = n - 1; p >= 0 && j >= i; p--) {
      if (abs(nums[i]) > abs(nums[j])) {
        nums[p] = nums[i] * nums[i];
        i++;
      } else {
        nums[p] = nums[j] * nums[j];
        j--;
      }
    }
    return nums;
  }
};

} // namespace solution
