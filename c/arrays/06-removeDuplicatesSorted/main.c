#include <stdio.h>

int removeDuplicates(int *nums, int numsSize) {
  int j = 0;
  int i = 1;
  for (; i < numsSize; i++) {
    if (nums[i] != nums[j]) {
      j++;
      nums[j] = nums[i];
    }
  }
  return j + 1;
}

int test_removeDuplicates(int *array, int arraySize, int *expectedArray,
                          int expectedArraySize) {
  int newSize = removeDuplicates(array, arraySize);
  if (newSize != expectedArraySize) {
    printf("Expected size %d, got %d\n", expectedArraySize, newSize);
    for (int i = 0; i < newSize; i++) {
      printf("%d ", array[i]);
    }
    printf("\n");
    return 1;
  }

  for (int i = 0; i < newSize; i++) {
    if (array[i] != expectedArray[i]) {
      printf("Expected %d, got %d\n", expectedArray[i], array[i]);
      return 1;
    }
  }
  return 0;
}

int main(int argc, char *argv[]) {
  int nums[] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9};
  int expected[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int numsSize = sizeof(nums) / sizeof(nums[0]);
  int expectedSize = sizeof(expected) / sizeof(expected[0]);

  printf("Test case 1: ");

  if (test_removeDuplicates(nums, numsSize, expected, expectedSize) == 1) {
    printf("FAIL!\n");
    return 1;
  }
  printf("OK!\n");

  printf("Test case 2: ");

  int testcase2[] = {1, 1, 2};
  int testcase2Size = sizeof(testcase2) / sizeof(testcase2[0]);
  int testcase2Expected[] = {1, 2};
  int testcase2ExpectedSize =
      sizeof(testcase2Expected) / sizeof(testcase2Expected[0]);
  if (test_removeDuplicates(testcase2, testcase2Size, testcase2Expected,
                            testcase2ExpectedSize) == 1) {
    printf("FAIL!\n");
    return 1;
  }
  printf("OK!\n");

  return 0;
}
