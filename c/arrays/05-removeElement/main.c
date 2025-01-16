#include <stdio.h>

#include <string.h>

int removeElement(int *nums, int numsSize, int val) {
  int i = 0;
  int j = 0;
  for (i = 0; i < numsSize; i++) {
    if (nums[i] != val) {
      nums[j++] = nums[i];
    }
  }
  return j;
}

int main(int argc, char *argv[]) {
  int nums[] = {3, 2, 2, 3};
  int val = 3;
  int expectedNums[] = {2, 2}; // The expected answer with correct length.
                               // It is sorted with no values equaling val.

  int k = removeElement(nums, sizeof(nums) / sizeof(int), val);

  if (k == 2 && memcmp(nums, expectedNums, sizeof(int) * 2) == 0) {
    printf("Test passed.\n");
    return 0;
  } else {
    printf("Test failed.\n");
    return 1;
  }
  return 0;
}
