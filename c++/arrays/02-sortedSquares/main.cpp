#include <iostream>

#include "solution.hpp"

bool test_solution() {

  std::vector<int> nums = {-4, -1, 0, 3, 10};
  std::vector<int> expected = {0, 1, 9, 16, 100};
  solution::Solution soln;
  std::vector<int> result = soln.sortedSquares(nums);
  if (result == expected) {
    return true;
  }
  return false;
}

void test_by_element() {
  std::vector<int> nums = {-4, -1, 0, 3, 10};
  std::vector<int> expected = {0, 1, 9, 16, 100};
  solution::Solution soln;
  std::cout << "Testing solution by element..." << std::endl;
  std::vector<int> result = soln.sortedSquares(nums);
  for (int i = 0; i < nums.size(); i++) {
    if (result[i] == expected[i]) {
      std::cout << "Test passed!" << std::endl;
    } else {
      std::cout << "Test failed! expected: " << expected[i]
                << " got: " << nums[i] << std::endl;
    }
  }
}

int main(int argc, char *argv[]) {
  std::cout << "Testing solution..." << std::endl;
  /* test_by_element(); */
  if (test_solution()) {
    std::cout << "Test passed!" << std::endl;
  } else {
    std::cout << "Test failed!" << std::endl;
  }
  return 0;
}
