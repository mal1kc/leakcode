#include <stdio.h>
#include <stdlib.h>
int *sortedSquares(int *nums, int numsSize, int *returnSize) {
  int i = 0, j = numsSize - 1;
  *returnSize = numsSize; // Set the value of returnSize

  int *result = (int *)malloc(numsSize * sizeof(int));

  if (result == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    *returnSize = 0; // Set returnSize to 0 to indicate failure
    return NULL;
  }

  for (int p = numsSize - 1; p >= 0; p--) {
    int squareI = nums[i] * nums[i];
    int squareJ = nums[j] * nums[j];

    if (abs(squareI) > abs(squareJ)) {
      result[p] = squareI;
      i++;
    } else {
      result[p] = squareJ;
      j--;
    }
  }

  return result;
}

int main(int argc, char *argv[]) {
  int nums[] = {-4, -1, 0, 3, 10};
  int expected[] = {0, 1, 9, 16, 100};
  int numsSize = sizeof(nums) / sizeof(nums[0]);
  int returnSize;

  int *result = sortedSquares(nums, numsSize, &returnSize);

  if (result != NULL) {
    // Print the sorted squared values
    for (int i = 0; i < returnSize; i++) {
      if (result[i] != expected[i]) {
        printf("Test failed\n");
        free(result);
        return 1;
      } else {
        printf("%d ", result[i]);
      }
    }
    // Free the allocated memory
    free(result);
  } else {
    printf("Test failed\n");
    printf("result is NULL\n");
    return 1;
  }
  return 0;
}
